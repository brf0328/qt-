#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer;

    picid = 2;

    QImage img;
    img.load("C:\\Users\\brf\\Pictures\\1.png");
    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出信号
    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    timer->start(MAX);
}

void Widget::timeoutSlot(){
    QString path("C:\\Users\\brf\\Pictures\\");
    path += QString::number(picid);
    path += ".png";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));
    if(picid == 3){
        picid = 1;
    }
    picid ++;
}

void Widget::on_pushButton_clicked()
{
    timer->stop();
}


void Widget::on_pushButton_3_clicked()
{
    QTimer::singleShot(1000,this,SLOT(timeoutSlot()));
}

