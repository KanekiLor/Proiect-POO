// AdminInterface.h
#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include "Interface.h"

class AdminInterface : public Interface {
public:
    void displayMenu() const override;
    void run() override;
    void specificFunction() const override;
};

#endif // ADMININTERFACE_H
