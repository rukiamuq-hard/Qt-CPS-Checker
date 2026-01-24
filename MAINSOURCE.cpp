#include "HEADER.h"
#include "./ui_FormUI.h"

Clicker::Clicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clicker)
{
   ui->setupUi(this);
   ui->TIMER->setText("00:00");
   connect(timer, &QTimer::timeout, this, &Clicker::startTimer);
}

Clicker::~Clicker()
{
    delete ui;
}

void Clicker::on_ClickButton_clicked(){
    strInptFrLine = ui->INPUTline->text();
    if(!timer->isActive()){
        timer->start(1000);
        curTime = QTime(0, 0, 0);
    }
    CLICKS++;
    ui->TEXT->setNum(CLICKS);

}

void Clicker::startTimer(){
    if(curTime == QTime(0, 0, (strInptFrLine.toInt()-1) )){
        timer->stop();
        CPSfunc();
    }
    curTime = curTime.addSecs(1);
    ui->TIMER->setText(curTime.toString("mm:ss"));
}

void Clicker::CPSfunc(){
    uint16_t CPS;
    CPS = CLICKS/(strInptFrLine.toInt() - 1);
    ui->CURRENTCPS->setNum(CPS);
    CLICKS = 0;
}
