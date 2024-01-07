// Interface.h
#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    virtual void displayMenu() const = 0;
    virtual void run() = 0;
    virtual void specificFunction() const = 0;
    virtual ~Interface() {}
};

#endif // INTERFACE_H
