#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("Alice", 3);
        std::cout << b1 << std::endl;
        
        b1.incrementGrade(); // On incrémente (3 - 1 = 2)
        std::cout << "After increment: " << b1 << std::endl; // Devrait afficher 2
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        
        // This should throw
        b2.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        // Invalid construction
        Bureaucrat b3("Charlie", 0);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        // Invalid construction
        Bureaucrat b4("Dave", 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
