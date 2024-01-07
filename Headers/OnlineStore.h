//
// Created by reas1 on 12/4/2023.
//

#ifndef OOP_ONLINESTORE_H
#define OOP_ONLINESTORE_H

#include <vector>
#include "Product.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include "Order.h"

class OnlineStore {
private:
    std::vector<Product> availableProducts;
    std::vector<Customer> customers;
    std::vector<Order> orders;

public:
    void displayAvailableProducts() const;
    [[nodiscard]] int getNumAvailableProducts() const;
    Product* getProductByNumber(int productNumber);
    Customer* addCustomer(const std::string& name, const std::string& address);
    Product* addProduct(const std::string& name, double price, int stock);
    Order* placeOrder(Customer* customer, ShoppingCart* cart);
};

#endif //OOP_ONLINESTORE_H
