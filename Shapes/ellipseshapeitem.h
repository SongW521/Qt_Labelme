#ifndef ELLIPSESHAPEITEM_H
#define ELLIPSESHAPEITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class EllipseShapeItem : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    EllipseShapeItem(qreal x, qreal y, qreal width, qreal height);

signals:
    void shapeModified();
private:
    bool isResizing;
    bool isRotating;
    int resizingCornerIndex;
    QPointF resizeStartPos;
    QRectF originalRect;
    QGraphicsEllipseItem *centerPoint;
    QGraphicsEllipseItem *rotationPoint;
    QList<QGraphicsEllipseItem*> cornerPoints;
    qreal normalizeAngle(qreal angle);
private:
    void  showPoints();
    void  updatePoints();
    void  setSelected(bool selected);
    void  setPointsVisibility(bool visible);



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

};

#endif // ELLIPSESHAPEITEM_H
