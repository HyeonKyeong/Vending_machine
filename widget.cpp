#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(money);
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
    if(money >= 100)
        ui->pbCoffee->setEnabled(true);
    if(money >= 150)
        ui->pbTea->setEnabled(true);
    if(money >= 200)
        ui->pbCoke->setEnabled(true);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    if(money >= 100)
        ui->pbCoffee->setEnabled(true);
    if(money >= 150)
        ui->pbTea->setEnabled(true);
    if(money >= 200)
        ui->pbCoke->setEnabled(true);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
        ui->pbCoffee->setEnabled(true);
    if(money >= 150)
        ui->pbTea->setEnabled(true);
    if(money >= 200)
        ui->pbCoke->setEnabled(true);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    ui->pbCoffee->setEnabled(true);
    ui->pbTea->setEnabled(true);
    ui->pbCoke->setEnabled(true);
}

void Widget::on_pbCoffee_clicked()
{
    if(money < 100){
        ui->pbCoffee->setEnabled(false);
    }
    else {
            changeMoney(-100);
    }
}

void Widget::on_pbTea_clicked()
{
    if(money < 150){
        ui->pbTea->setEnabled(false);
    }
    else {
            changeMoney(-150);
    }
}

void Widget::on_pbCoke_clicked()
{
    if(money < 200){
        ui->pbCoke->setEnabled(false);
    }
    else {
        changeMoney(-200);
    }
}

void Widget::on_pbReset_clicked()
{
    int a = 0; //500won
    int b = 0; //100won
    int c = 0; //50won
    int d = 0; //10won
    while(money >= 500)
        {
            money -= 500;
            a++;
        }
    while(money >= 100)
        {
            money -=100;
            b++;
        }
    while(money >= 50)
        {
            money -=50;
            c++;
        }
    while(money >=10)
        {
            money -=10;
            d++;
        }
   // auto str = QString::number(money);
    QMessageBox msg;
    QString a1 = QString("500won : %1, 100won : %2, 50won : %3, 10won : %4").arg(a).arg(b).arg(c).arg(d);
    msg.information(nullptr, "Charge", a1);
    changeMoney(0);
}
