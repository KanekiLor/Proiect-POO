#include "../Headers/Singleton.h"

Singleton::Singleton() : currentInterface(nullptr) {}

Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}

Interface* Singleton::getInterface() {
    return currentInterface;
}

void Singleton::setInterface(Interface* interface) {
    currentInterface = interface;
}
