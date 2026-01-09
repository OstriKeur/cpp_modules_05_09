#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    // Test 1: Robotomy
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // Don't forget to delete!
    }

    // Test 2: Shrubbery
    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf)
    {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    // Test 3: Presidential
    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (ppf)
    {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    // Test 4: Unknown Form
    AForm* unknown;
    unknown = someRandomIntern.makeForm("unknown form", "Nobody");
    if (unknown)
        delete unknown;

    return 0;
}
