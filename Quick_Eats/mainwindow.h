#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
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

private:
    Ui::MainWindow *ui;

    //declare vector of restaurants
    QVector<restaurant> restaurantsVector;



};

#endif // MAINWINDOW_H
