#include "mtview.h"

mtview::mtview(QWidget* parent):QGraphicsView (parent)
{

}

void mtview::mouseMoveEvent(QMouseEvent *event)
{
    QPointF p=event->pos();
    emit mouseMovePoint(p);
    QGraphicsView::mouseMoveEvent(event);

}

void mtview::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){

        QPointF pf=event->pos();
       emit mousePressPoint(pf);
    }

    QGraphicsView::mousePressEvent(event);

}
