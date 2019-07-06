#ifndef MTVIEW_H
#define MTVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>



class mtview : public QGraphicsView
{
    Q_OBJECT
public:
    mtview(QWidget* parent);
//    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);


signals:
//    void mouseMovePoint(QPoint p);
    void mousePressPoint(QPoint p);
    void mouseReleasePoint(QPoint p);
};

#endif // MTVIEW_H
