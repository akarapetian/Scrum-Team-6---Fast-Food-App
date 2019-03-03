/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogout;
    QWidget *centralWidget;
    QStackedWidget *primaryPageStackedWidget;
    QWidget *welcomePage;
    QLabel *ProgramNameLabel;
    QLabel *descriptionLabel;
    QStackedWidget *loginStackedWidget;
    QWidget *loginButtonPage;
    QPushButton *mainLoginButton;
    QWidget *loginCredentialsPage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *PasswordLabel;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QLabel *label_14;
    QWidget *foodie;
    QStackedWidget *FStackedWidget;
    QWidget *FWelcomePage;
    QLabel *label;
    QWidget *page_2;
    QWidget *maintenanceWorker;
    QStackedWidget *MWStackedWidget;
    QWidget *MWWelcomePage;
    QPushButton *MWTakeTripButton;
    QLabel *label_2;
    QPushButton *MWMyTripsButton;
    QPushButton *MWManageRestaurantsButton;
    QWidget *MWTakeTripPage;
    QLabel *label_3;
    QWidget *MWMyTripsPage;
    QLabel *label_4;
    QWidget *MWManageRestaurantsPage;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *restaurantListWidget;
    QListWidget *menuListWidget;
    QPushButton *MWManageBackButton;
    QMenuBar *menuBar;
    QMenu *menuContact;
    QMenu *menuHelp;
    QMenu *menuLogout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1140, 624);
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        primaryPageStackedWidget = new QStackedWidget(centralWidget);
        primaryPageStackedWidget->setObjectName(QString::fromUtf8("primaryPageStackedWidget"));
        primaryPageStackedWidget->setGeometry(QRect(0, 0, 1131, 561));
        welcomePage = new QWidget();
        welcomePage->setObjectName(QString::fromUtf8("welcomePage"));
        ProgramNameLabel = new QLabel(welcomePage);
        ProgramNameLabel->setObjectName(QString::fromUtf8("ProgramNameLabel"));
        ProgramNameLabel->setGeometry(QRect(480, 120, 81, 17));
        descriptionLabel = new QLabel(welcomePage);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(380, 160, 301, 17));
        loginStackedWidget = new QStackedWidget(welcomePage);
        loginStackedWidget->setObjectName(QString::fromUtf8("loginStackedWidget"));
        loginStackedWidget->setGeometry(QRect(350, 200, 361, 121));
        loginButtonPage = new QWidget();
        loginButtonPage->setObjectName(QString::fromUtf8("loginButtonPage"));
        mainLoginButton = new QPushButton(loginButtonPage);
        mainLoginButton->setObjectName(QString::fromUtf8("mainLoginButton"));
        mainLoginButton->setGeometry(QRect(20, 30, 311, 61));
        loginStackedWidget->addWidget(loginButtonPage);
        loginCredentialsPage = new QWidget();
        loginCredentialsPage->setObjectName(QString::fromUtf8("loginCredentialsPage"));
        layoutWidget = new QWidget(loginCredentialsPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 10, 291, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        horizontalLayout_2->addWidget(usernameLabel);

        usernameLineEdit = new QLineEdit(layoutWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        horizontalLayout_2->addWidget(usernameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PasswordLabel = new QLabel(layoutWidget);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));

        horizontalLayout->addWidget(PasswordLabel);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        horizontalLayout->addWidget(passwordLineEdit);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_2->addWidget(loginButton);

        loginStackedWidget->addWidget(loginCredentialsPage);
        label_14 = new QLabel(welcomePage);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(420, 380, 301, 20));
        primaryPageStackedWidget->addWidget(welcomePage);
        foodie = new QWidget();
        foodie->setObjectName(QString::fromUtf8("foodie"));
        FStackedWidget = new QStackedWidget(foodie);
        FStackedWidget->setObjectName(QString::fromUtf8("FStackedWidget"));
        FStackedWidget->setGeometry(QRect(0, 10, 1121, 541));
        FWelcomePage = new QWidget();
        FWelcomePage->setObjectName(QString::fromUtf8("FWelcomePage"));
        label = new QLabel(FWelcomePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 170, 171, 17));
        FStackedWidget->addWidget(FWelcomePage);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        FStackedWidget->addWidget(page_2);
        primaryPageStackedWidget->addWidget(foodie);
        maintenanceWorker = new QWidget();
        maintenanceWorker->setObjectName(QString::fromUtf8("maintenanceWorker"));
        MWStackedWidget = new QStackedWidget(maintenanceWorker);
        MWStackedWidget->setObjectName(QString::fromUtf8("MWStackedWidget"));
        MWStackedWidget->setGeometry(QRect(10, 10, 1101, 541));
        MWWelcomePage = new QWidget();
        MWWelcomePage->setObjectName(QString::fromUtf8("MWWelcomePage"));
        MWTakeTripButton = new QPushButton(MWWelcomePage);
        MWTakeTripButton->setObjectName(QString::fromUtf8("MWTakeTripButton"));
        MWTakeTripButton->setGeometry(QRect(20, 410, 321, 81));
        label_2 = new QLabel(MWWelcomePage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 50, 211, 17));
        MWMyTripsButton = new QPushButton(MWWelcomePage);
        MWMyTripsButton->setObjectName(QString::fromUtf8("MWMyTripsButton"));
        MWMyTripsButton->setGeometry(QRect(380, 410, 321, 81));
        MWManageRestaurantsButton = new QPushButton(MWWelcomePage);
        MWManageRestaurantsButton->setObjectName(QString::fromUtf8("MWManageRestaurantsButton"));
        MWManageRestaurantsButton->setGeometry(QRect(760, 410, 321, 81));
        MWStackedWidget->addWidget(MWWelcomePage);
        MWTakeTripPage = new QWidget();
        MWTakeTripPage->setObjectName(QString::fromUtf8("MWTakeTripPage"));
        label_3 = new QLabel(MWTakeTripPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 80, 191, 17));
        MWStackedWidget->addWidget(MWTakeTripPage);
        MWMyTripsPage = new QWidget();
        MWMyTripsPage->setObjectName(QString::fromUtf8("MWMyTripsPage"));
        label_4 = new QLabel(MWMyTripsPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 60, 171, 17));
        MWStackedWidget->addWidget(MWMyTripsPage);
        MWManageRestaurantsPage = new QWidget();
        MWManageRestaurantsPage->setObjectName(QString::fromUtf8("MWManageRestaurantsPage"));
        label_5 = new QLabel(MWManageRestaurantsPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(430, 20, 181, 17));
        label_6 = new QLabel(MWManageRestaurantsPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(240, 70, 141, 17));
        label_7 = new QLabel(MWManageRestaurantsPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(900, 60, 67, 17));
        layoutWidget1 = new QWidget(MWManageRestaurantsPage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 370, 256, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        restaurantListWidget = new QListWidget(MWManageRestaurantsPage);
        restaurantListWidget->setObjectName(QString::fromUtf8("restaurantListWidget"));
        restaurantListWidget->setGeometry(QRect(40, 100, 711, 221));
        menuListWidget = new QListWidget(MWManageRestaurantsPage);
        menuListWidget->setObjectName(QString::fromUtf8("menuListWidget"));
        menuListWidget->setGeometry(QRect(800, 100, 261, 261));
        MWManageBackButton = new QPushButton(MWManageRestaurantsPage);
        MWManageBackButton->setObjectName(QString::fromUtf8("MWManageBackButton"));
        MWManageBackButton->setGeometry(QRect(40, 20, 89, 25));
        MWStackedWidget->addWidget(MWManageRestaurantsPage);
        primaryPageStackedWidget->addWidget(maintenanceWorker);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1140, 22));
        menuContact = new QMenu(menuBar);
        menuContact->setObjectName(QString::fromUtf8("menuContact"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuLogout = new QMenu(menuBar);
        menuLogout->setObjectName(QString::fromUtf8("menuLogout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuContact->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLogout->menuAction());
        menuLogout->addAction(actionLogout);

        retranslateUi(MainWindow);

        primaryPageStackedWidget->setCurrentIndex(2);
        loginStackedWidget->setCurrentIndex(0);
        FStackedWidget->setCurrentIndex(0);
        MWStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", nullptr));
        ProgramNameLabel->setText(QApplication::translate("MainWindow", "Quick Eats", nullptr));
        descriptionLabel->setText(QApplication::translate("MainWindow", "Bringing you to your favorite food quickly.", nullptr));
        mainLoginButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        usernameLabel->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        PasswordLabel->setText(QApplication::translate("MainWindow", "Password:", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "temp username/password: foodie or MW", nullptr));
        label->setText(QApplication::translate("MainWindow", "welcome hungry person", nullptr));
        MWTakeTripButton->setText(QApplication::translate("MainWindow", "Take a Trip", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "welcome maintenance worker", nullptr));
        MWMyTripsButton->setText(QApplication::translate("MainWindow", "My Trips", nullptr));
        MWManageRestaurantsButton->setText(QApplication::translate("MainWindow", "Manage Restaurants", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "take a trip", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "your trips here", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "manage restaurants", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "list of restaurants", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "menu", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Add Restaurant", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Delete Restaurant", nullptr));
        MWManageBackButton->setText(QApplication::translate("MainWindow", "Back", nullptr));
        menuContact->setTitle(QApplication::translate("MainWindow", "Contact", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuLogout->setTitle(QApplication::translate("MainWindow", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
