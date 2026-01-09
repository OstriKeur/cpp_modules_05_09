#include <iostream>
#include "iter.hpp"

template<typename T>
void printElem(T& x){
	std::cout << x << std::endl;
}


template<typename T>
void printConstElem(const T& x){
	std::cout << x << " (const)" << std::endl;
}

template<typename T>
void minusss(T& x){
	x = x - 32;
}

int main(void){
	char arr[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};

	std::cout << "=== TEST 1: Char Array (Modifiable) ===" << std::endl;
	iter(arr, 7, printElem);

	std::cout << "--- Modifying elements (-32) ---" << std::endl;
	iter(arr, 7, minusss);
	iter(arr, 7, printElem);



	int tab[] = {12, 23 , 345, 3, 42, 24};

	std::cout << "\n=== TEST 2: Int Array (Modifiable) ===" << std::endl;
    iter(tab, 6, printElem);

	std::cout << "--- Modifying elements (-32) ---" << std::endl;
	iter(tab, 6, minusss);
    iter(tab, 6, printElem);



	const int constTab[] = {100, 200, 300};
	
	std::cout << "\n=== TEST 3: Const Int Array (Read-Only) ===" << std::endl;

	iter(constTab, 3, printConstElem);
    
    return 0;
}
