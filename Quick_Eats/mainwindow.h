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
    void readRestaurantFile();

    //LOGIN FUNCTIONS
    void on_mainLoginButton_clicked();
    void on_loginButton_clicked();
    void on_actionLogout_triggered();

    //MY TRIPS FUNCTIONS
    void on_MWMyTripsButton_clicked();
    void on_MWMyTripsBackButton_clicked();
    void on_myTripsListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_myTripsListWidget_itemDoubleClicked(QListWidgetItem *item);

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



    void on_MWTakeTripButton_clicked();

    void on_customSelectRestaurantListWidget_itemChanged(QListWidgetItem *item);

    void on_customTakeTripButton_clicked();

    void on_shortestPathButton_clicked();


    //SHORTEST PATH FUNCTIONS
    /*
    bool null(int index); //returns true if the index has been nullified within nullifiedLocations vector
      */


    void optimizePath(int j, int n); //searches a row for the shortest distance and returns the column
    bool validIndex(int i); //returns true if the index is alright to be operated on

private:
    Ui::MainWindow *ui;

    //declare vector of restaurants
    QVector<restaurant> restaurantsVector;

    //queue that represents the trip the user is currently taking
    QQueue<restaurant> currentTrip;

    //this data structure holds all the custom trips that belong to a user
    //it is a vector of pointers, each pointing to a Queue of restaurants (the custom trip).
    QVector<QQueue<restaurant>*> customTrips;

    //this is an object, that holds a queue of vectors. Only made it so I could tie a name to a queue
    trip myTrip;

    //vector of pointers, each pointing to a trip
    QVector<trip> myTrips;

    //shortest path algorithm variables

    //create matrix of distances
    //(two dimensional array of floats)
    //will contain 11 rows and columns, because there are 10 locations + saddleback is the number of restaurants in the editRestaurantListWidget
    QVector<QVector<float>> distanceMatrix;
    //array of restaurant id's that are no longer of use to the algorithm
    QVector<int> nullifiedIndexes;
    //these elements may have already been visted, or were not added to the list at all


};

#endif // MAINWINDOW_H
