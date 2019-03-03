#ifndef TRIP_H
#define TRIP_H

#include <QString>
#include <QQueue>

class trip{
  public:
    //CONSTRUCTORS AND DECONSTRUCTOR
    trip();
    trip(QString t_name,QQueue<int> t_order){
        tripName = t_name;
        for(int i = 0; i<t_order.size();i++){
            tripOrder.enqueue(t_order[i]);
        }
    }
    ~trip();

    //MUTATOR
    void changeName

    //ACCESSOR
    QString GetName(){return tripName;}

  private:
    QString tripName;      //Name of the trip.
    QQueue<int> tripOrder; //Restaraunt ID's will be stored here
};

#endif // TRIP_H
