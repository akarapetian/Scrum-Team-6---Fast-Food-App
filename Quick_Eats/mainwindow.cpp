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
    writeRestaurantFile();
    delete ui;
}

void MainWindow::writeRestaurantFile(){
    QFile file("/home/anthony/Scrum-Team-6---Fast-Food-App-master/Quick_Eats/data.txt");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    else{

        QTextStream out(&file);

        out << restaurantsVector[0].distance.size() << endl; //the way we have the file reading set up is built in a way such that it reads the size of how many distances per restaurant there are first since that is an independent variable from the rest of the rest. class, so im just taking the distance size of the first element since they are all the same size and placing it
        for(int i = 0; i < restaurantsVector.size(); i++){
            out << restaurantsVector[i].getName() << endl;
            out << restaurantsVector[i].getId() << endl;
            for(int j = 0; j < restaurantsVector[0].getDistanceSize(); j++){
                out << restaurantsVector[i].distance[j] << endl;
            }
            out << restaurantsVector[i].menu.size() << endl;
            for(int j = 0; j < restaurantsVector[i].menu.size(); j++){
                out << restaurantsVector[i].menu[j].itemName << endl;
                out << restaurantsVector[i].menu[j].price << endl;
            }
            out << endl;
        }
    }
}

void MainWindow::readRestaurantFile(){

    QFile file("/home/anthony/Scrum-Team-6---Fast-Food-App-master/Quick_Eats/data.txt");

    QString tempRest;
    QVector<item> tempMenu;
    QString tempItem;
    float tempPrice = 0;
    int tempId = 0;
    int menuSize = 0;
    QTextStream in(&file);
    QString line;
    int newDistanceSize;
    QVector<float> tempDistance;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    else{
        line = in.readLine();
        newDistanceSize = line.toInt();

        while(!in.atEnd()){
            line = in.readLine();
            tempRest = line;
            line = in.readLine();
            tempId = line.toInt();

            for(int i = 0; i < newDistanceSize; i++){
                line = in.readLine();
                tempDistance.push_back(line.toFloat());
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
                restaurantsVector.push_back(restaurant(tempId, tempRest, tempDistance, tempMenu));
                tempMenu.clear();
                tempRest = "";
                tempId = 0;
                for(int i = 0; i < newDistanceSize; i++){
                    tempDistance.clear();
                }
                menuSize = 0;
                line.clear();
                tempRest.clear();
            }
        }
    }
    file.close();
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

//need to go back and make this function parse the second text file
void MainWindow::on_addButton_clicked()
{
    /*
    if(ui->newRestaurantNameLineEdit->text() != "")
    {
        QVector<item> newMenu;
        restaurantsVector.push_back(restaurant(restaurantsVector.size(), ui->newRestaurantNameLineEdit->text(), 0, nullptr, newMenu));
        ui->manageRestaurantListWidget->addItem(restaurantsVector[restaurantsVector.size() - 1].getName());
    }
    ui->newRestaurantNameLineEdit->clear();
    ui->addRestaurantStackedWidget->setCurrentIndex(0);
    */
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
        restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu[previous->listWidget()->row(previous)].itemName = previous->text();
    }
}

//closes the editor if the selected item is changed in the menu price list
void MainWindow::on_manageMenuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->manageMenuPriceListWidget->isPersistentEditorOpen(previous))
    {
        ui->manageMenuPriceListWidget->closePersistentEditor(previous);
        restaurantsVector[ui->manageRestaurantListWidget->currentRow()].menu[previous->listWidget()->row(previous)].price = previous->text().toFloat();
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
    ui->TakeTripStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pathPageBackButton_clicked()
{

    ui->MWStackedWidget->setCurrentIndex(0);
    ui->customSelectRestaurantListWidget->clear();
    ui->customEditRestaurantListWidget->clear();
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


bool MainWindow::validIndex(int i)
{
    bool valid = true;

    //if i exists in a list of nullified indexes, valid = false;
   for(int count = 0; count < nullifiedIndexes.size(); count++)
   {
       if(i == nullifiedIndexes[count])
       {
           valid = false;
       }
   }
    return valid;
}

//recursive version
void MainWindow::optimizePath(int j, int n)
{
    //iterate through the whole row and return the index of the smallest number
    int index = 0;
    float minimumDistance =  100000000;

    for(int i = 0; i < restaurantsVector[0].getDistanceSize(); i++)
    {
        if(minimumDistance > distanceMatrix[j][i] && validIndex(i))
        {
            //new minimum distance
            minimumDistance = distanceMatrix[j][i];
            index = i;
        }
    }

    //add item to listwidget
    ui->customEditRestaurantListWidget->addItem(restaurantsVector[index].getName());
    nullifiedIndexes.push_back(index);

    if(ui->customEditRestaurantListWidget->count() < n)
    {
        optimizePath(index, n);
    }
}

//SHORTEST PATH ALGORITHM GOES HERE
void MainWindow::on_shortestPathButton_clicked()
{    
    //this attempt will try to add all ditances to a matrix, in the findshortestdistance function we will perform a check before returning
    //number of restaurants to be optimized
    int n = ui->customEditRestaurantListWidget->count();
    int k = restaurantsVector[0].getDistanceSize();

    bool found = false;

    int i = 0; //incrementer for iterating through EVERY element in the restaurant list widget
    int j = 0; //incrementer for iterating through restaurant vector until it matches

    //resize each row to be the right length
    distanceMatrix.resize(k);

    //first step is to load the restaurant distances into a 2D vector of distances
    for(i = 0; i < k; i++)
    {
        //fill up nullified indexes with all indexes, used later in code
        nullifiedIndexes.push_back(i);

        //resize each column to be the right height
        distanceMatrix[i].resize(k);
        for(j = 0; j < k; j++)
        {
            distanceMatrix[i][j] = restaurantsVector[i].getDistance(j);
        }
    }
    i = 0;
    j = 0;

    //perform the shortest distance algorithm, re-orders the list widget (or may need to return a queue and begin trip) 
    //aquire starting posistion
    QString startname = ui->customEditRestaurantListWidget->item(0)->text();
    int startingIndex = 0;
    while(!found && i < restaurantsVector.size())
    {
        if(ui->customEditRestaurantListWidget->item(0)->text() == restaurantsVector[i].getName())
        {
            startingIndex = restaurantsVector[i].getId();
            found = true;
        }
        else
        {
            ++i;
        }
    }
    i = 0;
    found = false;

    //UN-nullify restaurants we want to visit
    int count;
    for(i = 0; i < n; i++)
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
                nullifiedIndexes[count] = -1;
                found = true;
            }
            else
            {
                ++count;
            }
        }
    }

    ui->customEditRestaurantListWidget->clear();
    //ui->customEditRestaurantListWidget->addItem(startname);
    //nullifiedIndexes[startingIndex] = -1;

    optimizePath(startingIndex, n);

    nullifiedIndexes.clear();
}


void MainWindow::on_customTakeTripButton_clicked()
{
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
                currentTrip.addLocation(restaurantsVector[count]);
                found = true;
            }
            else
            {
                ++count;
            }
        }
    }

    //change screen to the trip page
    ui->TakeTripStackedWidget->setCurrentIndex(1);

    nextRestaurant();

}

//*************************************************************
//IN THE RESTAURANT METHODS
//*************************************************************

//need to track distances in here
void MainWindow::nextRestaurant()
{

    if(currentTrip.getCurrentLocation().getName() == "Saddleback College")
    {
        //if were at saddleback, frontend looks quite different
        //for now we may just pop saddleback from the queue // ************************************** < needs to get changed
        currentTrip.removeLocation();
    }

    // --- initialize data in the page --
    ui->currentLocationLabel->setText(currentTrip.getCurrentLocation().getName());

    for(int i = 0; i < currentTrip.getCurrentLocation().getMenuSize(); i++)
    {
        ui->currentLocationMenuItemListWidget->addItem(currentTrip.getCurrentLocation().menu[i].itemName);
        ui->currentLocationMenuPriceListWidget->addItem(QString::number(currentTrip.getCurrentLocation().menu[i].price));
        ui->currentLocationMenuItemListWidget->item(i)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        ui->currentLocationMenuItemListWidget->item(i)->setCheckState(Qt::Unchecked);
    }
    ui->subTotalLabel->setText(QString::number(0));
    ui->tripSizeLabel->setText(QString::number(currentTrip.getTripSize()));



}

float MainWindow::getSubTotal()
{
    float sum = 0;

    for(int i = 0; i < ui->myOrderQuantityListWidget->count(); i++)
    {
        //perform search to match up quanitty with correct price
        bool found = false;
        int j = 0;

        while(!found && j < ui->currentLocationMenuPriceListWidget->count())
        {
            if(ui->myOrderItemListWidget->item(i)->text() == ui->currentLocationMenuItemListWidget->item(j)->text())
            {
                //item is found
                found = true;
                sum += ui->myOrderQuantityListWidget->item(i)->text().toInt() * ui->currentLocationMenuPriceListWidget->item(j)->text().toFloat();
            }
            else
            {
                ++j;
            }
        }
    }
    return sum;
}


//allowing for multiple ways to change the quantity of a purchase, you can double click on the item to add it
//or you can direct edit by double clicking on the quantity you want to change
void MainWindow::on_currentLocationMenuItemListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    bool found = false;
    int i = 0;

    while(!found && i < ui->myOrderItemListWidget->count())
    {
        if(item->text() == ui->myOrderItemListWidget->item(i)->text())
        {
            //item is found
            found = true;
        }
        else
        {
            ++i;
        }
    }

    if(!found)
    {
        //if list widget doesnt contain the item
        ui->myOrderItemListWidget->addItem(item->text());
        ui->myOrderQuantityListWidget->addItem(QString::number(1));
        item->setCheckState(Qt::Checked);
    }
    else
    {
        ui->myOrderQuantityListWidget->item(i)->setText(QString::number(ui->myOrderQuantityListWidget->item(i)->text().toInt() + 1));
    }
    ui->subTotalLabel->setText(QString::number(getSubTotal()));
}

void MainWindow::on_myOrderQuantityListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //allow editing of the item price if double clicked
    ui->myOrderQuantityListWidget->openPersistentEditor(item);
}

void MainWindow::on_currentLocationMenuItemListWidget_itemChanged(QListWidgetItem *item)
{
    //perform search for the item to be removed
    int i = 0;
    bool found = false;

    while(!found && i < ui->myOrderItemListWidget->count())
    {
        if(item->text() == ui->myOrderItemListWidget->item(i)->text())
        {
            found = true;
        }
        else
        {
            ++i;
        }
    }

    //if the item gets checked, it is added to the cart
    //if item is checked it adds it to the secondary list
    if(item->checkState() == 2 && !found)
    {
        ui->myOrderItemListWidget->addItem(item->text());
        ui->myOrderQuantityListWidget->addItem(QString::number(1));

        //ui->customEditRestaurantListWidget->item(ui->customEditRestaurantListWidget->count() - 1)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);

        //QTextStream(stdout) <<  ui->customEditRestaurantListWidget->item(ui->customEditRestaurantListWidget->count() - 1)->text()  << ui->customEditRestaurantListWidget->dragDropMode() << endl;
    }
    else if (item->checkState() == 0) //if item is unchecked
    {
        ui->myOrderItemListWidget->takeItem(i);
        ui->myOrderQuantityListWidget->takeItem(i);
    }
    ui->subTotalLabel->setText(QString::number(getSubTotal()));
}

void MainWindow::on_checkOutButton_clicked()
{
    //incremrent trip total
    //get the distance between current and next restaurant
    int previousRestaurantIndex = currentTrip.getCurrentLocation().getId();

    currentTrip.setTotalCost(currentTrip.getTotalCost() + ui->subTotalLabel->text().toFloat());
    //currentTrip.setTotalDistance(currentTrip.getTotalDistanceTraveled() + //distance from current restaurant to next restaurant
    if(currentTrip.getTripSize() > 1)
    {
        currentTrip.removeLocation();

        int nextRestaurantIndex = currentTrip.getCurrentLocation().getId();

        currentTrip.setTotalDistance(currentTrip.getTotalDistanceTraveled() + restaurantsVector[previousRestaurantIndex].getDistance(nextRestaurantIndex));

        ui->totalLabel->setText(QString::number(currentTrip.getTotalCost()));
        ui->totalDistanceLabel->setText(QString::number(currentTrip.getTotalDistanceTraveled()));

        ui->currentLocationMenuItemListWidget->clear();
        ui->currentLocationMenuPriceListWidget->clear();
        ui->myOrderItemListWidget->clear();
        ui->myOrderQuantityListWidget->clear();

        nextRestaurant();
    }
    else
    {
        //trip has ended, bring user to final screen
        ui->summaryPageTotalSpent->setText(QString::number(currentTrip.getTotalCost()));
        ui->summaryPageTotalDistance->setText(QString::number(currentTrip.getTotalDistanceTraveled()));
        ui->TakeTripStackedWidget->setCurrentIndex(2);

    }
}


