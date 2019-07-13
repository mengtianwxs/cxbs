#ifndef MTP_H
#define MTP_H

#include <QGraphicsScene>
#include<QDebug>
#include<QListIterator>



class mtp
{
public:
    QGraphicsScene* scene;
    QList<QGraphicsItem*> list_gird;
    QList<int> grid_posx;
    QList<int> grid_posy;
    QList<QGraphicsItem*> list_items;
    QList<QGraphicsItem*> list_zp;

    mtp(QGraphicsScene* scene);
    void drawBorder(int sx,int sy,int w,int h);
    void drawGrid();
    void deleteGrid();
    QGraphicsItem* drawByq(int sx,int sy,int w,int h);
    QGraphicsItem* drawGuiti(int sx,int sy,int w,int h);
    QGraphicsItem* drawZhouPoint(int sx,int sy,int r);
    QGraphicsItem* drawPathItem(QPointF p1,QPointF p2,QPointF p3,QPointF p4);

};

#endif // MTP_H
