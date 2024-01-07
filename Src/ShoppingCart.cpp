#include "../Headers/ShoppingCart.h"
#include <iostream>

void ShoppingCart::addProduct(const Product& product) {
    products.push_back(product);
}

void ShoppingCart::displayCart() const {
    std::cout << "Shopping Cart:\n";
    for (const Product& product : products) {
        std::cout << product.getName() << " - " << product.getPrice() << " USD\n";
    }
}

const std::vector<Product>& ShoppingCart::getProducts() const {
    return products;
}

void ShoppingCart::clear() {
    products.clear();
}
