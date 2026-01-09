#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) 
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{}

const std::string &AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << "AForm " << AForm.getName() 
        << ", signed: " << (AForm.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << AForm.getGradeToSign()
        << ", grade to execute: " << AForm.getGradeToExecute();
    return out;
}
