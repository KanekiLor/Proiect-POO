#include "../Headers/UserInterface.h"
#include <iostream>

void UserInterface::displayMenu() const {
    std::cout << "Menu:\n";
    std::cout << "1. View available products\n";
    std::cout << "2. View shopping cart\n";
    std::cout << "3. Place an order\n";
    std::cout << "4. Exit\n";
}

void UserInterface::run() {
    int option;
    OnlineStore store;
    ShoppingCart cart;
    while (true) {
        displayMenu();
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == 1) {
            std::cout << "User specific operation: View available products\n";
            std::cout << "Here are all the available products: \n";
            viewAvailableProducts(store);
        } else if (option == 2) {
            std::cout << "User specific operation: View shopping cart\n";
            viewShoppingCart(cart);
        } else if (option == 3) {
                std::cout << "User specific operation: Place an order\n";
                placeOrder(store, cart);
            } else if (option == 4) {
                std::cout << "Goodbye from User Interface!\n";
                break;
            } else {
                std::cout << "Invalid option. Please choose again.\n";
            }
        }
    }

    void UserInterface::viewAvailableProducts(OnlineStore& store) const {
        std::cout << "Here are all the available products: \n";
        store.displayAvailableProducts();
    }

    void UserInterface::viewShoppingCart(const ShoppingCart& cart) const {
        cart.displayCart();
    }

    void UserInterface::placeOrder(OnlineStore &store, ShoppingCart &cart) {
            // Let the user choose a customer
            std::cout << "Enter the customer's name and address:\n";
            std::string customerName, customerAddress;
            std::cin >> customerName >> customerAddress;

            // Add a customer to the store or retrieve an existing one
            Customer* customer = store.addCustomer(customerName, customerAddress);

            // Display available products
            std::cout << "Here are all the available products: \n";
            store.displayAvailableProducts();

            // Let the user add products to the shopping cart
            std::cout << "Enter the product number to add to the cart (0 to stop):\n";
            int productNumber;

            while (true) {
                std::cin >> productNumber;


                if (productNumber == 0) {
                    break;
                }
                else if (productNumber > 0 && productNumber <= store.getNumAvailableProducts()) {
                    Product* selectedProduct = store.getProductByNumber(productNumber);
                    cart.addProduct(*selectedProduct);
                    std::cout << "Added " << selectedProduct->getName() << " to the cart.\n";
                }

            }

            // Place the order
            Order* order = store.placeOrder(customer, &cart);
            std::cout << "Order placed successfully!\n";

            // Display order details
            std::cout << "Order details:\n";
            std::cout << "Customer: " << order->getCustomer()->getName() << "\n";
            order->printCustomerInfo();
            std::cout << "Products in the order:\n";
            for (const Product& product : order->getShoppingCart()->getProducts()) {
                std::cout << product.getName() << " - " << product.getPrice() << " USD\n";
            }

            // Clear the shopping cart for the next order
            cart.clear();
        }
        void UserInterface::specificFunction() const {
           std::cout << "Default implementation of specificFunction() in UserInterface\n";
            }