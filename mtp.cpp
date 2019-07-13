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
    pen.setWidth(2);
//    pen.setColor(Qt::red);


    int seg=20;
    int b=39;
    //hang
    for(int n=1;n<b+1;n++){

            QGraphicsLineItem* item = new QGraphicsLineItem(seg,seg*n,(b+9)*seg,seg*n);
            item->setPen(pen);
            item->setOpacity(0.6);
            scene->addItem(item);
            list_gird.append(item);





    }
    //shu
    for(int n=1;n<b+10;n++){

            QGraphicsLineItem* item = new QGraphicsLineItem(seg*n,seg,seg*n,seg*b);
            scene->addItem(item);
//            item->setPen(pen);
            item->setOpacity(0.6);
            list_gird.append(item);
    }

    QFont f;
    f.setBold(false);
    f.setPixelSize(10);
    //hanghao
    for(int n=1;n<b+10;n++){

//        qDebug()<<n*20;
        QGraphicsSimpleTextItem* txt=new QGraphicsSimpleTextItem();
        txt->setText(QString::number(n*20));
        txt->setFont(f);

        txt->setPos(QPointF(n*20,6));
        scene->addItem(txt);
        list_gird.append(txt);
        grid_posx.append(n*20);
    }

    //liehao
    for(int n=1;n<b+1;n++){
        QGraphicsSimpleTextItem* txt=new QGraphicsSimpleTextItem();
        txt->setText(QString::number(n*20));
        txt->setFont(f);

        txt->setPos(QPointF(2,n*20));
        scene->addItem(txt);
        list_gird.append(txt);
        grid_posy.append(n*20);

    }



    QListIterator<QGraphicsItem*> ti(list_gird);
    while (ti.hasNext()) {

        ti.next()->setSelected(false);
        ti.next()->setZValue(-100);
        ti.next()->setEnabled(false);
    }


//    qDebug()<<"numoflistgrid "<<list_gird.count();







}

void mtp::deleteGrid()
{
//    qDebug()<<QString::number(list_gird.count());

    int num=list_gird.count();

    QListIterator<QGraphicsItem*> ll(list_gird);
    while (ll.hasNext()) {
        scene->removeItem(ll.next());
    }

}

QGraphicsItem* mtp::drawByq(int sx, int sy, int w, int h)
{
     QGraphicsRectItem* rect=new QGraphicsRectItem(sx,sy,w,h);
     scene->addItem(rect);
     rect->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);

     QPen p;
     p.setWidth(0);
     p.setColor(Qt::red);
     rect->setPen(p);
     QBrush brush;
     brush.setColor(Qt::red);
     brush.setStyle(Qt::Dense7Pattern);
     rect->setBrush(brush);
     rect->setData(0,"byq");
     rect->setSelected(false);
     rect->clearFocus();
     list_items.append(rect);


     return rect;



}

QGraphicsItem* mtp::drawGuiti(int sx, int sy, int w, int h)
{
    QGraphicsRectItem* rect=new QGraphicsRectItem(sx,sy,w,h);
    scene->addItem(rect);
    rect->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);

    QPen p;
    p.setWidth(0);
    p.setColor(Qt::blue);
    rect->setPen(p);
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::BDiagPattern);
    rect->setBrush(brush);
    rect->setData(0,"guiti");
    rect->setSelected(false);
    rect->clearFocus();
    list_items.append(rect);
    return rect;


}

QGraphicsItem *mtp::drawZhouPoint(int sx, int sy, int r)
{
    QGraphicsEllipseItem* c=new QGraphicsEllipseItem(QRectF(sx,sy,r,r));
    scene->addItem(c);

    QPen p;
    p.setWidth(0);
    c->setPen(p);
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    c->setBrush(brush);
    c->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);
    c->setData(0,"zp");
    list_zp.append(c);
    list_items.append(c);
    return c;

}

QGraphicsItem *mtp::drawPathItem(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
    QPainterPath path;
    QGraphicsPathItem* item =new QGraphicsPathItem();
    path.moveTo(p1);
    path.lineTo(p2);
    path.lineTo(p3);
    path.lineTo(p4);
    path.closeSubpath();
    item->setPath(path);
    item->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);
    list_items.append(item);
    QPen p;
    p.setWidth(4);
    p.setColor(Qt::red);
    item->setPen(p);
    item->setData(0,"zb");
    scene->addItem(item);
    return item;

}

