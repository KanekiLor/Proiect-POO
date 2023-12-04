    #include <iostream>
    #include <vector>
    #include <limits>
    #include "ShoppingCart.h"
    #include "OnlineStore.h"
    #include "Product.h"
    #include "Customer.h"
    #include "Order.h"
    enum Options_ {View_Add_Products=1,View_Cart,Place_Order,Exit};
    enum Options_2 {Add_Customer=1,Add_product,Exit2};


    // Custom exception classes
    class InvalidInputException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Invalid input. Please enter a valid value.";
        }
    };

    class InvalidProductNumberException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Invalid product number. Please enter a valid product number.";
        }
    };

    class Interface {
    public:
        virtual void displayMenu() const = 0;
        virtual void run() = 0;
        virtual ~Interface() {}
    };

    class AdminInterface : public Interface {
    public:
        void displayMenu() const override {
            std::cout << "Menu:\n";
            std::cout << "1. Add a new customer\n";
            std::cout << "2. Add a new product\n";
            std::cout << "3. Exit\n";
        }

        void run() override {
            int option;
            OnlineStore store;  // Creating an instance of OnlineStore for admin interactions

            while (true) {
                displayMenu();
                std::cout << "Select an option: ";
                std::cin >> option;
                if (option == Add_Customer) {
                    std::cout << "Enter the name and the address of the client\n";
                    std::string a, n;
                    std::cin >> a >> n;
                    store.addCustomer(n, a);
                }
                if (option == Add_product) {
                    std::cout << "Enter the name, the price, and the stock of the new product:\n";
                    std::string n;
                    double p;
                    int s;
                    std::cin >> n >> p >> s;
                    store.addProduct(n, p, s);
                }
                if (option == Exit2) {
                    std::cout << "Goodbye!\n";
                    break;
                }
                else {
                    std::cout << "Option not implemented. Please choose again.\n";
                }
            }
        }
    };

    class UserInterface : public Interface {
    public:
        void displayMenu() const override {
            std::cout << "Menu:\n";
            std::cout << "1. View available products\n";
            std::cout << "2. Add a product to the cart\n";
            std::cout << "3. View shopping cart\n";
            std::cout << "4. Place an order\n";
            std::cout << "5. Exit\n";
        }

        void run() override {
            int option;
            OnlineStore store;  // Creating an instance of OnlineStore for user interactions
            ShoppingCart cart;  // Creating a shopping cart for the user

            while (true) {
                try {
                    displayMenu();
                    std::cout << "Select an option: ";
                    std::cin >> option;

                    if (std::cin.fail()) {
                        throw InvalidInputException();
                    }

                    if (option == View_Add_Products) {
                        std::cout << "Here are all the available products: \n";
                        store.displayAvailableProducts();
                    }
                    else if (option == View_Cart) {
                        cart.displayCart();
                    }
                    else if (option == Place_Order) {
                        placeOrder(store, cart);

                    }
                    else if (option == Exit) {
                        std::cout << "Goodbye!\n";
                        break;
                    }
                    else {
                        std::cout << "Option not implemented. Please choose again.\n";
                    }
                }
                catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    std::cin.clear();  // Clear error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                }
            }
        }

    private:
        void placeOrder(OnlineStore& store, ShoppingCart& cart) {
            try {
                // Let the user choose a customer
                std::cout << "Enter the customer's name and address:\n";
                std::string customerName, customerAddress;
                std::cin >> customerName >> customerAddress;

                if (std::cin.fail()) {
                    throw InvalidInputException();
                }

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

                    if (std::cin.fail()) {
                        throw InvalidInputException();
                    }

                    if (productNumber == 0) {
                        break;
                    }
                    else if (productNumber > 0 && productNumber <= store.getNumAvailableProducts()) {
                        Product* selectedProduct = store.getProductByNumber(productNumber);
                        cart.addProduct(*selectedProduct);
                        std::cout << "Added " << selectedProduct->getName() << " to the cart.\n";
                    }
                    else {
                        throw InvalidProductNumberException();
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
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                std::cin.clear();  // Clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            }
        }
    };


    int main() {
        Interface* interface = nullptr;
        int i = 0;
        while (true) {
            try {
                if (i == 0) {
                    int option;
                    std::cout << "Select 1 for Admin Interface or 2 for User Interface \n";
                    std::cin >> option;
                    i = option;
                    if (i == 1) {
                        interface = new AdminInterface();
                    }
                    else if (i == 2) {
                        interface = new UserInterface();
                    }
                }
                if (interface) {
                    interface->run();
                    delete interface;
                    interface = nullptr;
                    i = 0;
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }