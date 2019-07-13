#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QActionGroup>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMap>
#include<QDebug>
#include <QButtonGroup>
#include "mtp.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMap<QString,QString> map_byq;
    QMap<QString,QString> map_guiti;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsTextItem* gti;

    QActionGroup* ag_guiti;
    QActionGroup* ag_as_byq;
    QButtonGroup* cbg;


    QString str_design="";
    mtp* p;
    bool isDisplayGrid=true;
    bool isXiFu=false;
    QTimer* timer;
    QPointF np1,np2,np3,np4;
    bool isCtrlPressed=false;


public:
    void method_initData();
    void method_displayGrid();
    void method_deleteGrid();
    bool method_panduanPoint4isOk(QPointF,QPointF,QPointF,QPointF);
    int method_maxPoint4(QList<int> pl);
    int method_minPoint4(QList<int> pl);




private slots:


    void on_actionDrawGrid_triggered();

//    void method_onViewMouseMove(QPoint pv);
    void method_onViewClick(QPoint pv);
    void on_actionword_triggered();
    void on_actionDeleteItem_triggered();
    void method_onMouseRelease(QPoint pv);

    void on_actionbianyaqi_triggered();

    void method_onToggleXifu(bool b);
    void on_actioncombine_triggered();
    void on_actionfenjie_triggered();
    void on_pb_setjianju_clicked();
    void method_onTimerOut();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_actionguiti_triggered();
    void on_pushButton_clicked();
    void method_onbuttonToggled(QAbstractButton *,bool);
    void on_actionvjuzhong_triggered();
    void on_actionhjuzhong_triggered();
    void on_actionzhoupoint_triggered();
    void on_action_qingkong_triggered();
    void on_actionlianxian_triggered();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
