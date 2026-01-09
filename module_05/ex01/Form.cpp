#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) 
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{}

const std::string &Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
