#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

// int main() {
//     // Test avec std::vector
//     std::cout << "--- Testing with std::vector ---" << std::endl;
//     std::vector<int> vec;
//     for (int i = 0; i < 5; ++i)
//         vec.push_back(i * 10); // 0, 10, 20, 30, 40

//     try {
//         std::cout << "Searching for 20... ";
//         easyfind(vec, 20);
//         std::cout << "Found!" << std::endl;

//         std::cout << "Searching for 42... ";
//         easyfind(vec, 42);
//         std::cout << "Found!" << std::endl;
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     std::cout << std::endl;

//     // Test avec std::list
//     std::cout << "--- Testing with std::list ---" << std::endl;
//     std::list<int> lst;
//     lst.push_back(100);
//     lst.push_back(200);
//     lst.push_back(300);

//     try {
//         std::cout << "Searching for 200... ";
//         easyfind(lst, 200);
//         std::cout << "Found!" << std::endl;

//         std::cout << "Searching for 500... ";
//         easyfind(lst, 500);
//         std::cout << "Found!" << std::endl;
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }

int main(void)
{
    std::vector<int> intvec;
    
    intvec.push_back(1);
    intvec.push_back(2);
    intvec.push_back(3);
    intvec.push_back(42);
    intvec.push_back(6);

    
    std::list<int> intlst;

    intlst.push_back(10);
    intlst.push_back(11);
    intlst.push_back(12);
    intlst.push_back(42);
    intlst.push_back(14);
    

    std::cout << "-----test 1------" << std::endl;
    try{
        std::vector<int>::iterator it1 = easyfind(intvec, 6);
        std::cout << "Found in vector: " << *it1 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "-----test 2------" << std::endl;
    try{
        std::vector<int>::iterator it2 = easyfind(intvec, 5);
        std::cout << "Found in vector: " << *it2 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "-----test 3------" << std::endl;
    try{
        std::list<int>::iterator it3 = easyfind(intlst, 42);
        std::cout << "Found in list: " << *it3 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    std::cout << "-----test 4------" << std::endl;
    try{
        std::list<int>::iterator it4 = easyfind(intlst, 13);
        std::cout << "Found in list: " << *it4 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
