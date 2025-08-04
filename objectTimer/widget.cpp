#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    picid = 2;

    QPixmap pix("C:\\Users\\brf\\Pictures\\1.jpg");
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{   //开启定时器，返回定时器编号
    myTimerId = this->startTimer(TIMEOUT);
}

void Widget::timerEvent(QTimerEvent *event){
    if (event -> timerId() !=  myTimerId){
        return;
    }

    QString path("C:\\Users\\brf\\Pictures\\");
    path += QString::number(picid);
    path += ".png";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picid++;
    if (picid == 4){
        picid = 1;
    }
}
void Widget::on_stopButton_clicked()
{
    this->killTimer(myTimerId);

}

