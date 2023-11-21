#include <iostream>
#include <vector>
enum Options_ {View_Products=1,Add_to_cart,View_Cart,Place_Order,Exit};
enum Options_2 {Add_Customer=1,Add_product};


class Product {
private:
    std::string name;
    double price;
    int stock;

public:
    Product(const std::string& n, double p, int s) : name(n), price(p), stock(s) {}
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }
};


class ShoppingCart {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }
    void displayCart() const {
        std::cout << "Shopping Cart:\n";
        for (const Product& product : products) {
            std::cout << product.getName() << " - " << product.getPrice() << " USD\n";
        }
    }
};


class Customer {
private:
    std::string name;
    std::string address;
public:
    Customer(const std::string& n, const std::string& a) : name(n), address(a) {}
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};


class Order {
private:
    Customer* customer;
    ShoppingCart* shoppingCart;

public:
    Order(Customer* c, ShoppingCart* cart) : customer(c), shoppingCart(cart) {}
    Customer* getCustomer() const { return customer; }
    ShoppingCart* getShoppingCart() const { return shoppingCart; }
};

class OnlineStore {
private:
    std::vector<Product> availableProducts;
    std::vector<Customer> customers;
    std::vector<Order> orders;

public:
    ///Functie unde vedem produsele valabile de pe site(afisam vectorul availableProducts
    void displayAvailableProducts() const {
        std::cout << "Available Products:\n";
        int i=0;
        for (const Product& product : availableProducts) {
            std::cout << ++i << "." << product.getName() << " - " << product.getPrice() << " RON " << product.getStock()
                      << " pcs.\n";
        }
      }

    Customer* addCustomer(const std::string& name, const std::string& address) {
        customers.push_back(Customer(name, address));
        return &customers.back();
    }
    Product* addProduct(const std::string& name, double price, int stock){
        availableProducts.push_back(Product(name,price,stock));
        return &availableProducts.back(); }
    Order* placeOrder(Customer* customer, ShoppingCart* cart) {
        orders.emplace_back(customer, cart);
        return &orders.back();
    }
};
///Interfata de Admin: Aceasta clasa a fost creeata pentru perspectiva programatorului
/// folosita pentru a adauga produs/clienti in magazinul nostru

class AdminInterface {
public:
    void displayMenu() const {
        std::cout << "Menu:\n";
        std::cout << "1. Add a new customer\n";
        std::cout << "2. Add a new product\n";
        std::cout << "3. Exit\n";
    }
///Functie de afisare continua a meniului
    void run() {
        int option;
        while (true) {
            displayMenu();
            std::cout << "Select an option: ";
            std::cin >> option;
            if (option == Add_Customer) {
                OnlineStore store;
                std::cout<<"Enter the name and the address of the client\n";
                std::string a,n;
                std::cin>>a>>n;
                store.addCustomer(n,a);
            }
            if(option == Add_product) {
                OnlineStore store;
                std::cout<<"Enter the name, the price, and the stock of the new product:\n";
                std::string n;
                double p;
                int s;
                std::cin>>n>>p>>s;
                store.addProduct(n,p,s);
            }
            if (option == Exit) {
                std::cout << "Goodbye!\n";
                break;
            } else {
                std::cout << "Option not implemented. Please choose again.\n";
            }
        }
    }
};

///Interfata pentru User: Din acest meniu proiectat pentru perspectiva clientului acesta poate vedea produsele
///valabile, sa le adauge in cosul de cumparaturi, sa isi vizualizeze cosul de cumparaturi si sa plaseze o comanda
class UserInterface {
public:
     void displayMenu() const {
        std::cout << "Menu:\n";
        std::cout << "1. View available products\n";
        std::cout << "2. Add a product to the cart\n";
        std::cout << "3. View shopping cart\n";
        std::cout << "4. Place an order\n";
        std::cout << "5. Exit\n";
    }

    void run() {
        int option;
        while (true) {
            displayMenu();
            std::cout << "Select an option: ";
            std::cin >> option;
            if (option == View_Products)
            {
                OnlineStore store;
                std::cout<<"Here are all the available products: \n";
                store.displayAvailableProducts();

            }
            if(option == Add_to_cart)
            {

            }
            if(option == View_Cart)
            {
                ShoppingCart S;
                S.displayCart();
            }
            if(option == Place_Order)
            {
                OnlineStore store;

            }
            if (option == Exit) {
                std::cout << "Goodbye!\n";
                break;
            } else {
                std::cout << "Option not implemented. Please choose again.\n";
            }
        }
    }
};

int main() {
    AdminInterface ai;
    UserInterface ui;
    int i=0;
    while(true)
    {
        if(i == 0)
        {
            int option;
            std::cout<<"Select 1 for Admin Interface or 2 for User Interface \n";
            std::cin>>option;
            i=option;
        }
        if(i == 1)
        {
            ai.run();
            i=0;
        }
        else if(i == 2)
        {
            ui.run();
            i=0;
        }
    }
}
