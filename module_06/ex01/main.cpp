#include "Serializer.hpp"

int main() {
    Data myData;
    myData.name = "Test Data";
    myData.id = 42;
    myData.value = 3.14159;

    std::cout << "Original Data Address: " << &myData << std::endl;
    std::cout << "Data: " << myData.name << ", " << myData.id << ", " << myData.value << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;

    if (deserializedData == &myData) {
        std::cout << "Success! The pointers are equal." << std::endl;
        std::cout << "Deserialized Data: " << deserializedData->name << ", " << deserializedData->id << ", " << deserializedData->value << std::endl;
    } else {
        std::cout << "Error! The pointers are not equal." << std::endl;
    }

    return 0;
}

