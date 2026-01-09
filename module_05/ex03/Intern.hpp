#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
    private:
        AForm *makeShrubbery(const std::string &target);
        AForm *makeRobotomy(const std::string &target);
        AForm *makePresidential(const std::string &target);

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
