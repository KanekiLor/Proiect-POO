#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string address;

public:
    Customer(const std::string& n, const std::string& a);

    std::string getName() const;
    std::string getAddress() const;
};

#endif // CUSTOMER_H
