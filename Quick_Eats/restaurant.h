#ifndef RESTAURANT_H
#define RESTAURANT_H
//#include <iostream>
#include <QString>
#include <QVector>
using namespace std;

struct item{
    //constructor for easily initializing new items
    item(){}

    item(QString newItemName, float newItemPrice, int newItemId, int newItemQuantity)
    {
        itemName = newItemName;
        itemPrice = newItemPrice;
        itemId = newItemId;
        itemQuantity = newItemQuantity;
    }

    QString itemName;
    float itemPrice;
    int itemId;
    int itemQuantity;
};

class restaurant{
public:
    //CONSTRUCTOR & DECONSTRUCTOR
    restaurant(){
        id = 0;
        name = "";
    }

    restaurant(int newId, QString newName, QVector<float> newDistance, QVector<item> newMenu){
        id = newId;
        name = newName;
        menu = newMenu;
        distance = newDistance;
    }

    ~restaurant(){
    }

    //MUTATORS
    void changeId(int new_id){id = new_id;}
    void changeName(QString new_name){name = new_name;}
    void addDistance(int new_distance){distance[getDistanceSize()] = new_distance;}
    void removeDistance(int key){
        distance.remove(key);
    }

    void addMenuItem(QString iName,float iPrice,int iId, int iQuantity){
        //create new item
        item newItem(iName, iPrice, iId, iQuantity);

        //push new item onto the menu
        menu.push_back(newItem);
    }

    //remove an item by its Id
    void removeMenuItem(int key){
        bool found = false;
        int count = 0;

        while(!found && count < menu.size())
        {
            if(key == menu[count].itemId)
            {
                found = true;
                menu.remove(count);
            }
            count++;
        }

        if(!found)
        {
            //output item not found error
        }
    }

    //ACCESSORS
    int getId()const{return id;}
    QString getName()const{return name;}
    int getMenuSize()const{return menu.size();}
    float getDistance(int key)const{return distance[key];}
    int getDistanceSize(){return distance.size();}

    //must be public at this moment
    QVector<item> menu; //menu vector (vector of items)
    QVector<float> distance; //Index 0 in this array is always going to be distance from saddleback.

private:
    int id;          //Unique ID of restaurant
    QString name;     //name of restaurant
    //QIcon icon;

    //THIS IS WHERE THE ERROR WAS (distance was declared to be size 10)

};

#endif // RESTAURANT_H
