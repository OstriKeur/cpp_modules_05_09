#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>

int main(void)
{
    std::cout << "--- Basic Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test (Full) ---" << std::endl;
    try {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test (Not enough numbers) ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(1);
        sp.shortestSpan();
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Large Scale Test (10,000 numbers) ---" << std::endl;
    try {
        std::srand(std::time(NULL));
        Span sp(10000);
        std::vector<int> randomNumbers;
        for (int i = 0; i < 10000; ++i) {
            randomNumbers.push_back(std::rand());
        }
        
        // Testing range addNumber
        sp.addNumber(randomNumbers.begin(), randomNumbers.end());
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}


// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }
