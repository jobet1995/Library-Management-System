#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <string>
#include <vector>
#include "User.h"

class AuthManager {
private:
    std::vector<User> users;
    User* currentUser;

public:
    AuthManager();

    void addUser(const User& user);
    User* login(const std::string& username, const std::string& password);
    void logout();
    bool isLoggedIn() const;
    User* getCurrentUser() const;
    bool checkPermission(const std::string& requiredRole) const;
};

#endif
