#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
    std::string name;
    int         id;
    double      value;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

