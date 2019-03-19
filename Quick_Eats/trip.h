#ifndef TRIP_H
#define TRIP_H

#include "restaurant.h"
#include "shoppingcart.h"
#include <QVector>
#include <QQueue>
#include <QString>
using namespace std;

class trip{
public:
    //CONSTRUCTOR & DECONSTRUCTOR
    trip(){name = ""; totalCost = 0; totalDistanceTraveled = 0;}
    trip(QString t_name, float t_totalCost, float t_totalDistanceTraveled){name = t_name; totalCost = t_totalCost; totalDistanceTraveled = t_totalDistanceTraveled;}
    ~trip(){}

    //MUTATORS
    void changeName(QString t_name){name = t_name;}
    void addLocation(restaurant loc){rList.enqueue(loc);}
    void removeLocation(){rList.dequeue();}
    void setTotalCost(float newTotalCost){totalCost = newTotalCost;}
    void setTotalDistance(float newTotalDistance){totalDistanceTraveled = newTotalDistance;}

    //ACCESSORS
    QString getName()const{return name;}
    restaurant getCurrentLocation(){return rList.head();}
    int getTripSize()const{return rList.size();}
    restaurant getLocation(int key)const{return rList[key];}
    float getTotalCost()const{return totalCost;}
    float getTotalDistanceTraveled()const{return totalDistanceTraveled;}


private:
    //queue that represents the order of locations in a trip.
    QQueue<restaurant> rList;
    //Trip Name
    QString name;

    float totalCost;
    float totalDistanceTraveled;

    //ShoppingCart currentShoppingCart;
};

#endif // TRIP_H
