#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QString"
#include "QChar"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    restaurantsAdded  = false;

    readRestaurantFile("/home/anthony/Scrum-Team-6---Fast-Food-App-master/Quick_Eats/data.txt");

    //initialize all the pages to the first page
    ui->primaryPageStackedWidget->setCurrentIndex(0);
    ui->loginStackedWidget->setCurrentIndex(0);
    ui->MWStackedWidget->setCurrentIndex(0);
    ui->FStackedWidget->setCurrentIndex(0);
    ui->addMenuItemStackedWidget->setCurrentIndex(0);
    ui->TakeTripStackedWidget->setCurrentIndex(0);

    //Setting size constraints on text entries
    ui->usernameLineEdit->setMaxLength(16);
    ui->passwordLineEdit->setMaxLength(16);
    ui->newMenuItemName->setMaxLength(40);
    ui->newMenuItemPrice->setMaxLength(10);

    //allows users to move items around in the custom trip list
    ui->customEditRestaurantListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->customEditRestaurantListWidget->setDragEnabled(true);
    ui->customEditRestaurantListWidget->setDragDropMode(QAbstractItemView::InternalMove);
    ui->customEditRestaurantListWidget->viewport()->setAcceptDrops(true);
    ui->customEditRestaurantListWidget->setDropIndicatorShown(true);


    icons[0]  = QPixmap(":/icons/icons/721px-Saddleback_College_logo.png");
    icons[1]  = QPixmap (":/icons/icons/Logo-Mcdonalds-2016.png");
    icons[2]  = QPixmap (":/icons/icons/chipotle-mexican-grill-logo-png-transparent.png");
    icons[3]  = QPixmap (":/icons/icons/5842999aa6515b1e0ad75ae1.png");
    icons[4]  = QPixmap (":/icons/icons/kfc-png-kfc-logo-png-1-year-ago-1024.png");
    icons[5]  = QPixmap (":/icons/icons/for-subway-symbol-png-logo-1.png");
    icons[6]  = QPixmap (":/icons/icons/InNOut.svg.png");
    icons[7]  = QPixmap (":/icons/icons/wendys-logo-png--2268.png");
    icons[8]  = QPixmap (":/icons/icons/122-1223923_jack-in-the-box-logo-png.png");
    icons[9]  = QPixmap (":/icons/icons/Elpolloloco-logo.png");
    icons[10] = QPixmap (":/icons/icons/sports-papa-johns-menu-png-logo-4.png");
    icons[11] = QPixmap (":/icons/icons/pizzahut.png");
    icons[12] = QPixmap (":/icons/icons/sonic.png");

/*
    int j = 0;
    for(int i = 0; i < restaurantsVector.size(); i++)
    {
        if(validDeletedIndex(i))
        {
            ui->manageRestaurantListWidget->addItem(new QListWidgetItem(QIcon(icons[i]), restaurantsVector[i].getName()));   //icons[i]), restaurantsVector[i].getName()));
            ui->manageRestaurantListWidget->item(j)->setSizeHint(QSize(-1, 26));

            ui->manageRestaurantDistanceListWidget->addItem(QString::number(restaurantsVector[0].getDistance(i)));
            ui->manageRestaurantDistanceListWidget->item(j)->setSizeHint(QSize(-1, 26));
            ++j;
        }
    }
    */
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
    else {

        QTextStream out(&file);

        out << deletedIndexes.size() << endl;

        if(deletedIndexes.size() > 0)
        {
            for(int i = 0; i < deletedIndexes.size(); i++)
            {
                out << deletedIndexes[i] << endl;
            }
        }

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
                out << restaurantsVector[i].menu[j].itemPrice << endl;
            }
            out << endl;
        }
    }
}

void MainWindow::readRestaurantFile(QString filePath){

    restaurantsVector.clear();

    QFile file(filePath);

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

    int numDeleted;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    else{
        //read in nullified restaurants
        line = in.readLine();
        numDeleted = line.toInt();

        for(int i = 0; i < numDeleted; i++)
        {
            line = in.readLine();
            deletedIndexes.push_back(line.toInt());
        }

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
                tempMenu.push_back(item(tempItem, tempPrice, j, 0));
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
    DoubleHash dh;

    //user authentication check //username and pass for foodie is "foodie", mainteneance worker is "MW"
    switch(dh.validEntry(ui->usernameLineEdit->text(),ui->passwordLineEdit->text())){
    case 0:ui->invalidEntryStackedWidget->setCurrentIndex(1);
        break;
    case 1:ui->primaryPageStackedWidget->setCurrentIndex(1);
           currentMode = 1;
        break;
    case 2:ui->primaryPageStackedWidget->setCurrentIndex(2);
           currentMode = 2;
        break;
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

    ui->foodieMenuPriceListWidget->blockSignals(true);
    ui->foodieMenuListWidget->blockSignals(true);
    ui->foodieRestaurantListWidget->blockSignals(true);
    ui->manageMenuListWidget->blockSignals(true);
    ui->manageMenuPriceListWidget->blockSignals(true);
    ui->manageRestaurantListWidget->blockSignals(true);
    ui->manageRestaurantDistanceListWidget->blockSignals(true);
    ui->currentLocationMenuItemListWidget->blockSignals(true);
    ui->currentLocationMenuPriceListWidget->blockSignals(true);
    ui->customEditRestaurantListWidget->blockSignals(true);
    ui->customSelectRestaurantListWidget->blockSignals(true);
    ui->currentLocationMenuItemListWidget->blockSignals(true);
    ui->currentLocationMenuPriceListWidget->blockSignals(true);
    ui->recieptListWidget->blockSignals(true);
    ui->recieptPricelistWidget->blockSignals(true);
    ui->recieptQuantityListWidget->blockSignals(true);

    ui->foodieMenuPriceListWidget->clear();
    ui->foodieMenuListWidget->clear();
    ui->foodieRestaurantListWidget->clear();
    ui->manageMenuListWidget->clear();
    ui->manageMenuPriceListWidget->clear();
    ui->manageRestaurantListWidget->clear();
    ui->manageRestaurantDistanceListWidget->clear();
    ui->currentLocationMenuItemListWidget->clear();
    ui->currentLocationMenuPriceListWidget->clear();
    ui->customEditRestaurantListWidget->clear();
    ui->customSelectRestaurantListWidget->clear();
    ui->currentLocationMenuItemListWidget->clear();
    ui->currentLocationMenuPriceListWidget->clear();
    ui->recieptListWidget->clear();
    ui->recieptPricelistWidget->clear();
    ui->recieptQuantityListWidget->clear();

    ui->foodieMenuPriceListWidget->blockSignals(false);
    ui->foodieMenuListWidget->blockSignals(false);
    ui->foodieRestaurantListWidget->blockSignals(false);
    ui->manageMenuListWidget->blockSignals(false);
    ui->manageMenuPriceListWidget->blockSignals(false);
    ui->manageRestaurantListWidget->blockSignals(false);
    ui->manageRestaurantDistanceListWidget->blockSignals(false);
    ui->currentLocationMenuItemListWidget->blockSignals(false);
    ui->currentLocationMenuPriceListWidget->blockSignals(false);
    ui->customEditRestaurantListWidget->blockSignals(false);
    ui->customSelectRestaurantListWidget->blockSignals(false);
    ui->currentLocationMenuItemListWidget->blockSignals(false);
    ui->currentLocationMenuPriceListWidget->blockSignals(false);
    ui->recieptListWidget->blockSignals(false);
    ui->recieptPricelistWidget->blockSignals(false);
    ui->recieptQuantityListWidget->blockSignals(false);
}

//************************************************************************
// MY TRIPS AND MENU FUNCTIONS
//************************************************************************
/*
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
*/
//************************************************************************
// MANAGE RESTAURANTS AND MENUS FUNCTIONS
//************************************************************************
void MainWindow::on_MWManageRestaurantsButton_clicked()
{
    //go to manage restaurants page
    ui->MWStackedWidget->setCurrentIndex(2);
    int j = 0;
    for(int i = 0; i < restaurantsVector.size(); i++)
    {
        if(validDeletedIndex(i))
        {
            ui->manageRestaurantListWidget->addItem(new QListWidgetItem(QIcon(icons[i]), restaurantsVector[i].getName()));   //icons[i]), restaurantsVector[i].getName()));
            ui->manageRestaurantListWidget->item(j)->setSizeHint(QSize(-1, 26));

            ui->manageRestaurantDistanceListWidget->addItem(QString::number(restaurantsVector[0].getDistance(i)));
            ui->manageRestaurantDistanceListWidget->item(j)->setSizeHint(QSize(-1, 26));
            ++j;
        }
    }
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

    ui->manageRestaurantDistanceListWidget->setCurrentRow(current->listWidget()->currentRow());

    //solve bug where program is crashign when changing row on restaurant list widget
    //close persistent editor and update vector with whatever is edited
    if(ui->manageMenuListWidget->isPersistentEditorOpen(ui->manageMenuListWidget->currentItem()))
    {
        ui->manageMenuListWidget->closePersistentEditor(ui->manageMenuListWidget->currentItem());
        restaurantsVector[previous->listWidget()->row(previous)].menu[ui->manageMenuListWidget->currentRow()].itemName
                = ui->manageMenuListWidget->currentItem()->text();
    }



    //solve bug where program is crashign when changing row on restaurant list widget
    //close persistent editor and update vector with whatever is edited
    if(ui->manageMenuPriceListWidget->isPersistentEditorOpen(ui->manageMenuPriceListWidget->currentItem()))
    {
        ui->manageMenuPriceListWidget->closePersistentEditor(ui->manageMenuPriceListWidget->currentItem());
        restaurantsVector[previous->listWidget()->row(previous)].menu[ui->manageMenuPriceListWidget->currentRow()].itemPrice
                = ui->manageMenuPriceListWidget->currentItem()->text().toFloat();

        //ui->manageMenuPriceListWidget->item(previous->listWidget()->row(previous))->setText("$ " + ui->manageMenuPriceListWidget->item(previous->listWidget()->row(previous))->text());
    }


    if(ui->manageRestaurantListWidget->isPersistentEditorOpen(previous))
    {
        //close any editors and update the vector with the new name of restaurant
        ui->manageRestaurantListWidget->closePersistentEditor(previous);
        restaurantsVector[previous->listWidget()->row(previous)].changeName(previous->text());
    }

    //update the menu list when a new restaurant is selected

    ui->manageMenuListWidget->blockSignals(true);
    ui->manageMenuPriceListWidget->blockSignals(true);
    ui->manageMenuListWidget->clear();
    ui->manageMenuPriceListWidget->clear();
    ui->manageMenuListWidget->blockSignals(false);
    ui->manageMenuPriceListWidget->blockSignals(false);

    //perform search for the item
    int k = 0;
    bool found = false;

    while(!found && k < restaurantsVector.size())
    {
        if(ui->manageRestaurantListWidget->currentItem()->text() == restaurantsVector[k].getName())
        {
            //QTextStream(stdout) << ui->manageRestaurantListWidget->currentItem()->text() << endl;
            found = true;
        }
        else
        {
            ++k;
        }
    }

    //this is wrong
    for(int i = 0; i < restaurantsVector[k].getMenuSize(); i++){     
        ui->manageMenuListWidget->addItem(restaurantsVector[k].menu[i].itemName);
        ui->manageMenuListWidget->item(i)->setSizeHint(QSize(-1, 26));

        ui->manageMenuPriceListWidget->addItem("$ " + QString::number(restaurantsVector[k].menu[i].itemPrice));
        ui->manageMenuPriceListWidget->item(i)->setSizeHint(QSize(-1, 26));
    }
}

void MainWindow::on_manageRestaurantDistanceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->manageRestaurantListWidget->setCurrentRow(current->listWidget()->currentRow());
}

void MainWindow::on_deleteRestaurantButton_clicked()
{
    //program currently crashing if all items are removed from list
    if(ui->manageRestaurantListWidget->currentItem() != nullptr && ui->manageRestaurantListWidget->currentItem()->text() != "Saddleback College")
    {
        //perform search for the item to be removed
        int i = 0;
        bool found = false;

        while(!found && i < restaurantsVector.size())
        {
            if(ui->manageRestaurantListWidget->currentItem()->text() == restaurantsVector[i].getName())
            {
                QTextStream(stdout) << ui->manageRestaurantListWidget->currentItem()->text() << endl;
                found = true;
            }
            else
            {
                ++i;
            }
        }
        deletedIndexes.push_back(i);

        int index = ui->manageRestaurantListWidget->currentRow();
        ui->manageRestaurantListWidget->takeItem(index);
        ui->manageRestaurantDistanceListWidget->takeItem(index);
    }
}

bool MainWindow::validDeletedIndex(int i)
{
    bool valid = true;

    if(deletedIndexes.size() > 0)
    {
        //if i exists in a list of nullified indexes, valid = false;
       for(int count = 0; count < deletedIndexes.size(); count++)
       {
           if(i == deletedIndexes[count])
           {
               valid = false;
           }
       }
    }
    return valid;
}

void MainWindow::on_addRestaurantButton_clicked()
{
    if(restaurantsAdded == false)
    {
        //parse second data.txt file and add new restaurants to vector
        readRestaurantFile("/home/anthony/Scrum-Team-6---Fast-Food-App-master/Quick_Eats/data2.txt");
        //update the list view in the manage restaurants page

        ui->manageRestaurantListWidget->blockSignals(true);
        ui->manageRestaurantDistanceListWidget->blockSignals(true);
        ui->manageMenuListWidget->blockSignals(true);
        ui->manageMenuPriceListWidget->blockSignals(true);

        ui->manageRestaurantListWidget->clear();
        ui->manageRestaurantDistanceListWidget->clear();
        ui->manageMenuListWidget->clear();
        ui->manageMenuPriceListWidget->clear();

        ui->manageRestaurantListWidget->blockSignals(false);
        ui->manageRestaurantDistanceListWidget->blockSignals(false);
        ui->manageMenuListWidget->blockSignals(false);
        ui->manageMenuPriceListWidget->blockSignals(false);


        int j = 0;
        for(int i = 0; i < restaurantsVector.size(); i++)
        {

            if(validDeletedIndex(i))
            {
                ui->manageRestaurantListWidget->addItem(new QListWidgetItem(QIcon(icons[i]), restaurantsVector[i].getName()));   //icons[i]), restaurantsVector[i].getName()));
                ui->manageRestaurantListWidget->item(j)->setSizeHint(QSize(-1, 26));

                ui->manageRestaurantDistanceListWidget->addItem(QString::number(restaurantsVector[0].getDistance(i)));
                ui->manageRestaurantDistanceListWidget->item(j)->setSizeHint(QSize(-1, 26));
                ++j;
            }
        }
        restaurantsAdded = true;
    }
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
        int k = 0;
        bool found = false;

        while(!found && k < restaurantsVector.size())
        {
            if(ui->manageRestaurantListWidget->currentItem()->text() == restaurantsVector[k].getName())
            {
                //QTextStream(stdout) << ui->manageRestaurantListWidget->currentItem()->text() << endl;
                found = true;
            }
            else
            {
                ++k;
            }
        }
        restaurantsVector[k].menu[previous->listWidget()->row(previous)].itemName = previous->text();
    }
    ui->manageMenuListWidget->closePersistentEditor(previous);
    ui->manageMenuPriceListWidget->setCurrentRow(current->listWidget()->currentRow());
}

//closes the editor if the selected item is changed in the menu price list
void MainWindow::on_manageMenuPriceListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->manageMenuPriceListWidget->isPersistentEditorOpen(previous))
    {
        int k = 0;
        bool found = false;

        while(!found && k < restaurantsVector.size())
        {
            if(ui->manageRestaurantListWidget->currentItem()->text() == restaurantsVector[k].getName())
            {
                //QTextStream(stdout) << ui->manageRestaurantListWidget->currentItem()->text() << endl;
                found = true;
            }
            else
            {
                ++k;
            }
        }
        //before closing editor, check for valid input
        //before closing editor, check for valid
        //perform search for the item
        if(isFloatNumber(previous->text()))
        {

            restaurantsVector[k].menu[previous->listWidget()->row(previous)].itemPrice = previous->text().toFloat();
            previous->setText("$ " + previous->text());
        }
        else
        {
            //input is not a float
            QMessageBox::warning(nullptr, "Error", "Invalid Price Input! Please Enter a Float");

            previous->setText("$ " + QString::number(restaurantsVector[k].menu[previous->listWidget()->row(previous)].itemPrice));

        }
        ui->manageMenuPriceListWidget->closePersistentEditor(previous);
    }
    ui->manageMenuListWidget->setCurrentRow(current->listWidget()->currentRow());
}

bool MainWindow::isFloatNumber(const QString& Qstring)
{
    string stdString = Qstring.toStdString();

    string::const_iterator it = stdString.begin();
    bool decimalPoint = false;
    unsigned int minSize = 0;
    if(stdString.size()>0 && (stdString[0] == '-' || stdString[0] == '+')){
      it++;
      minSize++;
    }
    while(it != stdString.end()){
      if(*it == '.'){
        if(!decimalPoint) decimalPoint = true;
        else break;
      }else if(!std::isdigit(*it) && ((*it!='f') || it+1 != stdString.end() || !decimalPoint)){
        break;
      }
      ++it;
    }
    return stdString.size() > minSize && it == stdString.end();
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
        //check for valid float
        if(isFloatNumber(ui->newMenuItemPrice->text()))
        {
            //perform search for the item
            int k = 0;
            bool found = false;

            while(!found && k < restaurantsVector.size())
            {
                if(ui->manageRestaurantListWidget->currentItem()->text() == restaurantsVector[k].getName())
                {
                    //QTextStream(stdout) << ui->manageRestaurantListWidget->currentItem()->text() << endl;
                    found = true;
                }
                else
                {
                    ++k;
                }
            }
            restaurantsVector[k].addMenuItem(ui->newMenuItemName->text(), ui->newMenuItemPrice->text().toFloat(),
                                                                                  restaurantsVector[k].menu.size(), 0);
            ui->manageMenuListWidget->addItem(ui->newMenuItemName->text());
            ui->manageMenuPriceListWidget->addItem("$ " + QString::number(ui->newMenuItemPrice->text().toFloat()));
        }
        else
        {
            QMessageBox::warning(nullptr, "Error", "Invalid Price Input! Please Enter a Float");
        }
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
    if(ui->manageMenuListWidget->currentItem() != nullptr && ui->manageMenuListWidget->count() > 1)
    {
        //perform search for the item to be removed
        int k = 0;
        bool found = false;

        while(!found && k < restaurantsVector.size())
        {
            if(ui->manageRestaurantListWidget->currentItem()->text() == restaurantsVector[k].getName())
            {
                //QTextStream(stdout) << ui->manageRestaurantListWidget->currentItem()->text() << endl;
                found = true;
            }
            else
            {
                ++k;
            }
        }
        //remove items from lists
        int index = ui->manageMenuListWidget->currentRow();
        ui->manageMenuListWidget->takeItem(index);
        ui->manageMenuPriceListWidget->takeItem(index);

        //remove items from data structure
        restaurantsVector[k].menu.remove(index);
    }
}
//***************************************************************************************************************************
// TAKING TRIPS FUNCTIONS
//***************************************************************************************************************************

void MainWindow::on_MWTakeTripButton_clicked()
{
    int j = 0;
    //update the list view in the manage restaurants page
    for(int i = 0; i < restaurantsVector.size(); i++)
    {

        if(validDeletedIndex(i))
        {
            ui->customSelectRestaurantListWidget->addItem(restaurantsVector[i].getName());

            ui->customSelectRestaurantListWidget->item(j)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
            ui->customSelectRestaurantListWidget->item(j)->setCheckState(Qt::Unchecked);
            ++j;
        }

    }

    ui->MWStackedWidget->setCurrentIndex(1);
    ui->TakeTripStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pathPageBackButton_clicked()
{
    //IF FOODIE
   if(currentMode == 1)
   {
       ui->primaryPageStackedWidget->setCurrentIndex(1);
   }

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

    if(nullifiedIndexes.size() > 0)
    {
        //if i exists in a list of nullified indexes, valid = false;
       for(int count = 0; count < nullifiedIndexes.size(); count++)
       {
           if(i == nullifiedIndexes[count])
           {
               valid = false;
           }
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
    if(ui->customEditRestaurantListWidget->count() > 1)
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

        optimizePath(startingIndex, n);

        nullifiedIndexes.clear();
    }
}


void MainWindow::on_customTakeTripButton_clicked()
{
    if(ui->customEditRestaurantListWidget->count() > 0)
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

        if(currentTrip.getCurrentLocation().getName() == "Saddleback College")
        {
            ui->TakeTripStackedWidget->setCurrentIndex(2);
            //nextrestaurant index is saddleback
            currentTrip.removeLocation();
            int nextnextRestaurantIndex = currentTrip.getCurrentLocation().getId();
            currentTrip.setTotalDistance(currentTrip.getTotalDistanceTraveled() + restaurantsVector[0].getDistance(nextnextRestaurantIndex));
        }

        nextRestaurant();
    }
}

//*************************************************************
//IN THE RESTAURANT METHODS
//*************************************************************

//need to track distances in here
void MainWindow::nextRestaurant()
{
    ui->totalLabel->setText(QString::number(currentTrip.getTotalCost()));
    ui->totalDistanceLabel->setText(QString::number(currentTrip.getTotalDistanceTraveled()));

    ui->currentLocationMenuItemListWidget->clear();
    ui->currentLocationMenuPriceListWidget->clear();

    ui->myOrderItemListWidget->clear();
    ui->myOrderQuantityListWidget->clear();

    // --- initialize data in the page --
    ui->currentLocationLabel->setText(currentTrip.getCurrentLocation().getName());

    for(int i = 0; i < currentTrip.getCurrentLocation().getMenuSize(); i++)
    {
        ui->currentLocationMenuItemListWidget->addItem(currentTrip.getCurrentLocation().menu[i].itemName);
        ui->currentLocationMenuPriceListWidget->addItem("$ " + QString::number(currentTrip.getCurrentLocation().menu[i].itemPrice));
        ui->currentLocationMenuItemListWidget->item(i)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        ui->currentLocationMenuItemListWidget->item(i)->setCheckState(Qt::Unchecked);
    }
    ui->subTotalLabel->setText(QString::number(0));
    ui->tripSizeLabel->setText(QString::number(currentTrip.getTripSize() - 1));
}



void MainWindow::on_continueButton_clicked()
{
    nextRestaurant();
    ui->TakeTripStackedWidget->setCurrentIndex(1);
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
                QTextStream(stdout) << ui->myOrderQuantityListWidget->item(i)->text().toInt() << endl;
                QTextStream(stdout) << ui->currentLocationMenuPriceListWidget->item(j)->text().toFloat() << endl;
                QString price = ui->currentLocationMenuPriceListWidget->item(j)->text().remove('$');
                sum += ui->myOrderQuantityListWidget->item(i)->text().toInt() * price.toFloat();
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
        //ui->myOrderPriceListWidget->addItem(ui->currentLocationMenuPriceListWidget->item(i));
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
        //ui->myOrderPriceListWidget->addItem(ui->currentLocationMenuPriceListWidget->item(item->listWidget()->currentRow())->text());
        ui->myOrderQuantityListWidget->addItem(QString::number(1));

        //ui->customEditRestaurantListWidget->item(ui->customEditRestaurantListWidget->count() - 1)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);

        //QTextStream(stdout) <<  ui->customEditRestaurantListWidget->item(ui->customEditRestaurantListWidget->count() - 1)->text()  << ui->customEditRestaurantListWidget->dragDropMode() << endl;
    }
    else if (item->checkState() == 0) //if item is unchecked
    {
        ui->myOrderItemListWidget->takeItem(i);
        //ui->myOrderPriceListWidget->takeItem(i);
        ui->myOrderQuantityListWidget->takeItem(i);
    }
    ui->subTotalLabel->setText(QString::number(getSubTotal()));
}

void MainWindow::on_checkOutButton_clicked()
{
    //incremrent trip total
        //GENERATE RECIEPT ***
        if(currentTrip.getCurrentLocation().getName() != "Saddleback College")
        {
            ui->recieptListWidget->addItem(currentTrip.getCurrentLocation().getName());
            ui->recieptPricelistWidget->addItem(" ");
            ui->recieptQuantityListWidget->addItem(" ");

            ui->recieptListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            ui->recieptQuantityListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            ui->recieptPricelistWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);

            ui->recieptListWidget->addItem("---------------------------------------------------");
            ui->recieptPricelistWidget->addItem("---------");
            ui->recieptQuantityListWidget->addItem("-------");

            ui->recieptListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            ui->recieptQuantityListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            ui->recieptPricelistWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);

            for(int i = 0; i < ui->myOrderItemListWidget->count(); i++)
            {
                //perform search for the menu item
                int k = 0;
                bool found = false;
                while(!found && k < ui->currentLocationMenuItemListWidget->count())
                {
                    if(ui->currentLocationMenuItemListWidget->item(k)->text() == ui->myOrderItemListWidget->item(i)->text())
                    {
                        found = true;
                    }
                    else
                    {
                        ++k;
                    }
                }
                //add items to reciept
                ui->recieptListWidget->addItem("    " + ui->currentLocationMenuItemListWidget->item(k)->text());
                ui->recieptPricelistWidget->addItem(ui->currentLocationMenuPriceListWidget->item(k)->text());
                ui->recieptQuantityListWidget->addItem(ui->myOrderQuantityListWidget->item(i)->text());

                ui->recieptListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
                ui->recieptQuantityListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
                ui->recieptPricelistWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);

            }
            ui->recieptListWidget->addItem(" ");
            ui->recieptPricelistWidget->addItem(" ");
            ui->recieptQuantityListWidget->addItem(" ");
            ui->recieptListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            ui->recieptQuantityListWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            ui->recieptPricelistWidget->item(ui->recieptListWidget->count() -1)->setFlags(Qt::NoItemFlags);
            //**********
        }


    currentTrip.setTotalCost(currentTrip.getTotalCost() + ui->subTotalLabel->text().toFloat());

    if(currentTrip.getTripSize() > 1)
    {
        //get the distance between current and next restaurant
        int previousRestaurantIndex = currentTrip.getCurrentLocation().getId();

        currentTrip.removeLocation();

        int nextRestaurantIndex = currentTrip.getCurrentLocation().getId();

        currentTrip.setTotalDistance(currentTrip.getTotalDistanceTraveled() + restaurantsVector[previousRestaurantIndex].getDistance(nextRestaurantIndex));

        //if the next location is saddleback, we change the screen, but also increment distance traveled
        if(currentTrip.getCurrentLocation().getName() == "Saddleback College")
        {
            ui->TakeTripStackedWidget->setCurrentIndex(2);
            //nextrestaurant index is saddleback
            currentTrip.removeLocation();
            int nextnextRestaurantIndex = currentTrip.getCurrentLocation().getId();
            currentTrip.setTotalDistance(currentTrip.getTotalDistanceTraveled() + restaurantsVector[nextRestaurantIndex].getDistance(nextnextRestaurantIndex));
        }

        nextRestaurant();
    }
    else
    {
        //trip has ended, bring user to final screen
        ui->summaryPageTotalSpent->setText(QString::number(currentTrip.getTotalCost()));
        ui->summaryPageTotalDistance->setText(QString::number(currentTrip.getTotalDistanceTraveled()));

        ui->TakeTripStackedWidget->setCurrentIndex(3);
    }
}

void MainWindow::on_endTripButton_clicked()
{
    //clear all data

    //check the type of user and

    //if foodie
    if(currentMode == 1)
    {
        ui->primaryPageStackedWidget->setCurrentIndex(1);
    }

    ui->MWStackedWidget->setCurrentIndex(0);

    ui->TakeTripStackedWidget->setCurrentIndex(0);

    ui->summaryPageTotalSpent->clear();
    ui->summaryPageTotalDistance->clear();

    while(currentTrip.getTripSize() != 0)
    {
        currentTrip.removeLocation();
    }

    ui->recieptListWidget->clear();
    ui->recieptPricelistWidget->clear();
    ui->recieptQuantityListWidget->clear();

    ui->currentLocationMenuItemListWidget->clear();
    ui->currentLocationLabel->clear();
    ui->currentLocationMenuPriceListWidget->clear();

    ui->myOrderQuantityListWidget->clear();
    ui->myOrderItemListWidget->clear();


    ui->customEditRestaurantListWidget->clear();
    ui->customSelectRestaurantListWidget->clear();

    currentTrip.setTotalCost(0);
    currentTrip.setTotalDistance(0);

}

//*************************************************
// FOODIE METHODS
//*************************************************


void MainWindow::on_FTakeTripButton_clicked()
{
    //link foodie to mw take trip function to avoid copy/pasting code
    ui->primaryPageStackedWidget->setCurrentIndex(2);
    on_MWTakeTripButton_clicked();
}

void MainWindow::on_FViewRestaurantsButton_clicked()
{
    int j = 0;
    for(int i = 0; i < restaurantsVector.size(); i++)
    {
        if(validDeletedIndex(i))
        {
            ui->foodieRestaurantListWidget->addItem(new QListWidgetItem(QIcon(icons[i]), restaurantsVector[i].getName()));   //icons[i]), restaurantsVector[i].getName()));
            ui->foodieRestaurantListWidget->item(j)->setSizeHint(QSize(-1, 26));

            ui->foodieRestaurantDistanceListWidget->addItem(QString::number(restaurantsVector[0].getDistance(i)));
            ui->foodieRestaurantDistanceListWidget->item(j)->setSizeHint(QSize(-1, 26));
            ++j;
        }
    }

    ui->FStackedWidget->setCurrentIndex(1);
}


void MainWindow::on_FviewRestaurantsBackButton_clicked()
{

    ui->FStackedWidget->setCurrentIndex(0);

    ui->foodieRestaurantListWidget->blockSignals(true);
    ui->foodieRestaurantDistanceListWidget->blockSignals(true);
    ui->foodieRestaurantListWidget->clear();
    ui->foodieRestaurantDistanceListWidget->clear();
    ui->foodieRestaurantListWidget->blockSignals(false);
    ui->foodieRestaurantDistanceListWidget->blockSignals(false);

}

void MainWindow::on_foodieRestaurantListWidget_currentRowChanged(int currentRow)
{
    ui->foodieRestaurantDistanceListWidget->setCurrentRow(currentRow);

    //update the menu list when a new restaurant is selected
    ui->foodieMenuListWidget->blockSignals(true);
    ui->foodieMenuPriceListWidget->blockSignals(true);
    ui->foodieMenuListWidget->clear();
    ui->foodieMenuPriceListWidget->clear();
    ui->foodieMenuListWidget->blockSignals(false);
    ui->foodieMenuPriceListWidget->blockSignals(false);

    //perform search for the item
    int k = 0;
    bool found = false;

    while(!found && k < restaurantsVector.size())
    {
        if(ui->foodieRestaurantListWidget->currentItem()->text() == restaurantsVector[k].getName())
        {
            found = true;
        }
        else
        {
            ++k;
        }
    }

    for(int i = 0; i < restaurantsVector[k].getMenuSize(); i++){
        ui->foodieMenuListWidget->addItem(restaurantsVector[k].menu[i].itemName);
        ui->foodieMenuListWidget->item(i)->setSizeHint(QSize(-1, 26));

        ui->foodieMenuPriceListWidget->addItem("$ " + QString::number(restaurantsVector[k].menu[i].itemPrice));
        ui->foodieMenuPriceListWidget->item(i)->setSizeHint(QSize(-1, 26));
    }

}

void MainWindow::on_foodieRestaurantDistanceListWidget_currentRowChanged(int currentRow)
{
    ui->foodieRestaurantListWidget->setCurrentRow(currentRow);
}

void MainWindow::on_foodieMenuListWidget_currentRowChanged(int currentRow)
{
    ui->foodieMenuPriceListWidget->setCurrentRow(currentRow);
}

void MainWindow::on_foodieMenuPriceListWidget_currentRowChanged(int currentRow)
{
    ui->foodieMenuListWidget->setCurrentRow(currentRow);
}
