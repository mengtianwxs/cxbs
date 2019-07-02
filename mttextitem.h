#ifndef MTTEXTITEM_H
#define MTTEXTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneDragDropEvent>



class mttextitem : public QGraphicsTextItem
{
    Q_OBJECT
public:
    mttextitem(QGraphicsItem *parent=nullptr);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);


 signals:
    void dragMovePoint(QPointF);
};

#endif // MTTEXTITEM_H
