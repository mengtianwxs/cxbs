#include "mtview.h"

mtview::mtview(QWidget* parent):QGraphicsView (parent)
{

}

//void mtview::mouseMoveEvent(QMouseEvent *event)
//{
//    QPoint p=event->pos();
//    emit mouseMovePoint(p);
//    QGraphicsView::mouseMoveEvent(event);

//}

//void mtview::mousePressEvent(QMouseEvent *event)
//{
//    if(event->button()==Qt::LeftButton){

//        QPoint pf=event->pos();
//       emit mousePressPoint(pf);
//    }

//    QGraphicsView::mousePressEvent(event);

//}

void mtview::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){

        QPoint p=event->pos();
        emit  mouseReleasePoint(p);
    }

    QGraphicsView::mouseReleaseEvent(event);
}


