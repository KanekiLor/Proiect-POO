#include "Headers/Singleton.h"
#include "Headers/Interface.h"
#include "Headers/AdminInterface.h"
#include "Headers/UserInterface.h"
#include "Headers/Customer.h"
#include <iostream>

int main() {
    Singleton& singleton = Singleton::getInstance();
    Interface* interface = nullptr;
    int option;
    while (true) {
        try {
            if (!interface) {
                std::cout << "Select 1 for Admin Interface or 2 for User Interface\n";
                std::cin >> option;

                if (option == 1) {
                    interface = new AdminInterface();
                } else if (option == 2) {
                    interface = new UserInterface();
                } else if (option == 3) {
                    delete interface;
                    break;
                } else {
                    std::cout << "Invalid option. Please choose again.\n";
                }

                if (interface) {
                    singleton.setInterface(interface);
                }
            }

            if (singleton.getInterface()) {
                singleton.getInterface()->run();
                singleton.getInterface()->specificFunction();
                delete singleton.getInterface();
                singleton.setInterface(nullptr);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
