#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QString"
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readRestaurantFile();

    //initialize all the pages to the first page
    ui->primaryPageStackedWidget->setCurrentIndex(0);
    ui->loginStackedWidget->setCurrentIndex(0);
    ui->MWStackedWidget->setCurrentIndex(0);
    ui->FStackedWidget->setCurrentIndex(0);
    ui->addRestaurantStackedWidget->setCurrentIndex(0);
    ui->addMenuItemStackedWidget->setCurrentIndex(0);

    ui->TakeTripStackedWidget->setCurrentIndex(0);

    //allows users to move items around in the custom trip list
    ui->customEditRestaurantListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->customEditRestaurantListWidget->setDragEnabled(true);
    ui->customEditRestaurantListWidget->setDragDropMode(QAbstractItemView::InternalMove);
    ui->customEditRestaurantListWidget->viewport()->setAcceptDrops(true);
    ui->customEditRestaurantListWidget->setDropIndicatorShown(true);



//    myTrips.push_back(trip("Mac Man"));
//    myTrips[0].addLocation(restaurantsVector[0]);
//    myTrips[0].addLocation(restaurantsVector[1]);
//    myTrips[0].addLocation(restaurantsVector[2]);

//    myTrips.push_back(trip("Wendy Woman"));
//    myTrips[1].addLocation(restaurantsVector[1]);
//    myTrips[1].addLocation(restaurantsVector[0]);
//    myTrips[1].addLocation(restaurantsVector[2]);

//    myTrips.push_back(trip("Dog Dude"));
//    myTrips[2].addLocation(restaurantsVector[2]);
//    myTrips[2].addLocation(restaurantsVector[1]);
//    myTrips[2].addLocation(restaurantsVector[0]);

//    for(int i  = 0; i < myTrips.size();i++)
//        ui->myTripsListWidget->addItem(myTrips[i].getName());


    //update the list view in the manage restaurants page
    for(int i = 0; i < restaurantsVector.size(); i++)
    ui->manageRestaurantListWidget->addItem(restaurantsVector[i].getName());



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

//************************************************************************
// MY TRIPS AND MENU FUNCTIONS
//************************************************************************
void MainWindow::on_MWMyTripsButton_clicked()
{
    //go to manage restaurants page
    ui->MWStackedWidget->setCurrentIndex(2);
}

void MainWindow::on_MWMyTripsBackButton_clicked()
{
    //go back to the main menu
    ui->primaryPageStackedWidget->setCurrentIndex(2);
    ui->MWStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_myTripsListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->myTripsListWidget->isPersistentEditorOpen(previous))
    {
        //close any editors and update the vector with the new name of restaurant
        ui->myTripsListWidget->closePersistentEditor(previous);
        myTrips[previous->listWidget()->row(previous)].changeName(previous->text());
    }

    ui->myTripsLocationListWidget->clear();

    for(int i = 0; i < myTrips[ui->myTripsListWidget->currentRow()].getTripSize(); i++){
        ui->myTripsLocationListWidget->addItem(myTrips[ui->myTripsListWidget->currentRow()].getLocation(i).getName());
    }
}

void MainWindow::on_myTripsListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //if a trip name is double clicked, it allows user to edit the name directly
    ui->myTripsListWidget->openPersistentEditor(item);
}

//************************************************************************
// MANAGE RESTAURANTS AND MENUS FUNCTIONS
//************************************************************************
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

void MainWindow::on_manageRestaurantListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //if a restaurant name is double clicked, it allows user to edit the name directly
    ui->manageRestaurantListWidget->openPersistentEditor(item);
}


void MainWindow::on_manageRestaurantListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    //solve bug where program is crashign when changing row on restaurant list widget
    //close persistent editor and update vector with whatever is edited
    if(ui->manageMenuListWidget->isPersistentEditorOpen(ui->manageMenuListWidget->currentItem()))
    {
        ui->manageMenuListWidget->closePersistentEditor(ui->manageMenuListWidget->currentItem());
        restaurantsVector[previous->listWidget()->row(previous)].menu[ui->manageMenuListWidget->currentRow()].itemName = ui->manageMenuListWidget->currentItem()->text();
    }

    //solve bug where program is crashign when changing row on restaurant list widget
    //close persistent editor and update vector with whatever is edited
    if(ui->manageMenuPriceListWidget->isPersistentEditorOpen(ui->manageMenuPriceListWidget->currentItem()))
    {
        ui->manageMenuPriceListWidget->closePersistentEditor(ui->manageMenuPriceListWidget->currentItem());
        restaurantsVector[previous->listWidget()->row(previous)].menu[ui->manageMenuPriceListWidget->currentRow()].price = ui->manageMenuPriceListWidget->currentItem()->text().toFloat();
    }


    if(ui->manageRestaurantListWidget->isPersistentEditorOpen(previous))
    {
        //close any editors and update the vector with the new name of restaurant
        ui->manageRestaurantListWidget->closePersistentEditor(previous);
        restaurantsVector[previous->listWidget()->row(previous)].changeName(previous->text());
    }


    //update the menu list when a new restaurant is selected
    ui->manageMenuListWidget->clear();
    ui->manageMenuPriceListWidget->clear();

    for(int i = 0; i < restaurantsVector[ui->manageRestaurantListWidget->currentRow()].getMenuSize(); i++){
        ui->manageMenuListWidget->addItem(restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu[i].itemName);
        ui->manageMenuPriceListWidget->addItem(QString::number(restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu[i].price));
    }

}

void MainWindow::on_deleteRestaurantButton_clicked()
{
    //program currently crashing if all items are removed from list
    if(ui->manageRestaurantListWidget->currentItem() != nullptr)
    {
        int index = ui->manageRestaurantListWidget->currentRow();
        ui->manageRestaurantListWidget->takeItem(index);
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
        ui->manageRestaurantListWidget->addItem(restaurantsVector[restaurantsVector.size() - 1].getName());
    }
    ui->newRestaurantNameLineEdit->clear();
    ui->addRestaurantStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_manageMenuListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //allow editing of the item name if double clicked
    ui->manageMenuListWidget->openPersistentEditor(item);
}


void MainWindow::on_manageMenuPriceListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //allow editing of the item price if double clicked
    ui->manageMenuPriceListWidget->openPersistentEditor(item);
}


//**** 2 FOLLOWING FUNCTION ARE WIP
//closes the editor if the selected item is changed in the menu list
void MainWindow::on_manageMenuListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->manageMenuListWidget->isPersistentEditorOpen(previous))
    {
        ui->manageMenuListWidget->closePersistentEditor(previous);
        restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu[ui->manageMenuListWidget->currentRow()].itemName = previous->text();
    }
}

//closes the editor if the selected item is changed in the menu price list
void MainWindow::on_manageMenuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->manageMenuPriceListWidget->isPersistentEditorOpen(previous))
    {
        ui->manageMenuPriceListWidget->closePersistentEditor(previous);
        restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu[ui->manageMenuPriceListWidget->currentRow()].price = previous->text().toFloat();
    }
}

void MainWindow::on_addItemButton_clicked()
{
    //if there is a restaurant selected, we can add an item to the menu
    if(ui->manageRestaurantListWidget->currentItem() != nullptr)
    ui->addMenuItemStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addMenuItemButton_clicked()
{
    if(ui->newMenuItemName->text() != "" && ui->newMenuItemPrice->text() != "")
    {
        restaurantsVector[ui->manageRestaurantListWidget->currentRow()].addMenuItem(ui->newMenuItemName->text(), ui->newMenuItemPrice->text().toFloat(),
                                                                              restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu.size());
        ui->manageMenuListWidget->addItem(ui->newMenuItemName->text());
        ui->manageMenuPriceListWidget->addItem(QString::number(ui->newMenuItemPrice->text().toFloat()));
    }

    //clear line edits once finished with them
    ui->newMenuItemName->clear();
    ui->newMenuItemPrice->clear();

    //hide the add item overlay
    ui->addMenuItemStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_deleteItemButton_clicked()
{
    //deletes the item selected on the manageMenuListWidget (not the price widget)
    if(ui->manageMenuListWidget->currentItem() != nullptr)
    {
        //remove items from lists
        int index = ui->manageMenuListWidget->currentRow();
        ui->manageMenuListWidget->takeItem(index);
        ui->manageMenuPriceListWidget->takeItem(index);

        //remove items from data structure
        restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu.remove(index);
    }
}
//***************************************************************************************************************************
// TAKING TRIPS FUNCTIONS
//***************************************************************************************************************************

void MainWindow::on_MWTakeTripButton_clicked()
{
    //update the list view in the manage restaurants page
    for(int i = 0; i < restaurantsVector.size(); i++)
    {
        ui->customSelectRestaurantListWidget->addItem(restaurantsVector[i].getName());

        ui->customSelectRestaurantListWidget->item(i)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        ui->customSelectRestaurantListWidget->item(i)->setCheckState(Qt::Unchecked);
    }

    ui->MWStackedWidget->setCurrentIndex(1);
}


//if a restaurant is checked, it gets moved to the second list widget where the user
//is able to drag the items around into their desired order

//if the state of an item changes in the restaurant selection checklist
void MainWindow::on_customSelectRestaurantListWidget_itemChanged(QListWidgetItem *item)
{
    //if item is checked it adds it to the secondary list
    if(item->checkState() == 2)
    {
        ui->customEditRestaurantListWidget->addItem(item->text());

        //ui->customEditRestaurantListWidget->item(ui->customEditRestaurantListWidget->count() - 1)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);

        QTextStream(stdout) <<  ui->customEditRestaurantListWidget->item(ui->customEditRestaurantListWidget->count() - 1)->text()  << ui->customEditRestaurantListWidget->dragDropMode() << endl;

    }
    else if (item->checkState() == 0) //if item is unchecked
    {
        //perform search for the item to be removed
        int i = 0;
        bool found = false;

        while(!found && i < ui->customEditRestaurantListWidget->count())
        {
            if(item->text() == ui->customEditRestaurantListWidget->item(i)->text())
            {
                found = true;
            }
            else
            {
                ++i;
            }
        }
        ui->customEditRestaurantListWidget->takeItem(i);
    }
}



void MainWindow::on_customTakeTripButton_clicked()
{
    //change screen to the trip page
    ui->TakeTripStackedWidget->setCurrentIndex(3);


    //fill up the currentrip queue with the items in the user-ordered restaurant list
    int count;
    bool found = false;

    for(int i = 0; i < ui->customEditRestaurantListWidget->count(); i++)
    {
        count = 0;
        found = false;
        //must perform search to add the correct restaurants to the queue
        while(!found && count < restaurantsVector.size())
        {
            if(ui->customEditRestaurantListWidget->item(i)->text() == restaurantsVector[count].getName())
            {
                //when the names match, add the restaurant to the current trip
                currentTrip.enqueue(restaurantsVector[count]);
                found = true;
            }
            else
            {
                ++count;
            }
        }
    }
}


bool MainWindow::null(int index)
{
    //perform sequential search on nullified vector
    bool found = false;
    for(int i = 0; i < nullifiedLocations.size(); i++)
    {
        if(index == nullifiedLocations[i])
        {
            found = true;
        }
    }
    return found;
}

//returns the column corresponding to the shortest distance
int MainWindow::findShortestDistance(int row)
{

    int index = 0;
    float minimumDistance =  distanceMatrix[row][0];

    for(int column = 1; column < 11; column++)
    {
        if(minimumDistance > distanceMatrix[row][column])
        {
            //new minimum distance
            minimumDistance = distanceMatrix[row][column];
            index = column;
        }
    }

    return index;
}

//SHORTEST PATH ALGORITHM GOES HERE
void MainWindow::on_shortestPathButton_clicked()
{   

    //**********************************************************************************************
    //* FIND THE RESTAURANTS THAT NEED TO BE VISITED AND UN-NULLIFY THEM
    //**********************************************************************************************


    for(int i = 0; i < 11; i++)
    {
        nullifiedLocations.push_back(i);
    }

    int count;
    bool found;
    //activate locations by iterating through editrestaurantlistwidget
    for(int i = 0; i < ui->customEditRestaurantListWidget->count(); i++)
    {
        //find index of the item in the list widget, and pop that from nullifiedlocations vector
        count = 0;
        found = false;
        //must perform search to add the correct restaurants to the queue
        while(!found && count < restaurantsVector.size())
        {


            if(ui->customEditRestaurantListWidget->item(i)->text() == restaurantsVector[count].getName())
            {
                //when the names match, remove the index from the nullifiedlocations vector
                nullifiedLocations.remove(count);
                found = true;
            }
            else
            {
                ++count;
            }
        }
    }

    //QTextStream(stdout) << "created nullifiedlocations vector" << endl;


    //**********************************************************************************************
    //* FILL MATRIX WITH ALL DISTANCES
    //**********************************************************************************************

    //fill 2d array with distances
    //insert all distances into the 2d matrix

    //***** CHANGE THIS .SIZE ***
    for(int i = 0; i < restaurantsVector.size(); i++)
    {
        //fill matrix
        for(int j = 0; j < restaurantsVector.size(); j++)
        {
            //test that the matrix has been filled properly
            if(!null(i) && !null(j))
            {
                QTextStream(stdout) << "created nullifiedlocations vector" << endl;
                distanceMatrix[i][j] = restaurantsVector[j].getDistance(i);
                QTextStream(stdout) << distanceMatrix[i][j] << endl;
            }
        }
    }

    //**********************************************************************************************
    //* RUN SHORTEST PATH ALGORITHM ON NON-NULL RESTAURANTS
    //**********************************************************************************************

    //begin at saddleback 0,0
    //search row for smallest distance
    //after finding smallest distance, travel to the columnth row
    //nullify columnth column

    ui->customEditRestaurantListWidget->clear();

    //initialize row and column to starting positions, default to saddleback
    int row = 0;
    ui->customEditRestaurantListWidget->addItem(restaurantsVector[row].getName());
    nullifiedLocations.push_back(row);

    while(nullifiedLocations.size() < restaurantsVector.size())
    {
        row = findShortestDistance(row);
        ui->customEditRestaurantListWidget->addItem(restaurantsVector[row].getName());
        nullifiedLocations.push_back(row);

    }
}

void MainWindow::readRestaurantFile(){

    QString myfile = "/home/anthony/Scrum-Team-6---Fast-Food-App-master/Quick_Eats/data.txt";
    QFile file(myfile);

    QString tempRest;
    QVector<item> tempMenu;
    QString tempItem;
    float tempPrice = 0;
    int tempId = 0;
    int menuSize = 0;
    QTextStream in(&file);
    QString line;
    int newDistanceSize;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    else{
        line = in.readLine();
        newDistanceSize = line.toInt();

        float tempDistance[13] = {0};
        while(!in.atEnd()){
            line = in.readLine();
            tempRest = line;
            line = in.readLine();
            tempId = line.toInt();

            for(int i = 0; i < 13; i++){
                line = in.readLine();
                tempDistance[i] = line.toFloat();
            }
            line = in.readLine();
            menuSize = line.toInt();
            for(int j = 0; j < menuSize; j++){
                line = in.readLine();
                tempItem = line;
                line = in.readLine();
                tempPrice = line.toFloat();
                tempMenu.push_back(item(tempItem, tempPrice, j));
            }
            line = in.readLine();

            if(line.isEmpty()){
                restaurantsVector.push_back(restaurant(tempId, tempRest, newDistanceSize, tempDistance, tempMenu));
                tempMenu.clear();
                tempRest = "";
                tempId = 0;
                for(int i = 0; i < 13; i++){
                    tempDistance[i] = 0;
                }
                menuSize = 0;
                line.clear();
                tempRest.clear();
            }

        }

    }

    file.close();
}

