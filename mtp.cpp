#include "mtp.h"

#include <QGraphicsTextItem>

mtp::mtp(QGraphicsScene* scene)
{
    this->scene=scene;
}

void mtp::drawBorder(int sx, int sy, int w, int h)
{
     QGraphicsRectItem* rect=new QGraphicsRectItem(sx,sy,w,h);
     scene->addItem(rect);
     QPen p;
     p.setWidth(20);
     rect->setPen(p);
     rect->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
}

void mtp::drawGrid()
{

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);


    int seg=20;
    int b=39;
    //hang
    for(int n=1;n<b+1;n++){

            QGraphicsLineItem* item = new QGraphicsLineItem(seg,seg*n,(b+9)*seg,seg*n);
            item->setPen(pen);
            item->setOpacity(0.5);
            scene->addItem(item);
            list_gird.append(item);

    }
    //shu
    for(int n=1;n<b+10;n++){

            QGraphicsLineItem* item = new QGraphicsLineItem(seg*n,seg,seg*n,seg*b);
            scene->addItem(item);
            item->setOpacity(0.5);
            list_gird.append(item);
    }


}

void mtp::deleteGrid()
{
    qDebug()<<QString::number(list_gird.count());

    int num=list_gird.count();

    QListIterator<QGraphicsItem*> ll(list_gird);
    while (ll.hasNext()) {
        scene->removeItem(ll.next());
    }

}

