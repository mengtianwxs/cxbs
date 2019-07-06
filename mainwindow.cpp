#include "mainwindow.h"
#include "mttextitem.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QInputDialog>
#include <QString>
#include<QtAlgorithms>
#include<algorithm>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1330,800);

    QDesktopWidget* desktop=QApplication::desktop();
    int dw=desktop->screen()->width();
    int dh=desktop->screen()->height();

    this->move((dw-1330)/2,30);
//    this->move(0,0);


 qDebug()<<this->width()<<this->height()<<"fdfsd"<<dw<<dh;

    method_initUI();
    method_initData();

    view=ui->ui_gv;
    scene=new QGraphicsScene();
    view->setScene(scene);
    view->setFixedSize(1100,800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->tabWidget->setFixedWidth(225);



      p=new mtp(scene);

//      ui->actionPinZiXing->setEnabled(false);

//      connect(view,SIGNAL(mouseMovePoint(QPoint)),this,SLOT(method_onViewMouseMove(QPoint)));
      connect(view,SIGNAL(mousePressPoint(QPoint)),this,SLOT(method_onViewClick(QPoint)));
      connect(view,SIGNAL(mouseReleasePoint(QPoint)),this,SLOT(method_onMouseRelease(QPoint)));
      connect(ui->actionXiFuGrid,SIGNAL(toggled(bool)),this,SLOT(method_onToggleXifu(bool)));

      view->setMouseTracking(true);
      view->setDragMode(QGraphicsView::RubberBandDrag);
      view->setCursor(Qt::CrossCursor);





     QButtonGroup* cbg=new QButtonGroup();
     cbg->addButton(ui->cb_heng);
     cbg->addButton(ui->cb_shu);
     ui->cb_heng->setChecked(true);








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::method_initData()
{
   map_byq.insert("s11-30","745*580");
   map_byq.insert("s11-50","795*600");
   map_byq.insert("s11-63","825*610");
   map_byq.insert("s11-80","855*645");
   map_byq.insert("s11-100","870*675");
   map_byq.insert("s11-125","900*705");
   map_byq.insert("s11-160","1135*720");
   map_byq.insert("s11-200","1180*740");
   map_byq.insert("s11-250","1210*755");
   map_byq.insert("s11-315","1245*600");
   map_byq.insert("s11-400","1310*815");
   map_byq.insert("s11-500","1445*885");
   map_byq.insert("s11-630","1485*945");
   map_byq.insert("s11-800","1540*990");
   map_byq.insert("s11-1000","1660*1115");
   map_byq.insert("s11-1250","1760*1185");
   map_byq.insert("s11-1600","1860*1260");
   map_byq.insert("s11-2000","2055*1305");
   map_byq.insert("s11-2500","2220*1415");



//   ag_ad=new QActionGroup(this);
//   ag_ad->addAction(ui->action_pin);
//   ag_ad->addAction(ui->action_mu);
//   ag_ad->setExclusive(true);



   ag_as_byq=new QActionGroup(this);
   ag_as_byq->addAction(ui->actionS11_30);
   ag_as_byq->addAction(ui->actionS11_50);
   ag_as_byq->addAction(ui->actionS11_63);
   ag_as_byq->addAction(ui->actionS11_80);
   ag_as_byq->addAction(ui->actionS11_100);
   ag_as_byq->addAction(ui->actionS11_125);
   ag_as_byq->addAction(ui->actionS11_160);
   ag_as_byq->addAction(ui->actionS11_200);
   ag_as_byq->addAction(ui->actionS11_250);
   ag_as_byq->addAction(ui->actionS11_315);
   ag_as_byq->addAction(ui->actionS11_400);
   ag_as_byq->addAction(ui->actionS11_500);
   ag_as_byq->addAction(ui->actionS11_630);
   ag_as_byq->addAction(ui->actionS11_800);
   ag_as_byq->addAction(ui->actionS11_1250);
   ag_as_byq->addAction(ui->actionS11_1000);
   ag_as_byq->addAction(ui->actionS11_1600);
   ag_as_byq->addAction(ui->actionS11_2000);
   ag_as_byq->addAction(ui->actionS11_2500);





}

void MainWindow::method_initUI()
{
//   ui->action_pin->setChecked(true);
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




void MainWindow::on_actionDrawGrid_triggered()
{

   // p->drawBorder(0,0,400,400);
    qDebug()<<isDisplayGrid;
   isDisplayGrid?method_displayGrid():method_deleteGrid();


    this->statusBar()->showMessage("draw grid");
}






void MainWindow::on_actionword_triggered()
{
    QString content=QInputDialog::getText(this,"请输入文字","");
   if(content!=""){
       QGraphicsTextItem * ti=new QGraphicsTextItem();
       ti->setPlainText(content);
       ti->setPos(QPoint(20,20));
       ti->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
       ti->setAcceptDrops(true);

       scene->addItem(ti);
       scene->clearSelection();

       connect(ti,SIGNAL(dragMovePoint(QPointF)),this,SLOT(method_ontextdragMove(QPointF)));
//       qDebug()<<"connect text";

   }


}

//void MainWindow::method_onViewMouseMove(QPoint pv)
//{
//    QPointF obj_point=view->mapToScene(pv);
//    QGraphicsItem* item=scene->itemAt(obj_point,view->transform());

//    if(item !=NULL ){

//        QPointF item_point=item->mapFromScene(obj_point);

//        qDebug()<<"itemx "<<item_point.x()<<"itemy "<<item_point.y();
//    }
//}

void MainWindow::method_onViewClick(QPoint pv)
{

//    qDebug()<<"onviewclick";

//    QPointF obj_point=view->mapToScene(pv);
//    QGraphicsItem* item=scene->itemAt(obj_point,view->transform());

//    if(item !=NULL ){

//        QPointF item_point=item->mapFromScene(obj_point);

//        qDebug()<<"itemx "<<item_point.x()<<"itemy "<<item_point.y();
//    }


}



void MainWindow::on_actionDeleteItem_triggered()
{
    int num=scene->selectedItems().count();
    if(num>0){
        QGraphicsItem *item=scene->selectedItems().at(0);
        scene->removeItem(item);
    }

}

void MainWindow::method_onMouseRelease(QPoint pv)
{

    QPointF pf=view->mapToScene(pv);
    QGraphicsItem * item=scene->itemAt(pf,view->transform());


    if((item!=NULL) && isXiFu && (item->flags()!=NULL) )
    {

        //     qDebug()<<"itemx "<<item->x()<<"itemy "<<item->y();
        //获取网格中的所有点的坐标
        QList<int> posx=p->grid_posx;
        QList<int> posy=p->grid_posy;
        //获取选中图元的坐标
        int itempx=item->x();
        int itempy=item->y();


        //判断图元的坐标在网格范围内，如果超出网格则无效
        if(itempx>20 and itempy >20 and itempx<960 and itempy<780){

            // 获取最接近网格的坐标
            QList<int>::iterator ix=qLowerBound(posx.begin(),posx.end(),itempx);
            QList<int>::iterator iy=qLowerBound(posy.begin(),posy.end(),itempy);
//            qDebug()<<"网格的坐标x"<<*ix<<"网格的坐标y"<<*iy;
            //      item->setPos(QPointF(*ix,*iy));
            //     if(*ix<20 or *iy <20 or ix>)



            //获取当前的位置索引
            int index_x=0;
            int index_y=0;

            for(int n=0;n<posx.length();n++){

                if(posx.at(n)==*ix){
                    index_x=n;
                }
            }

            for(int m=0;m<posy.length();m++){

                if(posy.at(m)==*iy){
                    index_y=m;
                }
            }

            //新的索引位置
            int newx=0;
            int newy=0;
            newx=posx.at(index_x-1);
            newy=posy.at(index_y-1);

//            qDebug()<<"newx "<<newx<<","<<"newy "<<newy;

            item->setPos(QPointF(newx,newy));

        }


    }
    if(item != NULL){

     ui->statusBar->showMessage("item ( "+QString::number(item->x())+" , "+QString::number(item->y())+" )");
    }



}



//void MainWindow::method_ontextdragMove(QPointF pf)
//{
//    qDebug()<<"drag";
//    QGraphicsItem* item=scene->itemAt(pf,view->transform());
//    int num=scene->selectedItems().count();

//    if(item!=NULL && num>1){

//        qDebug()<<"item"<<item->x()<<" : "<<item->y();
//    }
//}



void MainWindow::on_actionbianyaqi_triggered()
{
//    qDebug()<<ag_as_byq->checkedAction()->text();

    QString byqtype=ag_as_byq->checkedAction()->text().toLower();
//    qDebug()<<map_byq[byqtype];
    QString byqsize=map_byq[byqtype];
    QStringList byqsize_list=byqsize.split("*");
    int byq_deep=byqsize_list.at(0).toInt();
    int byq_width=byqsize_list.at(1).toInt();

//    qDebug()<<"cbstate"<<ui->cb_heng->isChecked()<<ui->cb_shu->isChecked();

    if(ui->cb_heng->isChecked()){
    p->drawByq(0,0,byq_deep/10,byq_width/10);

    }

    if(ui->cb_shu->isChecked()){
        p->drawByq(0,0,byq_width/10,byq_deep/10);
    }

//    qDebug()<<"byqdeep "<<byq_deep<<" byqwidht"<<byq_width;

}




void MainWindow::method_onToggleXifu(bool b)
{
 b?isXiFu=true:isXiFu=false;
 qDebug()<<"xifu "<<isXiFu;

    if(isXiFu==true){
        ui->statusBar->showMessage("吸附网格打开");
    }

    if(isXiFu==false){
       ui->statusBar->showMessage("吸附网格关闭");
    }


}

void MainWindow::on_actioncombine_triggered()
{

    int num=scene->selectedItems().count();
    qDebug()<<num;
    if(num>=2){

        QGraphicsItemGroup* itemGroup=new QGraphicsItemGroup();
         scene->addItem(itemGroup);
         itemGroup->setData(0,"group");

        for(int i=0;i<num;i++){
            QGraphicsItem* item=scene->selectedItems().at(0);
            item->clearFocus();
            item->setSelected(false);
            itemGroup->addToGroup(item);

        }


        itemGroup->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);
        scene->clearSelection();
        itemGroup->setSelected(true);

    }


}

void MainWindow::on_actionfenjie_triggered()
{
    int num=scene->selectedItems().count();

    if(num==1){
        QGraphicsItem* item=scene->selectedItems().at(0);
        if(item->data(0)=="group"){
            QGraphicsItemGroup * group=(QGraphicsItemGroup*)item;
            scene->destroyItemGroup(group);

        }



    }
}



void MainWindow::on_pb_setjianju_clicked()
{

   int num=scene->selectedItems().count();
    qDebug()<<"click"<<num;
   if(num==2){

        QGraphicsItem* item1=scene->selectedItems().at(0);
        QGraphicsItem* item2=scene->selectedItems().at(1);
//        qDebug()<<item1->x()<<item1->y()<<"item1"<<item2->x()<<item2->y()<<"item2";
        int item1width=item1->boundingRect().width();
        int item1height=item1->boundingRect().height();
        int item1posx=item1->x();
        int item1posy=item1->y();

        int item2width=item2->boundingRect().width();
        int item2height=item2->boundingRect().height();
        int item2posx=item2->x();
        int item2posy=item2->y();



      QRegExp re("[1-9][1-9][1-9][1-9][1-9][1-9]");
      QValidator* val=new QRegExpValidator(re,this);
      ui->le_hline->setValidator(val);
      ui->le_vline->setValidator(val);

      int vspace=ui->le_vline->text().toInt();
      int hspace=ui->le_hline->text().toInt();
      //cm
      if(hspace>0){
          if(item1posx<item2posx){
              item2->setX(item1posx+item1width+hspace);
          }

          if(item1posx>item2posx){
              item1->setX(item2posx+item2width+hspace);

          }
      }




   }
}
