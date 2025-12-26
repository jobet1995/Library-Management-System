#include "Headers/AuthManager.h"

AuthManager::AuthManager() : currentUser(nullptr) {}

void AuthManager::addUser(const User& user) {
    users.push_back(user);
}

User* AuthManager::login(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            currentUser = &user;
            currentUser->updateLoginTime();
            return currentUser;
        }
    }
    return nullptr;
}

void AuthManager::logout() {
    currentUser = nullptr;
}

bool AuthManager::isLoggedIn() const {
    return currentUser != nullptr;
}

User* AuthManager::getCurrentUser() const {
    return currentUser;
}

bool AuthManager::checkPermission(const std::string& requiredRole) const {
    if (!currentUser) return false;
    return currentUser->hasPermission(requiredRole);
}
