#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));
        
        float rate = static_cast<float>(std::atof(rateStr.c_str()));
        _database[date] = rate;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
    if (valueStr.empty()) return false;
    
    bool hasDot = false;
    for (size_t i = 0; i < valueStr.length(); ++i) {
        if (valueStr[i] == '-') {
            if (i != 0) return false;
        } else if (valueStr[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!isdigit(valueStr[i])) {
            if (i == valueStr.length() - 1 && valueStr[i] == 'f') continue;
            return false;
        }
    }

    char* end;
    value = static_cast<float>(std::strtod(valueStr.c_str(), &end));
    
    return true;
}

void BitcoinExchange::run(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        
        if (isFirstLine && line == "date | value") {
            isFirstLine = false;
            continue;
        }
        isFirstLine = false;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl; 
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _database.lower_bound(date);
        
        if (it == _database.end())
        {
             if (!_database.empty())
                 it--;
             else {
                 std::cerr << "Error: no data available." << std::endl;
                 continue;
             }
        }
        else if (it->first != date)
        {
            if (it != _database.begin())
                it--;
            else
            {
                 std::cerr << "Error: bad input => " << date << " (too early)" << std::endl;
                 continue;
            }
        }

        float result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}
