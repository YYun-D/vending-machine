#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
    ui->pushButton_5->setEnabled(money>=100);
    ui->pushButton_6->setEnabled(money>=200);
    ui->pushButton_7->setEnabled(money>=300);
    ui->pushButton_8->setEnabled(money>0);
}



void MainWindow::on_pushButton_clicked()
{
    changeMoney(10);
}

void MainWindow::on_pushButton_2_clicked()
{
    changeMoney(50);
}


void MainWindow::on_pushButton_3_clicked()
{
    changeMoney(100);
}


void MainWindow::on_lcdNumber_overflow()
{

}


void MainWindow::on_pushButton_4_clicked()
{
    changeMoney(500);
}


void MainWindow::on_pushButton_5_clicked()
{
    changeMoney(-100);
}


void MainWindow::on_pushButton_6_clicked()
{
    changeMoney(-150);
}


void MainWindow::on_pushButton_7_clicked()
{
    changeMoney(-200);
}


void MainWindow::on_pushButton_8_clicked()
{
    QMessageBox mb;
    mb.information(nullptr, "title",
                    "500 : " + QString::number(money/500) +
                    "\n100 : " + QString::number(money%500/100) +
                    "\n50 : " + QString::number(money%500%100/50) +
                    "\n10 : " + QString::number(money%500%100%50/10));
    money = 0;
    changeMoney(0);
}

