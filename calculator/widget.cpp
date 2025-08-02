#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(190,276);
    this->setMinimumSize(190,276);

    this->setWindowTitle("计算器");

    QFont f("宋体",12);//字体对象
    ui->mainLineEdit->setFont(f);

    //按钮上放图片
    QIcon con("C:\\Users\\brf\\Pictures\\1635e641b4034bdc85ba5852c40b964f~tplv-p14lwwcsbr-7.jpg");
    ui->deleteButton->setIcon(con);
    //改变按钮背景
    ui->resultButton->setStyleSheet("background:skyblue");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_1_clicked()
{
    expression += "1";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_2_clicked()
{
    expression += "2";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_3_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_4_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_5_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_6_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_7_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_8_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_9_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton_0_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_addButton_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_subButton_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_mulButton_clicked()
{
    expression += "x";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_divButton_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_deleteButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}

int Widget::apply(int a, int b, QChar op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == 'x') return a * b;
    if (op == '/') return b == 0 ? 0 : a / b; // 简单除零保护
    return 0;
}

int Widget::precedence(QChar op) {
    if (op == '+' || op == '-') return 1;
    if (op == 'x' || op == '/') return 2;
    return 0;
}

void Widget::calculateTop(QStack<int>& s_num, QStack<QChar>& s_opt) {
    int b = s_num.pop();
    int a = s_num.pop();
    QChar op = s_opt.pop();
    s_num.push(apply(a, b, op));
}

void Widget::on_resultButton_clicked()
{
    QString expr = ui->mainLineEdit->text().remove(' '); // 去空格
    QStack<int> s_num;
    QStack<QChar> s_opt;
    QString num;
    bool lastIsOp = true; // 用于判断负号位置

    for (int i = 0; i < expr.length(); ++i) {
        QChar ch = expr[i];

        if (ch == '(') {
            s_opt.push(ch);
            lastIsOp = true;
        }
        else if (ch == ')') {
            if (!num.isEmpty()) {
                s_num.push(num.toInt());
                num.clear();
            }

            while (!s_opt.isEmpty() && s_opt.top() != '(') {
                calculateTop(s_num, s_opt);
            }
            if (!s_opt.isEmpty() && s_opt.top() == '(')
                s_opt.pop();

            lastIsOp = false;
        }
        else if (ch.isDigit() || (ch == '-' && lastIsOp)) {
            num += ch;
            lastIsOp = false;
        }
        else if (ch == '+' || ch == '-' || ch == 'x' || ch == '/') {
            if (!num.isEmpty()) {
                s_num.push(num.toInt());
                num.clear();
            }

            while (!s_opt.isEmpty() && precedence(s_opt.top()) >= precedence(ch)) {
                calculateTop(s_num, s_opt);
            }
            s_opt.push(ch);
            lastIsOp = true;
        }
        else {
            // 非法字符
            ui->mainLineEdit->setText("非法字符！");
            return;
        }
    }

    if (!num.isEmpty()) {
        s_num.push(num.toInt());
    }

    while (!s_opt.isEmpty()) {
        calculateTop(s_num, s_opt);
    }

    if (s_num.size() == 1) {
        ui->mainLineEdit->setText(QString::number(s_num.top()));
    } else {
        ui->mainLineEdit->setText("表达式错误！");
    }
    expression.clear();
}

void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->clear();
}
