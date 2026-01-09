#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> _vec;
        unsigned int _N;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end) {
            if (std::distance(begin, end) + _vec.size() > _N) {
                throw std::overflow_error("Span is full");
            }
            _vec.insert(_vec.end(), begin, end);
        }

        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif
