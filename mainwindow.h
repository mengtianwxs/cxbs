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
    QMap<QString,QString> map;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsTextItem* gti;
    QActionGroup* ag_al;
    QActionGroup* ag_ad;
    QActionGroup* ag_ah;
    QActionGroup* ag_as;

    QString str_design="";
    mtp* p;
    bool isDisplayGrid=true;


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

    void on_action_caohuimenu_triggered();
    void on_actioncaohui_triggered();
    void on_actionDemo_triggered();
    void on_actionDrawGrid_triggered();
    void on_action_triggered();
    void on_actionborder_triggered();
};

#endif // MAINWINDOW_H
