#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Product.h"

class ShoppingCart {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void displayCart() const;
    const std::vector<Product>& getProducts() const;
    void clear();
};

#endif // SHOPPINGCART_H
