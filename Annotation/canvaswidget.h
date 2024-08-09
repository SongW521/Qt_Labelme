#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QVector>
#include <QGraphicsPixmapItem>
#include "ellipseshapeitem.h"

struct flagBuffer {
    QString labelname;
    QPointF center;
    float w;
    float h;
    float angle;
};

class CanVasWidget : public QGraphicsView
{
    Q_OBJECT

public:
    CanVasWidget(QWidget *parent = nullptr);
    ~CanVasWidget();

    void updateBkgroudImage(const QPixmap &pixmap);
    void setDrawMode(bool draw);
    QVector<flagBuffer> getItemsFlagBuffer();

signals:
    void drawFinish();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void handleShapeModified();

private:
    QGraphicsScene *scene;
    QVector<EllipseShapeItem*> ellipseItem;
    QPointF startPos;
    EllipseShapeItem *currentEllipse; // 当前正在绘制的椭圆
public:
    bool isDraw;
    int itemIndex;
};

#endif // CANVASWIDGET_H
