#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // For rand() in Robotomy

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

        // Pure virtual function makes this class abstract
        virtual void execute(const Bureaucrat &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
