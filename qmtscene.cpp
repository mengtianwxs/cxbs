#include "qmtscene.h"



QMtScene::QMtScene(QWidget *parent):QGraphicsView (parent)
{

}

void QMtScene::mouseMoveEvent(QMouseEvent* event)
{
   QPoint p=event->pos();
   emit mouseMovePoint(p);


}
