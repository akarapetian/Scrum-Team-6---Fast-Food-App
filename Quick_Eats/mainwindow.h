#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QQueue>
#include <QListWidget>
#include "restaurant.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //LOGIN FUNCTIONS
    void on_mainLoginButton_clicked();
    void on_loginButton_clicked();
    void on_actionLogout_triggered();

    //MANAGE RESTAURANTS FUNCTIONS
    void on_MWManageRestaurantsButton_clicked();
    void on_MWManageBackButton_clicked();
    void on_manageRestaurantListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_deleteRestaurantButton_clicked();
    void on_manageRestaurantListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_addButton_clicked();
    void on_addRestaurantButton_clicked();
    void on_addItemButton_clicked();
    void on_manageMenuListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_manageMenuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_addMenuItemButton_clicked();
    void on_manageMenuListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_manageMenuPriceListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_deleteItemButton_clicked();



    void on_customPathButton_clicked();

    void on_shortestPathButton_clicked();


    void on_MWTakeTripButton_clicked();

    void on_customSelectRestaurantListWidget_itemChanged(QListWidgetItem *item);

    void on_customTakeTripButton_clicked();

private:
    Ui::MainWindow *ui;

    //declare vector of restaurants
    QVector<restaurant> restaurantsVector;

    //queue that represents the trip the user is currently taking
    QQueue<restaurant> currentTrip;

    //this data structure holds all the custom trips that belong to a user
    //it is a vector of pointers, each pointing to a Queue of restaurants (the custom trip).
    QVector<QQueue<restaurant>*> customTrips;
};

#endif // MAINWINDOW_H
