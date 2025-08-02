#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>               // Qt 提供的栈结构，支持 push/pop/top
#include <QString>              // 字符串类，Qt 的替代 std::string
#include <QChar>                // 单个字符，Qt 的替代 char


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_addButton_clicked();

    void on_subButton_clicked();

    void on_mulButton_clicked();

    void on_divButton_clicked();

    void on_resultButton_clicked();

    void on_deleteButton_clicked();

    void on_clearButton_clicked();
private:
    Ui::Widget *ui;
    QString expression;
    int apply(int a, int b, QChar op);
    int precedence(QChar op);
    void calculateTop(QStack<int>& s_num, QStack<QChar>& s_opt);
};
#endif // WIDGET_H
