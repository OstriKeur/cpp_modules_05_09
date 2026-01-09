#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* DRILLING NOISES *" << std::endl;
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->target << "." << std::endl;
}
