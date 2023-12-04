
#include "Product.h"

Product::Product(const std::string& n, double p, int s) : name(n), price(p), stock(s) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}
