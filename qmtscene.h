#ifndef QMTSCENE_H
#define QMTSCENE_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QObject>

class QMtScene : public QGraphicsView
{
    Q_OBJECT
public:
    QMtScene(QWidget* parent);

    void mouseMoveEvent(QMouseEvent* event);
signals:
    void mouseMovePoint(QPoint);


};

#endif // QMTSCENE_H
