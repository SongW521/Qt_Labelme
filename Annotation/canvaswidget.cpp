#include "canvaswidget.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QGraphicsScene>
CanVasWidget::CanVasWidget(QWidget *parent)
    : QGraphicsView(parent),
    scene(new QGraphicsScene(this)),
    currentEllipse(nullptr), itemIndex(0)
{
    isDraw = false;
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);  // 设置缩放时的锚点在鼠标位置
}

CanVasWidget::~CanVasWidget()
{
    delete scene;
}

void CanVasWidget::updateBkgroudImage(const QPixmap &pixmap)
{
    itemIndex = 0;
    ellipseItem.clear();
    scene->clear();
    QGraphicsPixmapItem *backgroundItem = scene->addPixmap(pixmap);
    backgroundItem->setZValue(-1);

    // 获取场景的边界矩形
    QRectF sceneRect = scene->itemsBoundingRect();
    // 设置场景的边界矩形
    scene->setSceneRect(sceneRect);
    // 将视图中心移动到场景中心
    centerOn(sceneRect.center());
}

void CanVasWidget::setDrawMode(bool draw)
{
    isDraw = draw;
    if(isDraw)   setCursor(Qt::CrossCursor);
    else         setCursor(Qt::ArrowCursor);
}

QVector<flagBuffer> CanVasWidget::getItemsFlagBuffer()
{
    QVector<flagBuffer> buffers;
    int i = 0;
    for (auto item : ellipseItem) {
        flagBuffer buffer;
        buffer.labelname = QString("ellipse_%1").arg(i++); // 设置标签名称
        buffer.center = item->sceneBoundingRect().center();  // 获取场景中的中心点
        buffer.w = item->rect().width();
        buffer.h = item->rect().height();
        buffer.angle = item->rotation() * (-1);//转换为逆时针为正，顺时针为负数
        buffers.append(buffer);
    }
    return buffers;
}

void CanVasWidget::mousePressEvent(QMouseEvent *event)
{
    if (isDraw && event->button() == Qt::LeftButton) {
        startPos = mapToScene(event->pos());
        // 初始化一个 0x0 的矩形，并将其中心放在 startPos
        currentEllipse = new EllipseShapeItem(startPos.x(), startPos.y(), 0, 0);
        scene->addItem(currentEllipse);
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void CanVasWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDraw && currentEllipse) {
        QPointF currentPos = mapToScene(event->pos());
        // 计算宽度和高度，确保以 startPos 为中心
        qreal width = std::abs(currentPos.x() - startPos.x()) * 2;
        qreal height = std::abs(currentPos.y() - startPos.y()) * 2;
        // 确保矩形的中心位于 startPos
        QRectF newRect(startPos.x() - width / 2, startPos.y() - height / 2, width, height);
        currentEllipse->setRect(newRect);
    } else {
        QGraphicsView::mouseMoveEvent(event);
    }
}
void CanVasWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (isDraw && event->button() == Qt::LeftButton && currentEllipse) {
        setDrawMode(false);
        ellipseItem.append(currentEllipse);
        connect(currentEllipse, &EllipseShapeItem::shapeModified, this, &CanVasWidget::handleShapeModified);
        emit drawFinish();
        currentEllipse = nullptr;
    } else {
        QGraphicsView::mouseReleaseEvent(event);
    }
}
void CanVasWidget::wheelEvent(QWheelEvent *event)
{
    // 缩放比例
    const double scaleFactor = 1.15;

    if (event->angleDelta().y() > 0) {
        // 放大
        scale(scaleFactor, scaleFactor);
    } else {
        // 缩小
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

    QGraphicsView::wheelEvent(event);
}
void CanVasWidget::handleShapeModified()
{
    // 处理椭圆修改事件
    emit drawFinish();
}
