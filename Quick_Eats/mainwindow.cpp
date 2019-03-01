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


    int tempDistances[1] = {0};
    QVector<item> tempMenu;

    //CALL PARSER HERE
    restaurantsVector.push_back(restaurant(1, "McDonalds", 1, tempDistances, tempMenu));
    restaurantsVector[0].addMenuItem("Big Mac", 5.99, 1);
    restaurantsVector[0].addMenuItem("Fillet o' Fish", 4.99, 2);
    restaurantsVector[0].addMenuItem("Chicken Nuggets", 3.00, 3);


    //update the list view in the manage restaurants page
    ui->restaurantListWidget->addItem(restaurantsVector[0].getName());

    //update the menu view, not currently linked with the index of the restaurant list
    for(int i = 0; i < restaurantsVector[0].getMenuSize(); i++)
    ui->menuListWidget->addItem(restaurantsVector[0].menu[i].itemName);
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

    //clear entered username and password from line edit
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

void MainWindow::on_actionLogout_triggered()
{
    //initialize all the pages to the first page
    ui->primaryPageStackedWidget->setCurrentIndex(0);
    ui->loginStackedWidget->setCurrentIndex(0);
    ui->MWStackedWidget->setCurrentIndex(0);
    ui->FStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_MWManageRestaurantsButton_clicked()
{
    //go to manage restaurants page
    ui->MWStackedWidget->setCurrentIndex(3);
}



void MainWindow::on_MWManageBackButton_clicked()
{
    //return to main page of maintenance worker
    ui->primaryPageStackedWidget->setCurrentIndex(2);
    ui->MWStackedWidget->setCurrentIndex(0);
}
