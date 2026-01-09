#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {
    _vec.reserve(N);
}

Span::Span(const Span& other) : _vec(other._vec), _N(other._N) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _vec = other._vec;
        _N = other._N;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_vec.size() >= _N) {
        throw std::overflow_error("Span is full");
    }
    _vec.push_back(number);
}

unsigned int Span::shortestSpan() {
    if (_vec.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        unsigned int span = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
    if (_vec.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    
    int minVal = *std::min_element(_vec.begin(), _vec.end());
    int maxVal = *std::max_element(_vec.begin(), _vec.end());
    
    return static_cast<unsigned int>(maxVal - minVal);
}

