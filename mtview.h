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

signals:
    void mouseMovePoint(QPointF p);
    void mousePressPoint(QPointF p);
};

#endif // MTVIEW_H
