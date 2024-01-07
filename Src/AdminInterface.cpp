#include "../Headers/AdminInterface.h"
#include "../Headers/OnlineStore.h"
#include <iostream>


void AdminInterface::displayMenu() const {
    std::cout << "Menu:\n";
    std::cout << "1. Add a new customer\n";
    std::cout << "2. Add a new product\n";
    std::cout << "3. Exit\n";
}

void AdminInterface::run() {
    int option;
    OnlineStore store;
    while (true) {
        displayMenu();
        std::cout << "Select an option: ";
        std::cin >> option;
        if (option == 1) {
            std::cout << "Admin specific operation: Add a new customer\n";
            std::cout << "Enter the name and the address of the client\n";
            std::string a, n;
            std::cout << "Name";
            std::cin >> n;
            std::cout << "Address";
            std::cin >> a;
            store.addCustomer(n, a);
        } else if (option == 2) {
            std::cout << "Admin specific operation: Add a new product\n";
            std::cout << "Enter the name, the price, and the stock of the new product:\n";
            std::string n;
            double p;
            int s;
            std::cout << " Name: ";
            std::cin >> n;
            std::cout << "Price: ";
            std::cin >> p;
            std::cout << "Stock: ";
            std::cin >> s;
            store.addProduct(n, p, s);
        } else {
            if (option == 3) {
                std::cout << "Goodbye from Admin Interface!\n";
                break;
            } else {
                std::cout << "Invalid option. Please choose again.\n";
            }
        }
    }
}

void AdminInterface::specificFunction() const {
    std::cout << "Admin specific function\n";
}
