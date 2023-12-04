#include "Order.h"
#include <iostream>

Order::Order(Customer* c, ShoppingCart* cart) : customer(c), shoppingCart(cart) {}

Customer* Order::getCustomer() const {
    return customer;
}

ShoppingCart* Order::getShoppingCart() const {
    return shoppingCart;
}

void Order::printCustomerInfo() const {
    std::cout << "Customer address: " << customer->getAddress() << std::endl;
}
