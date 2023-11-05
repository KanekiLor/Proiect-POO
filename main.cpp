#include <iostream>
#include <string>
#include <vector>

class Product {
private:
    std::string name;
    double price;
    int stock;
public:
    Product(const std::string& n, double p, int s) : name(n), price(p), stock(s) {};
    const std::string& getName() { return this->name; }
    double getPrice() { return this->price; }
    int getStock() { return this->stock; }
};

class Customer {
private:
    std::string name;
    std::string address;
public:
    Customer(const std::string& n, const std::string& a) : name(n), address(a) {};
    const std::string& getName() { return this->name; }
    const std::string& getAddress() { return this->address; }
};

class UserInterface {
public:
    void displayMenu() {
        std::cout << "Menu:\n";
        std::cout << "1. View available products\n";
        std::cout << "2. Add product to cart\n";
        std::cout << "3. View shopping cart\n";
        std::cout << "4. Place order\n";
        std::cout << "5. Exit\n";
    }

    void execute() {
        int option;
        while (true) {
            displayMenu();
            std::cout << "Select an option: ";
            std::cin >> option;

            if (option == 5) {
                std::cout << "Goodbye!\n";
                break;
            } else {
                std::cout << "Unimplemented option. Please choose again.\n";
            }
        }
    }
};

int main() {
    UserInterface interface;
    interface.execute();
    return 0;
}
