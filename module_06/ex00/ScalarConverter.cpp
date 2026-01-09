#include "ScalarConverter.hpp"
#include <cctype>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]);
}

static bool isInt(const std::string& literal) {
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+') i++;
    if (i == literal.length()) return false;
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    return true;
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    if (literal.find('f') == std::string::npos) return false; // Must have 'f'
    // Check if 'f' is at the end
    if (literal[literal.length() - 1] != 'f') return false;
    
    // Validate the number part
    size_t i = 0;
    bool dotFound = false;
    if (literal[i] == '-' || literal[i] == '+') i++;
    for (; i < literal.length() - 1; i++) { // Skip last 'f'
        if (literal[i] == '.') {
            if (dotFound) return false;
            dotFound = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
    size_t i = 0;
    bool dotFound = false;
    if (literal[i] == '-' || literal[i] == '+') i++;
    if (i == literal.length()) return false; // Just sign is not a double
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (dotFound) return false;
            dotFound = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return dotFound;
}

void ScalarConverter::convert(const std::string& literal) {
    char c_val = 0;
    int i_val = 0;
    float f_val = 0.0f;
    double d_val = 0.0;

    bool c_imp = false;
    bool i_imp = false;

    // Detect Type and parse
    if (isChar(literal)) {
        c_val = literal[0];
        i_val = static_cast<int>(c_val);
        f_val = static_cast<float>(c_val);
        d_val = static_cast<double>(c_val);
    } else if (isInt(literal)) {
        long l_val = std::strtol(literal.c_str(), NULL, 10);
        if (l_val > std::numeric_limits<int>::max() || l_val < std::numeric_limits<int>::min()) {
            i_imp = true;
            c_imp = true;
        } else {
            i_val = static_cast<int>(l_val);
            if (i_val < 0 || i_val > 127) c_imp = true;
            else c_val = static_cast<char>(i_val);
        }
        f_val = static_cast<float>(l_val);
        d_val = static_cast<double>(l_val);
    } else if (isFloat(literal)) {
        f_val = std::strtof(literal.c_str(), NULL);
        d_val = static_cast<double>(f_val);
        
        if (std::isnan(f_val) || std::isinf(f_val) || 
            f_val > static_cast<float>(std::numeric_limits<int>::max()) || 
            f_val < static_cast<float>(std::numeric_limits<int>::min())) {
            i_imp = true;
        } else {
            i_val = static_cast<int>(f_val);
        }

        if (std::isnan(f_val) || std::isinf(f_val) || f_val < 0.0f || f_val > 127.0f) {
            c_imp = true;
        } else {
            c_val = static_cast<char>(f_val);
        }
    } else if (isDouble(literal)) {
        d_val = std::strtod(literal.c_str(), NULL);
        f_val = static_cast<float>(d_val);

        if (std::isnan(d_val) || std::isinf(d_val) || 
            d_val > std::numeric_limits<int>::max() || 
            d_val < std::numeric_limits<int>::min()) {
            i_imp = true;
        } else {
            i_val = static_cast<int>(d_val);
        }

        if (std::isnan(d_val) || std::isinf(d_val) || d_val < 0.0 || d_val > 127.0) {
            c_imp = true;
        } else {
            c_val = static_cast<char>(d_val);
        }
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Output Char
    std::cout << "char: ";
    if (c_imp) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(c_val)) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << c_val << "'" << std::endl;
    }

    // Output Int
    std::cout << "int: ";
    if (i_imp) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << i_val << std::endl;
    }

    // Output Float
    std::cout << "float: ";
    if (std::isnan(f_val)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(f_val)) {
        std::cout << (f_val > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::stringstream ss;
        ss << f_val;
        std::string s = ss.str();
        if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) {
            s += ".0";
        }
        std::cout << s << "f" << std::endl;
    }

    // Output Double
    std::cout << "double: ";
    if (std::isnan(d_val)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(d_val)) {
        std::cout << (d_val > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::stringstream ss;
        ss << d_val;
        std::string s = ss.str();
        if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) {
            s += ".0";
        }
        std::cout << s << std::endl;
    }
}
