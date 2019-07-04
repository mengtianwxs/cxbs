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

    mtp(QGraphicsScene* scene);
    void drawBorder(int sx,int sy,int w,int h);
    void drawGrid();
    void deleteGrid();
    void drawByq(int sx,int sy,int w,int h);
};

#endif // MTP_H
