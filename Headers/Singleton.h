#pragma once
#include "Interface.h"

class Singleton {
public:
    static Singleton& getInstance();
    Interface* getInterface();
    void setInterface(Interface* interface);

private:
    Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    Interface* currentInterface;
};
