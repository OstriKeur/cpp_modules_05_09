#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <list> 

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int argc, char** argv);

private:
    // Core logic hidden from header
    template <typename T>
    void sortContainer(T& container);
};

#endif
