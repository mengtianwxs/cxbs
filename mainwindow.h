#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QActionGroup>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMap>
#include<QDebug>
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
    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsTextItem* gti;
    QActionGroup* ag_al;
    QActionGroup* ag_ad;
    QActionGroup* ag_ah;
    QActionGroup* ag_as_byq;

    QString str_design="";
    mtp* p;
    bool isDisplayGrid=true;
    bool isXiFu=true;


public:
    void method_initData();
    void method_initUI();
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
    void on_actionborder_triggered();

//    void method_onViewMouseMove(QPoint pv);
//    void method_onViewClick(QPoint pv);
    void on_actionword_triggered();
    void on_actionDeleteItem_triggered();
    void method_onMouseRelease(QPoint pv);

//    void method_ontextdragMove(QPointF pf);
    void on_actionbianyaqi_triggered();

    void on_actionXiFuGrid_triggered();
    void method_onToggleXifu(bool b);
};

#endif // MAINWINDOW_H
