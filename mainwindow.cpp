#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    method_initUI();
    method_initData();

    view=ui->ui_gv;
    scene=new QGraphicsScene(this);
    view->setScene(scene);
    view->setFixedSize(1000,800);
//    gti=new QGraphicsTextItem();
//    gti->setPlainText("this is mengtianwxs");
//    scene->addItem(gti);

//    QGraphicsRectItem* rec=new QGraphicsRectItem(0,0,100,100);
//    scene->addItem(rec);
//    QTransform tran;
//    qDebug()<<scene->itemAt(50,50,tran)<<"pp";
//    qDebug()<<rec->scenePos()<<rec->sceneBoundingRect();
      p=new mtp(scene);

      ui->actionPinZiXing->setEnabled(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::method_initData()
{
   map.insert("s11-30","745*580");
   map.insert("s11-50","795*600");
   map.insert("s11-63","825*610");
   map.insert("s11-80","855*645");
   map.insert("s11-100","870*675");
   map.insert("s11-125","900*705");
   map.insert("s11-160","1135*720");
   map.insert("s11-200","1180*740");
   map.insert("s11-250","1210*755");
   map.insert("s11-315","1245*600");
   map.insert("s11-400","795*600");
   map.insert("s11-500","795*600");
   map.insert("s11-630","795*600");
   map.insert("s11-800","795*600");
   map.insert("s11-1000","795*600");
   map.insert("s11-1250","795*600");
   map.insert("s11-1600","795*600");
   map.insert("s11-2000","795*600");
   map.insert("s11-2500","795*600");



   ag_ad=new QActionGroup(this);
   ag_ad->addAction(ui->action_pin);
   ag_ad->addAction(ui->action_mu);
   ag_ad->setExclusive(true);



   ag_as=new QActionGroup(this);
   ag_as->addAction(ui->actionS11_30);
   ag_as->addAction(ui->actionS11_50);
   ag_as->addAction(ui->actionS11_63);
   ag_as->addAction(ui->actionS11_80);
   ag_as->addAction(ui->actionS11_100);
   ag_as->addAction(ui->actionS11_125);
   ag_as->addAction(ui->actionS11_160);
   ag_as->addAction(ui->actionS11_200);
   ag_as->addAction(ui->actionS11_250);
   ag_as->addAction(ui->actionS11_315);
   ag_as->addAction(ui->actionS11_400);
   ag_as->addAction(ui->actionS11_500);
   ag_as->addAction(ui->actionS11_630);
   ag_as->addAction(ui->actionS11_800);
   ag_as->addAction(ui->actionS11_1250);
   ag_as->addAction(ui->actionS11_1000);
   ag_as->addAction(ui->actionS11_1600);
   ag_as->addAction(ui->actionS11_2000);
   ag_as->addAction(ui->actionS11_2500);





}

void MainWindow::method_initUI()
{
   ui->action_pin->setChecked(true);
   str_design="pin";
   ui->actionS11_630->setChecked(true);

}

void MainWindow::method_displayGrid()
{
    isDisplayGrid=false;
    p->drawGrid();


}

void MainWindow::method_deleteGrid()
{
    isDisplayGrid=true;
    p->deleteGrid();

}


void MainWindow::on_action_pin_triggered()
{
   str_design="pin";
   qDebug()<<str_design;
}

void MainWindow::on_action_mu_triggered()
{
  str_design="mu";
  qDebug()<<str_design;
}

void MainWindow::on_actionS11_30_triggered()
{

}

void MainWindow::on_actionS11_50_triggered()
{

}

void MainWindow::on_actionS11_63_triggered()
{

}

void MainWindow::on_actionH1_triggered()
{

}

void MainWindow::on_actionH2_triggered()
{

}

void MainWindow::on_actionH3_triggered()
{

}

void MainWindow::on_actionH4_triggered()
{

}

void MainWindow::on_actionL1_triggered()
{

}

void MainWindow::on_actionL2_triggered()
{

}

void MainWindow::on_actionL3_triggered()
{

}

void MainWindow::on_actionL6_triggered()
{

}

void MainWindow::on_actionL4_triggered()
{

}

void MainWindow::on_actionL5_triggered()
{

}


void MainWindow::on_action_caohuimenu_triggered()
{

}

void MainWindow::on_actioncaohui_triggered()
{
    ui->tabWidget->setCurrentIndex(2);
    p->deleteGrid();
}

void MainWindow::on_actionDemo_triggered()
{
   // p->drawBorder(0,0,400,400);

}

void MainWindow::on_actionDrawGrid_triggered()
{

   // p->drawBorder(0,0,400,400);
    qDebug()<<isDisplayGrid;
   isDisplayGrid?method_displayGrid():method_deleteGrid();


    this->statusBar()->showMessage("draw grid");
}



void MainWindow::on_actionborder_triggered()
{
    p->drawBorder(this->view->width()/2-200,this->view->height()/2-150,400,300);
}

