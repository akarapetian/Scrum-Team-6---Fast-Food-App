#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "restaurant.h"

using namespace std;

//struct representing a customer's selection at the restaurant, contains an item and the quantity

class reciept
{
public:
    reciept(){Total = 0;}
    ~reciept(){}

    void addVisit(restaurant newRestaurant){
        myreciept.push_back(newRestaurant);
    }

    float getTotal()
    {
        Total = 0;
        for(int i = 0; i < myreciept.size(); i++)
        {
            for(int j = 0; j < myreciept[i].menu.size(); j++)
            {
                Total += (myreciept[i].menu[j].itemPrice * myreciept[i].menu[j].itemQuantity);
            }
        }

        return Total;
    }

    restaurant getLastVisit(){return myreciept.back();}

    restaurant getVisit(int key){return myreciept[key];}

    int getRecieptSize(){return myreciept.size();}

private:
    float Total;
    //a vector of selections (items and their quantities), representing our cart
    QVector<restaurant> myreciept;
};


#endif // SHOPPINGCART_H
