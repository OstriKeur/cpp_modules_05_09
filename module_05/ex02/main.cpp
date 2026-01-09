#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL)); // Seed for robotomy

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 140);

    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    // Test Shrubbery
    std::cout << "\n--- Shrubbery ---" << std::endl;
    intern.signForm(shrub);
    intern.executeForm(shrub); // Should succeed (exec 137 > 140? No wait. Exec is 137. Intern is 140 (lower). Should fail.)
    boss.executeForm(shrub);

    // Test Robotomy
    std::cout << "\n--- Robotomy ---" << std::endl;
    boss.signForm(robo);
    boss.executeForm(robo); // 50% chance

    // Test Pardon
    std::cout << "\n--- Pardon ---" << std::endl;
    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}
