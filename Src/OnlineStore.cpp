#include "../Headers/OnlineStore.h"
#include <iostream>

void OnlineStore::displayAvailableProducts() const {
    std::cout << "Available Products:\n";
    int i=0;
    for (const Product& product : availableProducts) {
        std::cout << ++i << "." << product.getName() << " - " << product.getPrice() << " RON " << product.getStock()
                  << " pcs.\n";
    }
}

int OnlineStore::getNumAvailableProducts() const {
    return static_cast<int>(availableProducts.size());
}

Product* OnlineStore::getProductByNumber(int productNumber) {
    if (productNumber > 0 && productNumber <= getNumAvailableProducts()) {
        return &availableProducts[productNumber - 1];
    }
    else {
        return nullptr;  // Return nullptr for invalid product numbers
    }
}

Customer* OnlineStore::addCustomer(const std::string& name, const std::string& address) {
    customers.emplace_back(name, address);
    return &customers.back();
}

Product* OnlineStore::addProduct(const std::string& name, double price, int stock) {
    availableProducts.emplace_back(name,price,stock);
    return &availableProducts.back();
}

Order* OnlineStore::placeOrder(Customer* customer, ShoppingCart* cart) {
    Order newOrder(customer, cart);
    orders.push_back(newOrder);
    return &orders.back();
}