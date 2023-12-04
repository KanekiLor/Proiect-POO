//
// Created by reas1 on 12/4/2023.
//

#ifndef OOP_PRODUCT_H
#define OOP_PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    int stock;

public:
    Product(const std::string& n, double p, int s);

    std::string getName() const;
    double getPrice() const;
    int getStock() const;
};


#endif //OOP_PRODUCT_H
