#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other); // On appelle l'opérateur de la classe de base
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file((this->target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "   ^   " << std::endl;
        file << "  /|\\  " << std::endl;
        file << " /|||\\ " << std::endl;
        file << "   |   " << std::endl;
        file.close();
    }
}
