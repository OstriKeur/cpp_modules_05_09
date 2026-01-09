#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    // Array of pairs: name -> member function pointer
    struct FormType {
        std::string name;
        AForm *(Intern::*creator)(const std::string &target);
    };

    FormType forms[] = {
        {"shrubbery creation", &Intern::makeShrubbery},
        {"robotomy request", &Intern::makeRobotomy},
        {"presidential pardon", &Intern::makePresidential}
    };

    for (int i = 0; i < 3; i++)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            // Syntax to call member function pointer: (object->*ptr)(args)
            return (this->*forms[i].creator)(target);
        }
    }

    std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    return NULL;
}
