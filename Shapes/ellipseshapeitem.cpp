#include "ellipseshapeitem.h"
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPointF>
#include <QCursor>
#include <QDebug>

EllipseShapeItem::EllipseShapeItem(qreal x, qreal y, qreal width, qreal height)
    : QGraphicsEllipseItem(x, y, width, height), isResizing(false),
    centerPoint(nullptr), rotationPoint(nullptr)
{
    setPen(QPen(QColor(0, 155, 0), 2));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setTransformOriginPoint(rect().center());
    setAcceptHoverEvents(true);

    //显示圆心点
    if (centerPoint) centerPoint->setVisible(true);
    // 初始化顶点但不显示
    showPoints();
    setPointsVisibility(false);
}
void EllipseShapeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        resizeStartPos = event->scenePos();
        originalRect = rect();
        // Check if a corner point is clicked
        QPointF scenePos = event->scenePos();
        QRectF detectionRect(-5, -5, 10, 10); // 判定范围为10x10的矩形区域
        for (int i = 0; i < cornerPoints.size(); ++i) {
            if (cornerPoints[i] && detectionRect.translated(cornerPoints[i]->scenePos()).contains(scenePos)) {
                isResizing = true;
                resizingCornerIndex = i;
                break;
            }
        }
        if (rotationPoint && detectionRect.translated(rotationPoint->scenePos()).contains(scenePos)) {
            isRotating = true;
        }
    }

    QGraphicsEllipseItem::mousePressEvent(event);
}

void EllipseShapeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (isResizing) {
        setFlag(QGraphicsItem::ItemIsMovable,false);
        QPointF currentPos = event->scenePos();
        QRectF newRect = originalRect;
        QPointF center = originalRect.center();  // 获取当前矩形的中心

        // Adjust width or height based on which corner is being dragged
        if (resizingCornerIndex == 1) {
            // Adjust width by changing the bottom center point
            setCursor(Qt::SizeHorCursor);
            qreal deltaWidth = currentPos.x() - resizeStartPos.x();
            newRect.setWidth(originalRect.width() - deltaWidth);
        } else if (resizingCornerIndex == 0) {
            // Adjust height by changing the left center point
            setCursor(Qt::SizeVerCursor);
            qreal deltaHeight = currentPos.y() - resizeStartPos.y();
            newRect.setHeight(originalRect.height() + deltaHeight);
        }

        // 确保新矩形的中心保持不变
        newRect.moveCenter(center);

        setRect(newRect);
        updatePoints();
    }
    else if (isRotating) {
        setFlag(QGraphicsItem::ItemIsMovable, false);
        QPointF center = rect().center();
        QPointF currentPos = event->scenePos();
        QLineF lineToStart(center, resizeStartPos);
        QLineF lineToCurrent(center, currentPos);
        // 计算从起始位置到当前鼠标位置的旋转角度
        qreal angle = lineToStart.angleTo(lineToCurrent);
        // 逆时针旋转得到负角度，顺时针为正角度
        qreal newRotation = rotation() - angle;
        newRotation = normalizeAngle(newRotation);  // 规范化角度到 -180 到 180 范围内
        setRotation(newRotation);
        resizeStartPos = currentPos;  // 更新起始位置
    }
    QGraphicsEllipseItem::mouseMoveEvent(event);
}

void EllipseShapeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    isResizing = false;
    isRotating = false;
    setCursor(Qt::ArrowCursor);
    setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsEllipseItem::mouseReleaseEvent(event);
    updatePoints();
    emit shapeModified();
}

void EllipseShapeItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QPointF scenePos = event->scenePos();
    QRectF detectionRect(-5, -5, 10, 10); // 判定范围为10x10的矩形区域

    // 默认鼠标样式
    setCursor(Qt::ArrowCursor);

    if (centerPoint && detectionRect.translated(centerPoint->scenePos()).contains(scenePos)) {
        setCursor(Qt::SizeAllCursor);
    }
    else if (rotationPoint && detectionRect.translated(rotationPoint->scenePos()).contains(scenePos)) {
        setCursor(Qt::ClosedHandCursor);
    }
    else if (cornerPoints[0] && detectionRect.translated(cornerPoints[0]->scenePos()).contains(scenePos)) {
        setCursor(Qt::SizeVerCursor);
    }
    else if (cornerPoints[1] && detectionRect.translated(cornerPoints[1]->scenePos()).contains(scenePos)) {
        setCursor(Qt::SizeHorCursor);
    }

    QGraphicsEllipseItem::hoverMoveEvent(event);
}

qreal EllipseShapeItem::normalizeAngle(qreal angle) {
    while (angle < -180) angle += 360;
    while (angle > 180) angle -= 360;
    return angle;
}

void EllipseShapeItem::showPoints() {
    if (!centerPoint) {
        centerPoint = new QGraphicsEllipseItem(-2, -2, 4, 4, this);
        centerPoint->setBrush(QBrush(Qt::blue));
    }

    if (!rotationPoint) {
        rotationPoint = new QGraphicsEllipseItem(-2, -2, 4, 4, this);
        rotationPoint->setBrush(QBrush(QColor(255, 150, 150)));
    }

    if (cornerPoints.isEmpty()) {
        for (int i = 0; i < 2; ++i) {
            QGraphicsEllipseItem* corner = new QGraphicsEllipseItem(-2, -2, 4, 4, this);
            corner->setBrush(QBrush(Qt::green));
            cornerPoints.append(corner);
        }
    }
    updatePoints();
}

void EllipseShapeItem::updatePoints() {
    if (!centerPoint || !rotationPoint || cornerPoints.size() != 2) {
        return;
    }
    QRectF rect_2 = rect();
    // 更新端点
    centerPoint->setPos(rect_2.center());
    rotationPoint->setPos((rect_2.topRight() + rect_2.bottomRight()) / 2);      // 右边中心
    cornerPoints[0]->setPos((rect_2.bottomRight() + rect_2.bottomLeft()) / 2); // 下边中心
    cornerPoints[1]->setPos((rect_2.bottomLeft() + rect_2.topLeft()) / 2);     // 左边中心
    qDebug() << rotationPoint->pos();
}

void EllipseShapeItem::setPointsVisibility(bool visible) {
    if (centerPoint) centerPoint->setVisible(true); // 始终显示圆心点
    if (rotationPoint) rotationPoint->setVisible(visible);
    for (auto &point : cornerPoints) {
        updatePoints();
        point->setVisible(visible);
    }
}

QVariant EllipseShapeItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemSelectedChange) {
        bool selected = value.toBool();
        setPointsVisibility(selected);
    }
    return QGraphicsEllipseItem::itemChange(change, value);
}
