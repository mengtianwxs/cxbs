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


public:
    void method_initData();
    void method_displayGrid();
    void method_deleteGrid();




private slots:
    void on_action_pin_triggered();
    void on_action_mu_triggered();
    void on_actionS11_30_triggered();
    void on_actionS11_50_triggered();
    void on_actionS11_63_triggered();
    void on_actionH1_triggered();
    void on_actionH2_triggered();
    void on_actionH3_triggered();
    void on_actionH4_triggered();
    void on_actionL1_triggered();
    void on_actionL2_triggered();
    void on_actionL3_triggered();
    void on_actionL6_triggered();
    void on_actionL4_triggered();
    void on_actionL5_triggered();

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
};

#endif // MAINWINDOW_H
