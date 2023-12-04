#include "Customer.h"

Customer::Customer(const std::string& n, const std::string& a) : name(n), address(a) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}
