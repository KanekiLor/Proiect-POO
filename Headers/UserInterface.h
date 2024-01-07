// UserInterface.h
#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "OnlineStore.h"
#include "Interface.h"

class UserInterface : public Interface {
public:
    void displayMenu() const override;
    void run() override;
    void specificFunction() const override;  // Suprascrieți metoda
    void viewAvailableProducts(OnlineStore& store) const;
    void viewShoppingCart(const ShoppingCart& cart) const;
    void placeOrder(OnlineStore &store, ShoppingCart &cart);
};

#endif // USERINTERFACE_H
