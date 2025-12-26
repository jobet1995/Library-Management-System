#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ctime>

class Utils {
public:
    static std::string formatDate(std::time_t timestamp);
    static std::time_t parseDate(const std::string& dateStr, const std::string& format = "%Y-%m-%d");
    static int generateId();
    static bool isValidEmail(const std::string& email);
    static std::string toUpper(const std::string& str);
    static std::string toLower(const std::string& str);
};

#endif
