#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.run(argc, argv);

    return 0;
}

