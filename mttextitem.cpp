#include "mttextitem.h"

mttextitem::mttextitem(QGraphicsItem *parent):QGraphicsTextItem (parent)
{

}

void mttextitem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(true);
    update();
    QPointF point=event->pos();
    emit dragMovePoint(point);
    QGraphicsTextItem::dragMoveEvent(event);

}
