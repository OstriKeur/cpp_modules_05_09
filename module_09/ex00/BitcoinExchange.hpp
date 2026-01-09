#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

    void loadDatabase();
    std::string trim(const std::string& str);
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& valueStr, float& value);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void run(const std::string& filename);
};

#endif
