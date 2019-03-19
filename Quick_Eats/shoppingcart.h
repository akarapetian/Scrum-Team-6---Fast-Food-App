#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "restaurant.h"

using namespace std;

//struct representing a customer's selection at the restaurant, contains an item and the quantity
struct selection
{
    selection();
    selection(item newItem, int newQuantity)
    {
        selectedItem.itemName = newItem.itemName;
        selectedItem.price    = newItem.price;
        selectedItem.itemId   = newItem.itemId;

        quantity = newQuantity;
    }

    item selectedItem;
    int  quantity;
};

class ShoppingCart
{
public:
    ShoppingCart();
    ~ShoppingCart();

    void addSelection(selection mySelection){
        cart.push_back(mySelection);
    }

    float getSubTotal()const{return subTotal;}



private:
    float subTotal;

    //a vector of selections (items and their quantities), representing our cart
    QVector<selection> cart;
};


#endif // SHOPPINGCART_H
