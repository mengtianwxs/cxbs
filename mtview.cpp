#include "mtview.h"

mtview::mtview(QWidget* parent):QGraphicsView (parent)
{

}

void mtview::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p=event->pos();
    emit mouseMovePoint(p);
    QGraphicsView::mouseMoveEvent(event);

}

void mtview::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){

        QPoint pf=event->pos();
       emit mousePressPoint(pf);
    }

    QGraphicsView::mousePressEvent(event);

}

void mtview::drawMoveEvent(QDragMoveEvent *event)
{

    event->accept();
    QPoint p=event->pos();
    emit mouseDragPoint(p);
    QGraphicsView::dragMoveEvent(event);

}
