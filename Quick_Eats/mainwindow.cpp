#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initialize all the pages to the first page
    ui->primaryPageStackedWidget->setCurrentIndex(0);
    ui->loginStackedWidget->setCurrentIndex(0);
    ui->MWStackedWidget->setCurrentIndex(0);
    ui->FStackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mainLoginButton_clicked()
{
    //changes the page on the stacked widget to the enter credentials page
    ui->loginStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loginButton_clicked()
{
    //user authentication check //username and pass for foodie is "foodie", mainteneance worker is "MW"
    if(ui->usernameLineEdit->text() == "foodie" && ui->passwordLineEdit->text() == "foodie")
    {
        ui->primaryPageStackedWidget->setCurrentIndex(1);
    }
    else if(ui->usernameLineEdit->text() == "MW" && ui->passwordLineEdit->text() == "MW")
    {
        ui->primaryPageStackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_MWManageRestaurantsButton_clicked()
{
    //go to manage restaurants page
    ui->MWStackedWidget->setCurrentIndex(3);
}
