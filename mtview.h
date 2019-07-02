#ifndef MTVIEW_H
#define MTVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>



class mtview : public QGraphicsView
{
    Q_OBJECT
public:
    mtview(QWidget* parent);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void drawMoveEvent(QDragMoveEvent* event);


signals:
    void mouseMovePoint(QPoint p);
    void mousePressPoint(QPoint p);
    void mouseDragPoint(QPoint p);
};

#endif // MTVIEW_H
