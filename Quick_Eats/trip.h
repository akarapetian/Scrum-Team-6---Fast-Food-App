#ifndef TRIP_H
#define TRIP_H

#include "restaurant.h"
#include <QVector>
#include <QQueue>
#include <QString>
using namespace std;

class trip{
public:
    //CONSTRUCTOR & DECONSTRUCTOR
    trip(){name = "";}
    trip(QString t_name){name = t_name;}
    ~trip(){}

    //MUTATORS
    void changeName(QString t_name){name = t_name;}
    void addLocation(restaurant loc){rList.enqueue(loc);}
    void removeLocation(){rList.dequeue();}

    //ACCESSORS
    QString getName(){return name;}
    restaurant getLocation(int key){return rList[key];}
    int getTripSize(){return rList.size();}

private:
    //queue that represents the order of locations in a trip.
    QQueue<restaurant> rList;
    //Trip Name
    QString name;

};

#endif // TRIP_H
