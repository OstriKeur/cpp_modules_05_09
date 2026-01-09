#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cctype>

class RPN
{
private:
    std::stack<long> _stack;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void run(const std::string& expression);
};

#endif
