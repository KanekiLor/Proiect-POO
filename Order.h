//
// Created by reas1 on 12/4/2023.
//

#ifndef OOP_ORDER_H
#define OOP_ORDER_H
\

#include "Customer.h"
#include "ShoppingCart.h"

class Order {
private:
    Customer* customer;
    ShoppingCart* shoppingCart;

public:
    Order(Customer* c, ShoppingCart* cart);
    Customer* getCustomer() const;
    ShoppingCart* getShoppingCart() const;
    void printCustomerInfo() const;
};

#endif //OOP_ORDER_H
