#include "mainwindow.h"
#include "mttextitem.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QInputDialog>
#include <QString>
#include <QTimer>
#include<QtAlgorithms>
#include<QtMath>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1430,800);

    QDesktopWidget* desktop=QApplication::desktop();
    int dw=desktop->screen()->width();
    int dh=desktop->screen()->height();

    this->move((dw-1330)/2,30);

    view=ui->ui_gv;
    scene=new QGraphicsScene();
    view->setScene(scene);
    view->setFixedSize(1100,800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->tabWidget->setFixedWidth(400);

    p=new mtp(scene);


    //connect(view,SIGNAL(mouseMovePoint(QPoint)),this,SLOT(method_onViewMouseMove(QPoint)));
    connect(view,SIGNAL(mousePressPoint(QPoint)),this,SLOT(method_onViewClick(QPoint)));
    connect(view,SIGNAL(mouseReleasePoint(QPoint)),this,SLOT(method_onMouseRelease(QPoint)));
    connect(ui->actionXiFuGrid,SIGNAL(toggled(bool)),this,SLOT(method_onToggleXifu(bool)));

    view->setMouseTracking(true);
    view->setDragMode(QGraphicsView::RubberBandDrag);
    view->setCursor(Qt::CrossCursor);
    view->setRenderHint(QPainter::Antialiasing);








    ui->te_info->setEnabled(false);
    ui->te_info->setText("init complete!\n");

    timer=new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(method_onTimerOut()));
     method_initData();

     ui->le_hline->setText("=");
     ui->le_vline->setText("=");


     connect(cbg,SIGNAL(buttonToggled(QAbstractButton *,bool)),this,SLOT(method_onbuttonToggled(QAbstractButton *,bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::method_initData()
{

    cbg=new QButtonGroup();
    cbg->addButton(ui->cb_heng);
    cbg->addButton(ui->cb_shu);
    ui->cb_heng->setChecked(true);

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
   ui->actionS11_630->setChecked(true);


   ag_guiti=new QActionGroup(this);
   ag_guiti->addAction(ui->action750_900);
   ag_guiti->addAction(ui->action900_1000);
   ag_guiti->addAction(ui->action1000_600);
   ag_guiti->addAction(ui->action600_600);
   ag_guiti->addAction(ui->action800_600);
   ag_guiti->addAction(ui->action1200_600);
   ui->action750_900->setChecked(true);
//   map_guiti.insert("750*900","750*900");
//   map_guiti.insert("900*1000","900*1000");
//   map_guiti.insert("900*1000","1000*600");
//   map_guiti.insert("900*1000","900*1000");
//   map_guiti.insert("900*1000","900*1000");
//   map_guiti.insert("900*1000","900*1000");
//   map_guiti.insert("900*1000","900*1000");





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

bool MainWindow::method_panduanPoint4isOk(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{

    //method1
//    if(p1.x()>p4.x() and p1.x()<p2.x() and p3.x()>p4.x() and p3.x()<p2.x() and p4.y()>p1.y() and p4.y()<p3.y() and p2.y()> p1.y() and p2.y()< p3.y()){

//        return true;
//    }
    //method2



    return false;
}

int MainWindow::method_maxPoint4(QList<int> pl)
{
    int max=pl.at(0);
    int num=pl.count();
    if(num>0){

        for(int i=0;i<num;i++){
            if(pl.at(i)>max){
                max=pl.at(i);
            }
        }
        return max;
    }



}

int MainWindow::method_minPoint4(QList<int> pl)
{

    int max=pl.at(0);
    int num=pl.count();
    if(num>0){

        for(int i=0;i<num;i++){
            if(pl.at(i)<max){
                max=pl.at(i);
            }
        }
        return max;
    }

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

    //鼠标单击的点判断有没有图元
//    QPointF obj_point=view->mapToScene(pv);
//    QGraphicsItem* item=scene->itemAt(obj_point,view->transform());

//    if(item !=NULL ){

////        QPointF item_point=item->mapFromScene(obj_point);

////        qDebug()<<"itemx "<<item_point.x()<<"itemy "<<item_point.y();

//        int index=scene->selectedItems().indexOf(item);
//        qDebug()<<index<<"index";
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

    QString byqtype=ag_as_byq->checkedAction()->text().toLower();
    QString byqsize=map_byq[byqtype];
    QStringList byqsize_list=byqsize.split("*");
    int byq_deep=byqsize_list.at(0).toInt();
    int byq_width=byqsize_list.at(1).toInt();

    if(ui->cb_heng->isChecked()){
    p->drawByq(0,0,byq_deep/10,byq_width/10);

    }

    if(ui->cb_shu->isChecked()){
        p->drawByq(0,0,byq_width/10,byq_deep/10);
    }


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
//    qDebug()<<num;
    if(num>=2){

        QGraphicsItemGroup* itemGroup=new QGraphicsItemGroup();
         scene->addItem(itemGroup);
         itemGroup->setData(0,"group");
         itemGroup->setX(0);
         itemGroup->setY(0);

        for(int i=0;i<num;i++){
            QGraphicsItem* item=scene->selectedItems().at(0);
            item->clearFocus();
            item->setSelected(false);
            itemGroup->addToGroup(item);

        }


        itemGroup->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);
        scene->clearSelection();
        itemGroup->setSelected(true);
        itemGroup->setData(0,"ig");

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
    QRegExp re("=?-?[0-9]{1,4}");
    QValidator* val=new QRegExpValidator(re,ui->page_3);
    ui->le_hline->setValidator(val);
    ui->le_vline->setValidator(val);

   int num=scene->selectedItems().count();
//    qDebug()<<"click"<<num;
   if(num==2){

        QGraphicsItem* item1=scene->selectedItems().at(0);
        QGraphicsItem* item2=scene->selectedItems().at(1);

        //判断是否为周点
        bool isZP1=item1->data(0)=="zp"?true:false;
        bool isZP2=item2->data(0)=="zp"?true:false;
        //判断是否有且有一个周点
       bool isZP=(isZP1==true and isZP2==false) or (isZP1==false and isZP2==true);
        QGraphicsItem* itemzp=NULL;
        QGraphicsItem* itemgt=NULL;
        int zpx,zpy,gtx,gty,zpw,zph,gtw,gth=0;

        if(item1->data(0)=="zp"){
            itemzp=item1;
            itemgt=item2;
            zpx=item1->x();
            zpy=item1->y();
            zpw=item1->boundingRect().width();
            zph=item1->boundingRect().height();
            gtx=item2->x();
            gty=item2->y();
            gtw=item2->boundingRect().width();
            gth=item2->boundingRect().height();
        }
        if(item2->data(0)=="zp"){
            itemzp=item2;
            itemgt=item1;

            zpx=item2->x();
            zpy=item2->y();
            zpw=item2->boundingRect().width();
            zph=item2->boundingRect().height();
            gtx=item1->x();
            gty=item1->y();
            gtw=item1->boundingRect().width();
            gth=item1->boundingRect().height();
        }



        //有一个周点的情况 上下调整
        if(re.exactMatch(ui->le_vline->text()) and isZP ){
            qDebug()<<"this is zdian mode";

            int vspace=ui->le_vline->text().toInt();

            if(vspace<0){
                //@1 如果设置成0则让右边的往左靠，下边的往上靠
                //               如果为正值下往上靠
                //            周点在图元的上方
                if(zpy<gty){
                    ui->statusBar->showMessage("周点在图元的上方");
                    itemzp->setY(gty-qFabs(vspace));
                }
                //            周点在图元的下方
                if(zpy>gty){
                    ui->statusBar->showMessage("周点在图元的下方");

                    itemgt->setY(zpy-gth-qFabs(vspace));
                }
            }


            if(vspace>=0){
                //            周点在图元的上方
                if(zpy<gty){
                    //
                    itemgt->setY(zpy+qFabs(vspace));
                }

                //            周点在图元的下方
                if(zpy>gty){
                    itemzp->setY(gty+gth+qFabs(vspace));
                }

            }

        }


//有一个周点情况水平调整

        if(re.exactMatch(ui->le_hline->text()) and isZP ){
            qDebug()<<"this is zdian mode h";

            int hspace=ui->le_hline->text().toInt();

            if(hspace<0){
         //周点在图元的左方
                if(zpx<gtx){
                    ui->statusBar->showMessage("周点在图元的左方");
                    itemzp->setX(gtx-qFabs(hspace));
                }
                //            周点在图元的下方
                if(zpx>gtx){
                    ui->statusBar->showMessage("周点在图元的右方");

                    itemgt->setX(zpx-gtw-qFabs(hspace));
                }
            }


            if(hspace>=0){
                //
                if(zpx<gtx){
                    //
                    itemgt->setX(zpx+qFabs(hspace));
                }

                //
                if(zpx>gtx){
                    itemzp->setX(gtx+gtw+qFabs(hspace));
                }

            }

        }




//##############################################################################################







        //单独的两个图元存放处没有周点的情况
        if(item1->data(0)!="zp" and item2->data(0)!="zp"){


//        qDebug()<<item1->x()<<item1->y()<<"item1"<<item2->x()<<item2->y()<<"item2";
        int item1width=item1->boundingRect().width();
        int item1height=item1->boundingRect().height();
        int item1posx=item1->x();
        int item1posy=item1->y();

        int item2width=item2->boundingRect().width();
        int item2height=item2->boundingRect().height();
        int item2posx=item2->x();
        int item2posy=item2->y();

        if(re.exactMatch(ui->le_vline->text())){
            qDebug()<<"this is vline mode";

            int vspace=ui->le_vline->text().toInt();
            if(vspace<0){
                //@1 如果设置成0则让右边的往左靠，下边的往上靠
//               如果为正值下往上靠

                if(item1posy<item2posy){

                    item1->setY(item2posy-item1height-qFabs(vspace));
                }

                if(item1posy>item2posy){

                    item2->setY(item1posy-item2height-qFabs(vspace));
                }
            }

            if(vspace>=0){
                if(item1posy<item2posy){

                    item2->setY(item1posy+item1height+vspace);
                }

                if(item1posy>item2posy){

                    item1->setY(item2posy+item2height+vspace);
                }

            }

        }



        if(re.exactMatch(ui->le_hline->text())){
            qDebug()<<"this is hvlinemode ";
            int hspace=ui->le_hline->text().toInt();
            //cm
            if(hspace>=0){
                if(item1posx<item2posx){
                    item2->setX(item1posx+hspace+item1width);
                }

                if(item1posx>item2posx){
                    item1->setX(item2posx+hspace+item2width);

                }


            }

            if(hspace<0){
                if(item1posx<item2posx){
                    item1->setX(item2posx-item1width-qFabs(hspace));
                }

                if(item1posx>item2posx){
                    item2->setX(item1posx-item2width-qFabs(hspace));

                }


            }
        }

   }

        }











}

void MainWindow::method_onTimerOut()
{
//    qDebug()<<ag_as_byq->checkedAction()->text()<<ag_guiti->checkedAction()->text();
    QString byqstate=ag_as_byq->checkedAction()->text();
    QString guitistate=ag_guiti->checkedAction()->text();
    ui->te_info->setText("变压器 "+byqstate+"\n");
    ui->te_info->append("柜  体 "+guitistate+"\n");

    QString cbcheck="";
    if(ui->cb_heng->isChecked()){

        cbcheck=" -";
    }
    if(ui->cb_shu->isChecked()){

        cbcheck=" |";
    }
    ui->te_info->append("优先级别:"+cbcheck+"\n");

   int num=scene->selectedItems().count();
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

      ui->te_info->append("图元1 ( x "+QString::number(item1posx)+",y "+QString::number(item1posy)+"),( w "+QString::number(item1width)+",h "+QString::number(item1height)+")\n");
      ui->te_info->append("图元2 ( x "+QString::number(item2posx)+",y "+QString::number(item2posy)+"),( w "+QString::number(item2width)+",h "+QString::number(item2height)+")\n");

    }

    if(num==1){
        QGraphicsItem* item1=scene->selectedItems().at(0);
        int item1width=item1->boundingRect().width();
        int item1height=item1->boundingRect().height();
        int item1posx=item1->x();
        int item1posy=item1->y();
        QString itemtype="";
        if(item1->data(0)=="byq"){
            itemtype="变压器";
        }

        if(item1->data(0)=="guiti"){
            itemtype="内柜";
        }
        if(item1->data(0)=="zp"){
            itemtype="周点";
        }

        if(item1->data(0)=="zb"){

            itemtype="周边";
        }

        ui->te_info->append(itemtype+" ( x "+QString::number(item1posx)+",y "+QString::number(item1posy)+"),( w "+QString::number(item1width)+",h "+QString::number(item1height)+")\n");

    }





}


void MainWindow::on_pushButton_2_clicked()
{
    ui->le_hline->clear();
    ui->le_vline->clear();
    ui->le_hline->setText("=");
    ui->le_vline->setText("=");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->le_gtdeep->clear();
    ui->le_gtwidth->clear();

}

void MainWindow::on_actionguiti_triggered()
{
    QString gttype=ag_guiti->checkedAction()->text();
    QStringList gtsize_list=gttype.split("*");
    int gt_width=gtsize_list.at(0).toInt();
    int gt_deep=gtsize_list.at(1).toInt();
    qDebug()<<QString::number(gt_width)<<QString::number(gt_deep);

    if(ui->cb_heng->isChecked()){
    p->drawGuiti(0,0,gt_width/10,gt_deep/10);

    }

    if(ui->cb_shu->isChecked()){
        p->drawGuiti(0,0,gt_deep/10,gt_width/10);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int width=ui->le_gtwidth->text().toInt();
    int deep=ui->le_gtdeep->text().toInt();
    if(width >100 && deep >100){
    if(ui->cb_heng->isChecked()){
    p->drawGuiti(0,0,width/10,deep/10);

    }

    if(ui->cb_shu->isChecked()){
        p->drawGuiti(0,0,deep/10,width/10);
    }
    }

}

void MainWindow::method_onbuttonToggled(QAbstractButton * in, bool bo)
{
    int num=scene->selectedItems().count();
    QString strin=in->text();
    bool boolin=in->isChecked();
    if(num==1){
        QGraphicsItem* item=scene->selectedItems().at(0);
        int itemx=item->x();
        int itemy=item->y();
        int itemwidth=item->boundingRect().width();
        int itemheight=item->boundingRect().height();

        if(strin=="-" and boolin){

            if(item->data(0)=="byq"){
                QGraphicsItem* itemw= p->drawByq(0,0,itemheight,itemwidth);
                itemw->setPos(QPointF(itemx,itemy));
                itemw->setSelected(true);

                scene->removeItem(item);

                qDebug()<<"heng byq";


            }
            if(item->data(0)=="guiti"){
                QGraphicsItem* itemgt= p->drawGuiti(0,0,itemheight,itemwidth);
                itemgt->setPos(QPointF(itemx,itemy));
                 scene->removeItem(item);
                 itemgt->setSelected(true);
                qDebug()<<"heng gt";
            }




        }
        if(strin=="|" and boolin){


            if(item->data(0)=="byq"){
                QGraphicsItem* itemw= p->drawByq(0,0,itemheight,itemwidth);
                itemw->setPos(QPointF(itemx,itemy));
                 itemw->setSelected(true);
                scene->removeItem(item);
                qDebug()<<"su byq";

            }
            if(item->data(0)=="guiti"){
                QGraphicsItem* itemgt= p->drawGuiti(0,0,itemheight,itemwidth);
                itemgt->setPos(QPointF(itemx,itemy));
                itemgt->setSelected(true);
                 scene->removeItem(item);
                 qDebug()<<"su gt";
            }


        }
//

    }

}

void MainWindow::on_actionvjuzhong_triggered()
{

    //垂直居中
    int num=scene->selectedItems().count();
    if(num==2){
        QGraphicsItem* item1=scene->selectedItems().at(0);
        QGraphicsItem* item2=scene->selectedItems().at(1);
//   qDebug()<<item1->x()<<item1->y()<<"item1"<<item2->x()<<item2->y()<<"item2";
        int item1width=item1->boundingRect().width();
        int item1height=item1->boundingRect().height();
        int item1posx=item1->x();
        int item1posy=item1->y();

        int item2width=item2->boundingRect().width();
        int item2height=item2->boundingRect().height();
        int item2posx=item2->x();
        int item2posy=item2->y();

        if(item1width==item2width){
            if(item1posy<item2posy){

                item2->setPos(item1posx,item2posy);
            }
            if(item1posy>item2posy){
                item1->setPos(item2posx,item1posy);
            }


        }

        if(item1width>item2width){
            if(item1posy<item2posy){

                 item2->setPos(item1posx+(item1width-item2width)/2,item2posy);
              }

            if(item1posy>item2posy){
                item1->setPos(item1posx-(item1width-item2width)/2,item1posy);
            }

        }

        if(item1width<item2width){

            if(item1posy<item2posy){

                 item2->setPos(item1posx-(item2width-item1width)/2,item2posy);
              }

            if(item1posy>item2posy){
                item1->setPos((item2width-item1width)/2+item2posx,item1posy);
            }
        }




    }
}

void MainWindow::on_actionhjuzhong_triggered()
{

    //水平居中
    int num=scene->selectedItems().count();
    if(num==2){
        QGraphicsItem* item1=scene->selectedItems().at(0);
        QGraphicsItem* item2=scene->selectedItems().at(1);


//   qDebug()<<item1->x()<<item1->y()<<"item1"<<item2->x()<<item2->y()<<"item2";
        int item1width=item1->boundingRect().width();
        int item1height=item1->boundingRect().height();
        int item1posx=item1->x();
        int item1posy=item1->y();

        int item2width=item2->boundingRect().width();
        int item2height=item2->boundingRect().height();
        int item2posx=item2->x();
        int item2posy=item2->y();

        if(item1height==item2height){

            if(item1posx<item2posx){

                item2->setPos(item2posx,item1posy);
            }

            if(item1posx>item2posx){

                item1->setPos(item1posx,item2posy);
            }

        }


        if(item1height>item2height){

            if(item1posx<item2posx){

                item2->setPos(item2posx,(item1height-item2height)/2+item1posy);
            }

            if(item1posx>item2posx){

                item1->setPos(item1posx,item2posy-(item1height-item2height)/2);
            }

        }


        if(item1height<item2height){

            if(item1posx<item2posx){

                item2->setPos(item2posx,item1posy-(item1height-item2height)/2);
            }

            if(item1posx>item2posx){

                item1->setPos(item1posx,item1posy+(item1height-item2height)/2);
            }

        }



}
}

void MainWindow::on_actionzhoupoint_triggered()
{
//    qDebug()<<p->list_items.count();


    //如何ctrl按下则画4个周点
    if(isCtrlPressed){
        QGraphicsItem* item1=p->drawZhouPoint(-10,-10,20);
        QGraphicsItem* item2=p->drawZhouPoint(-10,-10,20);
        QGraphicsItem* item3=p->drawZhouPoint(-10,-10,20);
        QGraphicsItem* item4=p->drawZhouPoint(-10,-10,20);
        item1->moveBy(120,340);
        item2->moveBy(480,120);
        item3->moveBy(720,340);
        item4->moveBy(480,520);
//        qDebug()<<"draw zp";



    }else{
        p->drawZhouPoint(-10,-10,20);
    }
}

void MainWindow::on_action_qingkong_triggered()
{
    int num=p->list_items.count();
    if(num>0){
        QListIterator<QGraphicsItem*> it(p->list_items);
        while (it.hasNext()) {
            scene->removeItem(it.next());
        }
    }
}

void MainWindow::on_actionlianxian_triggered()
{

    //用框选来选择出周点对象
     int num=scene->selectedItems().count();
     qDebug()<<"num"<<num;
     if(num>4){
         QList<QPointF> listzp;
         QList<QGraphicsItem*> list_item;
          QPointF p1,p2,p3,p4;

         for(int i=0;i<num;i++){
             QGraphicsItem* item=scene->selectedItems().at(i);
             list_item.append(item);

         }
          qDebug()<<list_item;

//         QListIterator<QGraphicsItem*> it(list_item);
//         while (it.hasNext()) {
//             if(it.next()->data(0)=="zp"){
//                 listzp.append(it.next()->pos());
//             }
//         }
          int itemnum=list_item.count();
          for(int n=0;n<itemnum;n++){
              if(list_item.at(n)->data(0)=="zp"){

                  listzp.append(list_item.at(n)->pos());
              }
          }

          if(listzp.count()==4){

              p1=listzp.at(0);
              p2=listzp.at(1);
              p3=listzp.at(2);
              p4=listzp.at(3);

          }

         qDebug()<<listzp;



         int x1,x2,x3,x4,y1,y2,y3,y4;
         x1=p1.x();
         x2=p2.x();
         x3=p3.x();
         x4=p4.x();
         y1=p1.y();
         y2=p2.y();
         y3=p3.y();
         y4=p4.y();
         QList<int> listx;
         QList<int> listy;
         listx.append(x1);
         listx.append(x2);
         listx.append(x3);
         listx.append(x4);
         listy.append(y1);
         listy.append(y2);
         listy.append(y3);
         listy.append(y4);


         int maxx=method_maxPoint4(listx);
         int minx=method_minPoint4(listx);
         int maxy=method_maxPoint4(listy);
         int miny=method_minPoint4(listy);
         qDebug()<<"maxx minx"<<maxx<<minx<<"maxy miny"<<maxy<<miny;

         np1=QPointF(minx,miny);
         np2=QPointF(maxx,miny);
         np3=QPointF(maxx,maxy);
         np4=QPointF(minx,maxy);
         p->drawPathItem(np1,np2,np3,np4);
         double w=np2.x()-np1.x();
         double h=np3.y()-np2.y();
         double area=(w/100)*(h/100);
         double price=area*1700;
         ui->statusBar->showMessage("周边 w,h:("+QString::number(w/100)+","+QString::number(h/100)+") / area "+QString::number(area)+" m2 / price(1700/m2) " +QString::number(price));

     }





//         判断4点符合规则

 /*
         p1
    |||||||||||||
    |           |
 p4 |           |  p2
    |           |
    |||||||||||||

         p3
   */

   //有p2,p4两个点的y坐标在p1,p2两个点的y坐标范围内
   //有p1,p3两个点的x坐标在p2,p4两个点的x坐标范围内






}



void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->modifiers()==Qt::ControlModifier){

        isCtrlPressed=true;
         qDebug()<<"press key "<<isCtrlPressed;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(QApplication::keyboardModifiers()==Qt::ControlModifier){

        isCtrlPressed=false;
        qDebug()<<"press key relase"<<isCtrlPressed;
    }
}
