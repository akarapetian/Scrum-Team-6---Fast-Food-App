#ifndef RESTAURANT_H
#define RESTAURANT_H
//#include <iostream>
#include <QString>
//#include <vector>
using namespace std;

struct item{
    QString itemName;
    float price;
    int itemId;
    item*next;
};

class restaurant{
public:
    //CONSTRUCTOR & DECONSTRUCTOR
    restaurant(){
        id = 0;
        name = "";
        distanceSize = 0;
        distance[0] = 0;
        menuSize = 0;
        menu = nullptr;
    }

    restaurant(int newId, QString newName, int newDistanceSize, int newDistance[], int newMenuSize, item *newMenu){
        id = newId;
        name = newName;
        distanceSize = newDistanceSize;
        for(int i = 0; i < newDistanceSize; i++)
        {
            distance[i] = newDistance[i];
        }
        menuSize = newMenuSize;
        menu = newMenu;
    }

    ~restaurant(){
        item*temp = menu;
        id = 0;
        name = "";
        distanceSize = 0;
        for(int i = 0;i<20;i++){
            distance[i] = 0;
        }
        menuSize = 0;
        while(temp!=nullptr){
            menu = temp->next;
            delete temp;
            temp = menu;
        }
    }

    //MUTATORS
    void changeId(int new_id){id = new_id;}
    void changeName(QString new_name){name = new_name;}
    void changeMenuSize(int new_menuSize){menuSize = new_menuSize;}
    void changeDistanceSize(int new_distSize){distanceSize = new_distSize;}
    void addDistance(int new_distance){distance[distanceSize] = new_distance;distanceSize++;}
    void removeDistance(int key){
        for(int i =key;i<distanceSize;i++){
            distance[i] = distance[i+1];
        }
        distanceSize--;
    }
    void addMenuItem(QString iName,float iPrice,int iId){
        item*temp = new item;
        temp->itemName = iName;
        temp->price = iPrice;
        temp->itemId = iId;
        temp->next = menu;
        menu = temp;
        menuSize++; //Increase menu size
    }
    void removeMenuItem(int key){
        // Store head node
        item* temp = menu;
        item* prev = menu;

        // If head node itself holds the key to be deleted
        if(temp != nullptr && temp->itemId == key){
            menu = temp->next;   //Changed head
            delete temp;         //free old head
            menuSize--;          //Decrease menuSize
            return;
        }

        // Search for the key to be deleted, keep track of the
        // previous node as we need to change 'prev->next'
        while(temp != nullptr && temp->itemId != key){
            prev = temp;
            temp = temp->next;
        }
        // If key was not present in linked list
        if(temp == nullptr){return;}

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;  // Free memory
        menuSize--;  //Decrease menuSize
    }

    //ACCESSORS
    int getId()const{return id;}
    QString getName()const{return name;}
    int getMenuSize()const{return menuSize;}
    int getDistance(int key)const{return distance[key];}
    int getDistanceSize(){return distanceSize;}
private:
    int id;          //Unique ID of restaurant
    QString name;     //name of restaurant
    int distanceSize; //Number of restaurants
    int distance[20]; //Index 1 in this array is always going to be distance from saddleback.
    int menuSize;     //Number of menuItems
    item *menu;       //Linked list of menu Items.
};

#endif // RESTAURANT_H
