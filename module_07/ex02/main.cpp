#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    // --- TESTS SUPPLEMENTAIRES ---
    std::cout << "\n--- Tests Supplementaires ---\n" << std::endl;

    // 1. Test Constructeur par defaut
    std::cout << "Test 1: Constructeur par defaut et size()" << std::endl;
    Array<int> emptyArray;
    std::cout << "Taille attendue: 0, Taille reelle: " << emptyArray.size() << std::endl;

    // 2. Test de l'Operateur d'assignation (=)
    std::cout << "\nTest 2: Operateur d'assignation" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++) a[i] = i;
    
    Array<int> b(10);
    b = a; // Appel explicite de operator=
    
    std::cout << "Taille de b apres assignation (doit etre 5): " << b.size() << std::endl;
    b[0] = 42; // On modifie la copie
    std::cout << "a[0] (doit rester 0): " << a[0] << std::endl;
    std::cout << "b[0] (doit etre 42): " << b[0] << std::endl;

    // 3. Test avec type complexe (std::string)
    std::cout << "\nTest 3: Tableau de strings" << std::endl;
    Array<std::string> strArray(2);
    strArray[0] = "Hello";
    strArray[1] = "World";
    std::cout << strArray[0] << " " << strArray[1] << std::endl;

    return 0;
}
