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

    mtp(QGraphicsScene* scene);
    void drawBorder(int sx,int sy,int w,int h);
    void drawGrid();
    void deleteGrid();
};

#endif // MTP_H
