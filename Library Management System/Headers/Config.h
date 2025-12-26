#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    static const std::string APP_NAME;
    static const std::string VERSION;
    static const int MAX_BORROW_DAYS;
    static const double LATE_FEE_PER_DAY;
    static const int MAX_BORROW_PER_MEMBER;
    static const std::string DEFAULT_COVER_IMAGE_PATH;
};

#endif
