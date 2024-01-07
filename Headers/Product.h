
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

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] double getPrice() const;
    [[nodiscard]] int getStock() const;
};


#endif //OOP_PRODUCT_H
