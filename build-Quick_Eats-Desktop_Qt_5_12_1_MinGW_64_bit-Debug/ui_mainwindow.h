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
    QStackedWidget *TakeTripStackedWidget;
    QWidget *determineTripTypePage;
    QLabel *header;
    QPushButton *customPathButton;
    QPushButton *shortestPathButton;
    QWidget *customPathPage;
    QLabel *label_3;
    QListWidget *customSelectRestaurantListWidget;
    QListWidget *customEditRestaurantListWidget;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *customTakeTripButton;
    QWidget *shortestPathPage;
    QLabel *label_17;
    QWidget *tripPage;
    QLabel *label_13;
    QWidget *MWMyTripsPage;
    QLabel *label_4;
    QListWidget *myTripsListWidget;
    QListWidget *myTripsLocationListWidget;
    QLabel *label_12;
    QLabel *label_18;
    QPushButton *myTripsDeleteButton;
    QPushButton *MWMyTripsBackButton;
    QPushButton *myTripsAddButton;
    QWidget *MWManageRestaurantsPage;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addRestaurantButton;
    QPushButton *deleteRestaurantButton;
    QListWidget *manageRestaurantListWidget;
    QListWidget *manageMenuListWidget;
    QPushButton *MWManageBackButton;
    QStackedWidget *addRestaurantStackedWidget;
    QWidget *hiddenPage;
    QWidget *editPage;
    QLabel *label_8;
    QPushButton *addButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *newRestaurantNameLineEdit;
    QListWidget *manageMenuPriceListWidget;
    QStackedWidget *addMenuItemStackedWidget;
    QWidget *hiddenMenuPage;
    QWidget *editMenuPage;
    QPushButton *addMenuItemButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *newMenuItemName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLineEdit *newMenuItemPrice;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addItemButton;
    QPushButton *deleteItemButton;
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
        MWStackedWidget->setGeometry(QRect(10, 10, 1121, 541));
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
        TakeTripStackedWidget = new QStackedWidget(MWTakeTripPage);
        TakeTripStackedWidget->setObjectName(QString::fromUtf8("TakeTripStackedWidget"));
        TakeTripStackedWidget->setGeometry(QRect(20, 10, 1101, 541));
        determineTripTypePage = new QWidget();
        determineTripTypePage->setObjectName(QString::fromUtf8("determineTripTypePage"));
        header = new QLabel(determineTripTypePage);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(290, 50, 461, 17));
        customPathButton = new QPushButton(determineTripTypePage);
        customPathButton->setObjectName(QString::fromUtf8("customPathButton"));
        customPathButton->setGeometry(QRect(130, 180, 321, 151));
        shortestPathButton = new QPushButton(determineTripTypePage);
        shortestPathButton->setObjectName(QString::fromUtf8("shortestPathButton"));
        shortestPathButton->setGeometry(QRect(580, 180, 321, 151));
        TakeTripStackedWidget->addWidget(determineTripTypePage);
        customPathPage = new QWidget();
        customPathPage->setObjectName(QString::fromUtf8("customPathPage"));
        label_3 = new QLabel(customPathPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 30, 211, 17));
        customSelectRestaurantListWidget = new QListWidget(customPathPage);
        customSelectRestaurantListWidget->setObjectName(QString::fromUtf8("customSelectRestaurantListWidget"));
        customSelectRestaurantListWidget->setGeometry(QRect(130, 150, 256, 311));
        customEditRestaurantListWidget = new QListWidget(customPathPage);
        customEditRestaurantListWidget->setObjectName(QString::fromUtf8("customEditRestaurantListWidget"));
        customEditRestaurantListWidget->setGeometry(QRect(490, 150, 256, 311));
        label_15 = new QLabel(customPathPage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(160, 120, 191, 17));
        label_16 = new QLabel(customPathPage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(550, 120, 141, 17));
        customTakeTripButton = new QPushButton(customPathPage);
        customTakeTripButton->setObjectName(QString::fromUtf8("customTakeTripButton"));
        customTakeTripButton->setGeometry(QRect(840, 390, 191, 71));
        TakeTripStackedWidget->addWidget(customPathPage);
        shortestPathPage = new QWidget();
        shortestPathPage->setObjectName(QString::fromUtf8("shortestPathPage"));
        shortestPathPage->setEnabled(true);
        label_17 = new QLabel(shortestPathPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(490, 20, 111, 17));
        TakeTripStackedWidget->addWidget(shortestPathPage);
        tripPage = new QWidget();
        tripPage->setObjectName(QString::fromUtf8("tripPage"));
        label_13 = new QLabel(tripPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(520, 30, 161, 17));
        TakeTripStackedWidget->addWidget(tripPage);
        MWStackedWidget->addWidget(MWTakeTripPage);
        MWMyTripsPage = new QWidget();
        MWMyTripsPage->setObjectName(QString::fromUtf8("MWMyTripsPage"));
        label_4 = new QLabel(MWMyTripsPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 60, 171, 17));
        myTripsListWidget = new QListWidget(MWMyTripsPage);
        myTripsListWidget->setObjectName(QString::fromUtf8("myTripsListWidget"));
        myTripsListWidget->setGeometry(QRect(30, 110, 711, 221));
        myTripsLocationListWidget = new QListWidget(MWMyTripsPage);
        myTripsLocationListWidget->setObjectName(QString::fromUtf8("myTripsLocationListWidget"));
        myTripsLocationListWidget->setGeometry(QRect(800, 110, 161, 261));
        label_12 = new QLabel(MWMyTripsPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(130, 80, 141, 20));
        label_18 = new QLabel(MWMyTripsPage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(856, 80, 71, 20));
        myTripsDeleteButton = new QPushButton(MWMyTripsPage);
        myTripsDeleteButton->setObjectName(QString::fromUtf8("myTripsDeleteButton"));
        myTripsDeleteButton->setGeometry(QRect(630, 350, 111, 23));
        MWMyTripsBackButton = new QPushButton(MWMyTripsPage);
        MWMyTripsBackButton->setObjectName(QString::fromUtf8("MWMyTripsBackButton"));
        MWMyTripsBackButton->setGeometry(QRect(10, 10, 75, 23));
        myTripsAddButton = new QPushButton(MWMyTripsPage);
        myTripsAddButton->setObjectName(QString::fromUtf8("myTripsAddButton"));
        myTripsAddButton->setGeometry(QRect(500, 350, 111, 23));
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
        layoutWidget1->setGeometry(QRect(500, 340, 256, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        addRestaurantButton = new QPushButton(layoutWidget1);
        addRestaurantButton->setObjectName(QString::fromUtf8("addRestaurantButton"));

        horizontalLayout_3->addWidget(addRestaurantButton);

        deleteRestaurantButton = new QPushButton(layoutWidget1);
        deleteRestaurantButton->setObjectName(QString::fromUtf8("deleteRestaurantButton"));

        horizontalLayout_3->addWidget(deleteRestaurantButton);

        manageRestaurantListWidget = new QListWidget(MWManageRestaurantsPage);
        manageRestaurantListWidget->setObjectName(QString::fromUtf8("manageRestaurantListWidget"));
        manageRestaurantListWidget->setGeometry(QRect(40, 100, 711, 221));
        manageMenuListWidget = new QListWidget(MWManageRestaurantsPage);
        manageMenuListWidget->setObjectName(QString::fromUtf8("manageMenuListWidget"));
        manageMenuListWidget->setGeometry(QRect(820, 100, 161, 261));
        MWManageBackButton = new QPushButton(MWManageRestaurantsPage);
        MWManageBackButton->setObjectName(QString::fromUtf8("MWManageBackButton"));
        MWManageBackButton->setGeometry(QRect(40, 20, 89, 25));
        addRestaurantStackedWidget = new QStackedWidget(MWManageRestaurantsPage);
        addRestaurantStackedWidget->setObjectName(QString::fromUtf8("addRestaurantStackedWidget"));
        addRestaurantStackedWidget->setGeometry(QRect(40, 340, 421, 181));
        hiddenPage = new QWidget();
        hiddenPage->setObjectName(QString::fromUtf8("hiddenPage"));
        addRestaurantStackedWidget->addWidget(hiddenPage);
        editPage = new QWidget();
        editPage->setObjectName(QString::fromUtf8("editPage"));
        label_8 = new QLabel(editPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 121, 17));
        addButton = new QPushButton(editPage);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(310, 150, 89, 25));
        layoutWidget2 = new QWidget(editPage);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 50, 192, 27));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        newRestaurantNameLineEdit = new QLineEdit(layoutWidget2);
        newRestaurantNameLineEdit->setObjectName(QString::fromUtf8("newRestaurantNameLineEdit"));

        horizontalLayout_4->addWidget(newRestaurantNameLineEdit);

        addRestaurantStackedWidget->addWidget(editPage);
        manageMenuPriceListWidget = new QListWidget(MWManageRestaurantsPage);
        manageMenuPriceListWidget->setObjectName(QString::fromUtf8("manageMenuPriceListWidget"));
        manageMenuPriceListWidget->setGeometry(QRect(980, 100, 61, 261));
        addMenuItemStackedWidget = new QStackedWidget(MWManageRestaurantsPage);
        addMenuItemStackedWidget->setObjectName(QString::fromUtf8("addMenuItemStackedWidget"));
        addMenuItemStackedWidget->setGeometry(QRect(830, 410, 221, 131));
        hiddenMenuPage = new QWidget();
        hiddenMenuPage->setObjectName(QString::fromUtf8("hiddenMenuPage"));
        addMenuItemStackedWidget->addWidget(hiddenMenuPage);
        editMenuPage = new QWidget();
        editMenuPage->setObjectName(QString::fromUtf8("editMenuPage"));
        addMenuItemButton = new QPushButton(editMenuPage);
        addMenuItemButton->setObjectName(QString::fromUtf8("addMenuItemButton"));
        addMenuItemButton->setGeometry(QRect(120, 90, 89, 25));
        layoutWidget3 = new QWidget(editMenuPage);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 10, 194, 62));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        newMenuItemName = new QLineEdit(layoutWidget3);
        newMenuItemName->setObjectName(QString::fromUtf8("newMenuItemName"));

        horizontalLayout_7->addWidget(newMenuItemName);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_6->addWidget(label_11);

        newMenuItemPrice = new QLineEdit(layoutWidget3);
        newMenuItemPrice->setObjectName(QString::fromUtf8("newMenuItemPrice"));

        horizontalLayout_6->addWidget(newMenuItemPrice);


        verticalLayout_3->addLayout(horizontalLayout_6);

        addMenuItemStackedWidget->addWidget(editMenuPage);
        layoutWidget4 = new QWidget(MWManageRestaurantsPage);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(870, 370, 177, 27));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        addItemButton = new QPushButton(layoutWidget4);
        addItemButton->setObjectName(QString::fromUtf8("addItemButton"));

        horizontalLayout_5->addWidget(addItemButton);

        deleteItemButton = new QPushButton(layoutWidget4);
        deleteItemButton->setObjectName(QString::fromUtf8("deleteItemButton"));

        horizontalLayout_5->addWidget(deleteItemButton);

        MWStackedWidget->addWidget(MWManageRestaurantsPage);
        primaryPageStackedWidget->addWidget(maintenanceWorker);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1140, 21));
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
        FStackedWidget->setCurrentIndex(1);
        MWStackedWidget->setCurrentIndex(2);
        TakeTripStackedWidget->setCurrentIndex(1);
        addRestaurantStackedWidget->setCurrentIndex(0);
        addMenuItemStackedWidget->setCurrentIndex(0);


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
        header->setText(QApplication::translate("MainWindow", "Please Select Which Type of Custom Trip You Would Like to take", nullptr));
        customPathButton->setText(QApplication::translate("MainWindow", "Custom Path", nullptr));
        shortestPathButton->setText(QApplication::translate("MainWindow", "Shortest Path", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "custom path", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Select Restaurants to Visit", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Edit order of visits", nullptr));
        customTakeTripButton->setText(QApplication::translate("MainWindow", "Take Trip", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "shortest path", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "trip", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "My Trips", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "List of Trips", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Locations", nullptr));
        myTripsDeleteButton->setText(QApplication::translate("MainWindow", "Delete Trips", nullptr));
        MWMyTripsBackButton->setText(QApplication::translate("MainWindow", "Back", nullptr));
        myTripsAddButton->setText(QApplication::translate("MainWindow", "Add Trips", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "manage restaurants", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "list of restaurants", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "menu", nullptr));
        addRestaurantButton->setText(QApplication::translate("MainWindow", "Add Restaurant", nullptr));
        deleteRestaurantButton->setText(QApplication::translate("MainWindow", "Delete Restaurant", nullptr));
        MWManageBackButton->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "New Restaurant:", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "add", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "name:", nullptr));
        addMenuItemButton->setText(QApplication::translate("MainWindow", "add", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "name:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "price:", nullptr));
        addItemButton->setText(QApplication::translate("MainWindow", "Add Item", nullptr));
        deleteItemButton->setText(QApplication::translate("MainWindow", "Delete Item", nullptr));
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
