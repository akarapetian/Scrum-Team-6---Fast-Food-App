#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
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
    void on_mainLoginButton_clicked();

    void on_loginButton_clicked();

    void on_MWManageRestaurantsButton_clicked();

    void on_actionLogout_triggered();

    void on_MWManageBackButton_clicked();

    void on_restaurantListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_deleteRestaurantButton_clicked();

    void on_restaurantListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_addButton_clicked();

    void on_addRestaurantButton_clicked();

    void on_addItemButton_clicked();

    void on_menuListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_menuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_addMenuItemButton_clicked();

    void on_menuListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_menuPriceListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_deleteItemButton_clicked();

private:
    Ui::MainWindow *ui;

    //declare vector of restaurants
    QVector<restaurant> restaurantsVector;
};

#endif // MAINWINDOW_H
