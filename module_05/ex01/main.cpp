#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 150);
        
        Form formA("FormA", 3, 5); // Needs grade 3 to sign
        Form formB("FormB", 1, 5); // Needs grade 1 to sign

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        // Alice (grade 2) tries to sign FormA (needs 3) -> Success
        alice.signForm(formA);
        std::cout << formA << std::endl;

        // Alice (grade 2) tries to sign FormB (needs 1) -> Fail
        alice.signForm(formB);
        
        // Bob (grade 150) tries to sign FormA (needs 3) -> Fail
        bob.signForm(formA);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
