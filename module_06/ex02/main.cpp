#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main() {
    std::srand(std::time(NULL));

    Base* instance = generate();
    
    std::cout << "Identify pointer: ";
    identify(instance);

    std::cout << "Identify reference: ";
    identify(*instance);

    delete instance;
    return 0;
}
