#include "Headers/Utils.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <regex>

int Utils::generateId() {
    static int idCounter = 1;
    return idCounter++;
}

std::string Utils::formatDate(std::time_t timestamp) {
    std::tm* tmPtr = std::localtime(&timestamp);
    std::stringstream ss;
    ss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::time_t Utils::parseDate(const std::string& dateStr, const std::string& format) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, format.c_str());
    return std::mktime(&tm);
}

bool Utils::isValidEmail(const std::string& email) {
    const std::regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return std::regex_match(email, pattern);
}

std::string Utils::toUpper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string Utils::toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
