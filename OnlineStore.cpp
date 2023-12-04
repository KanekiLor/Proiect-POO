#include "OnlineStore.h"
#include <iostream>

void OnlineStore::displayAvailableProducts() const {
    // Implementation
}

int OnlineStore::getNumAvailableProducts() const {
    return static_cast<int>(availableProducts.size());
}

Product* OnlineStore::getProductByNumber(int productNumber) {
    // Implementation
}

Customer* OnlineStore::addCustomer(const std::string& name, const std::string& address) {
    // Implementation
}

Product* OnlineStore::addProduct(const std::string& name, double price, int stock) {
    // Implementation
}

Order* OnlineStore::placeOrder(Customer* customer, ShoppingCart* cart) {
    // Implementation
}
