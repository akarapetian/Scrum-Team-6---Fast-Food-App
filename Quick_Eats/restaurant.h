#ifndef RESTAURANT_H
#define RESTAURANT_H
//#include <iostream>
#include <QString>
#include <QVector>
using namespace std;

struct item{
    //constructor for easily initializing new items
    item(){}

    item(QString newItemName, float newItemPrice, int newItemId)
    {
        itemName = newItemName;
        price = newItemPrice;
        itemId = newItemId;
    }

    QString itemName;
    float price;
    int itemId;
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

    void addMenuItem(QString iName,float iPrice,int iId){     
        //create new item
        item newItem(iName, iPrice, iId);

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

private:
    int id;          //Unique ID of restaurant
    QString name;     //name of restaurant


    //THIS IS WHERE THE ERROR WAS (distance was declared to be size 10)
    QVector<float> distance; //Index 0 in this array is always going to be distance from saddleback.
};

#endif // RESTAURANT_H
