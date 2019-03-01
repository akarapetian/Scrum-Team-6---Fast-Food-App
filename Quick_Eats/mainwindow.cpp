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
    ui->addRestaurantStackedWidget->setCurrentIndex(0);
    ui->addMenuItemStackedWidget->setCurrentIndex(0);


    int tempDistances[1] = {0};
    QVector<item> tempMenu;

    //CALL PARSER HERE
    restaurantsVector.push_back(restaurant(1, "McDonalds", 1, tempDistances, tempMenu));
    restaurantsVector[0].addMenuItem("Big Mac", 5.99, 1);
    restaurantsVector[0].addMenuItem("Fillet o' Fish", 4.99, 2);
    restaurantsVector[0].addMenuItem("Chicken Nuggets", 3.00, 3);

    restaurantsVector.push_back(restaurant(2, "Wendys", 1, tempDistances, tempMenu));
    restaurantsVector[1].addMenuItem("Burger", 3.99, 1);
    restaurantsVector[1].addMenuItem("Salad", 2.99, 2);
    restaurantsVector[1].addMenuItem("Nuggets", 7.00, 3);


    //update the list view in the manage restaurants page
    for(int i = 0; i < restaurantsVector.size(); i++)
    ui->restaurantListWidget->addItem(restaurantsVector[i].getName());


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

void MainWindow::on_restaurantListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //if a restaurant name is double clicked, it allows user to edit the name directly
    ui->restaurantListWidget->openPersistentEditor(item);
}


void MainWindow::on_restaurantListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->restaurantListWidget->isPersistentEditorOpen(previous))
    {
        //close any editors and update the vector with the new name of restaurant
        ui->restaurantListWidget->closePersistentEditor(previous);
        restaurantsVector[previous->listWidget()->row(previous)].changeName(previous->text());
    }


    //update the menu list when a new restaurant is selected
    ui->menuListWidget->clear();
    ui->menuPriceListWidget->clear();

    for(int i = 0; i < restaurantsVector[ui->restaurantListWidget->currentRow()].getMenuSize(); i++){
        ui->menuListWidget->addItem(restaurantsVector[ui->restaurantListWidget->currentRow()].menu[i].itemName);
        ui->menuPriceListWidget->addItem(QString::number(restaurantsVector[ui->restaurantListWidget->currentRow()].menu[i].price));
    }

}

void MainWindow::on_deleteRestaurantButton_clicked()
{
    //program currently crashing if all items are removed from list
    if(ui->restaurantListWidget->currentItem() != nullptr)
    {
        int index = ui->restaurantListWidget->currentRow();
        ui->restaurantListWidget->takeItem(index);
        restaurantsVector.remove(index);
    }
}

void MainWindow::on_addRestaurantButton_clicked()
{
    ui->addRestaurantStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addButton_clicked()
{
    if(ui->newRestaurantNameLineEdit->text() != "")
    {
        QVector<item> newMenu;
        restaurantsVector.push_back(restaurant(restaurantsVector.size(), ui->newRestaurantNameLineEdit->text(), 0, nullptr, newMenu));
        ui->restaurantListWidget->addItem(restaurantsVector[restaurantsVector.size() - 1].getName());
    }
    ui->newRestaurantNameLineEdit->clear();
    ui->addRestaurantStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_menuListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //allow editing of the item name if double clicked
    ui->menuListWidget->openPersistentEditor(item);
}


void MainWindow::on_menuPriceListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //allow editing of the item price if double clicked
    ui->menuPriceListWidget->openPersistentEditor(item);
}


//**** 2 FOLLOWING FUNCTION ARE WIP
//closes the editor if the selected item is changed in the menu list
void MainWindow::on_menuListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->menuListWidget->isPersistentEditorOpen(previous))
    {
        ui->menuListWidget->closePersistentEditor(previous);
        restaurantsVector[ui->restaurantListWidget->currentRow()].menu[ui->menuListWidget->currentRow()].itemName = previous->text();
    }
}

//closes the editor if the selected item is changed in the menu price list
void MainWindow::on_menuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->menuPriceListWidget->isPersistentEditorOpen(previous))
    {
        ui->menuPriceListWidget->closePersistentEditor(previous);
        restaurantsVector[ui->restaurantListWidget->currentRow()].menu[ui->menuPriceListWidget->currentRow()].price = previous->text().toFloat();
    }
}

void MainWindow::on_addItemButton_clicked()
{
    //if there is a restaurant selected, we can add an item to the menu
    if(ui->restaurantListWidget->currentItem() != nullptr)
    ui->addMenuItemStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addMenuItemButton_clicked()
{
    if(ui->newMenuItemName->text() != "" && ui->newMenuItemPrice->text() != "")
    {
        restaurantsVector[ui->restaurantListWidget->currentRow()].addMenuItem(ui->newMenuItemName->text(), ui->newMenuItemPrice->text().toFloat(),
                                                                              restaurantsVector[ui->restaurantListWidget->currentRow()].menu.size());
        ui->menuListWidget->addItem(ui->newMenuItemName->text());
        ui->menuPriceListWidget->addItem(QString::number(ui->newMenuItemPrice->text().toFloat()));
    }

    //clear line edits once finished with them
    ui->newMenuItemName->clear();
    ui->newMenuItemPrice->clear();

    //hide the add item overlay
    ui->addMenuItemStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_deleteItemButton_clicked()
{
    //deletes the item selected on the menulistwidget (not the price widget)
    if(ui->menuListWidget->currentItem() != nullptr)
    {
        //remove items from lists
        int index = ui->menuListWidget->currentRow();
        ui->menuListWidget->takeItem(index);
        ui->menuPriceListWidget->takeItem(index);

        //remove items from data structure
        restaurantsVector[ui->restaurantListWidget->currentRow()].menu.remove(index);
    }
}
