#include "RPN.hpp"
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::run(const std::string& expression)
{
    std::string token;
    std::stringstream ss(expression);

    while (ss >> token)
    {
        if (token.length() == 1 && !isdigit(token[0]))
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return;
            }

            long b = _stack.top();
            _stack.pop();
            long a = _stack.top();
            _stack.pop();

            if (token == "+")
                _stack.push(a + b);
            else if (token == "-")
                _stack.push(a - b);
            else if (token == "*")
                _stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cout << "Error" << std::endl;
                    return;
                }
                _stack.push(a / b);
            }
            else
            {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        else
        {
            if (token.length() > 1 || !isdigit(token[0]))
            {
                std::cout << "Error" << std::endl;
                return;
            }
            
            long num = std::atol(token.c_str());
            _stack.push(num);
        }
    }

    if (_stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}
