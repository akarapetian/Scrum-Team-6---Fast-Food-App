#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QQueue>
#include <QFile>
#include <QString>
#include <QListWidget>
#include <QMessageBox>
#include "restaurant.h"
#include "trip.h"
#include "doublehash.h"

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
    //void readRestaurantFile(QVector<restaurant>&);
    void writeRestaurantFile();
    void readRestaurantFile(QString filePath);

    //LOGIN FUNCTIONS
    void on_mainLoginButton_clicked();
    void on_loginButton_clicked();
    void on_actionLogout_triggered();

    //MANAGE RESTAURANTS FUNCTIONS
    void on_MWManageRestaurantsButton_clicked();
    void on_MWManageBackButton_clicked();
    void on_manageRestaurantListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_deleteRestaurantButton_clicked();
    bool validDeletedIndex(int i); //returns true if the index is NOT deleted
    void on_manageRestaurantListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_addRestaurantButton_clicked();
    bool isFloatNumber(const QString& Qstring);
    void on_addItemButton_clicked();
    void on_manageMenuListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_manageMenuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_addMenuItemButton_clicked();
    void on_manageMenuListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_manageMenuPriceListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_deleteItemButton_clicked();
    void on_manageRestaurantDistanceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    //Creating trip functions
    void on_MWTakeTripButton_clicked();
    void on_customSelectRestaurantListWidget_itemChanged(QListWidgetItem *item);
    void on_customTakeTripButton_clicked();
    void on_shortestPathButton_clicked();

    //taking trip functions
    void nextRestaurant();
    float getSubTotal();

    //SHORTEST PATH FUNCTIONS

    void optimizePath(int j, int n); //searches a row for the shortest distance and returns the column
    bool validIndex(int i); //returns true if the index is alright to be operated on


    //visiting restaurant functions
    void on_currentLocationMenuItemListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_myOrderQuantityListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_currentLocationMenuItemListWidget_itemChanged(QListWidgetItem *item);
    void on_checkOutButton_clicked();
    void on_pathPageBackButton_clicked();
    void on_continueButton_clicked();
    void on_endTripButton_clicked();

    void on_FTakeTripButton_clicked();

    void on_FViewRestaurantsButton_clicked();


    void on_FviewRestaurantsBackButton_clicked();

    void on_foodieRestaurantListWidget_currentRowChanged(int currentRow);

    void on_foodieRestaurantDistanceListWidget_currentRowChanged(int currentRow);

    void on_foodieMenuListWidget_currentRowChanged(int currentRow);

    void on_foodieMenuPriceListWidget_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;

    //declare vector of restaurants
    QVector<restaurant> restaurantsVector;

    QPixmap icons[13]; //stores restaurant icons

    bool restaurantsAdded; //returns true if additional restaurants have been read in

    //queue that represents the trip the user is currently taking
    trip currentTrip;



    //shortest path algorithm variables

    //create matrix of distances
    //(two dimensional array of floats)
    //will contain 11 rows and columns, because there are 10 locations + saddleback is the number of restaurants in the editRestaurantListWidget
    QVector<QVector<float>> distanceMatrix;
    //array of restaurant id's that are no longer of use to the algorithm
    QVector<int> nullifiedIndexes;
    //these elements may have already been visted, or were not added to the list at all

    //indexes of deleted restaurants
    QVector<int> deletedIndexes;

    //0 mean not logged in, 1 is foodie, 2 is Maintenance Worker
    int currentMode;

};

#endif // MAINWINDOW_H
