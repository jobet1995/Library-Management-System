#include "Headers/User.h"
#include <ctime>
#include <string>
#include <functional>

User::User()
    : id(0), username(""), passwordHash(""), role(""), email(""), isActive(true),
      createdAt(std::time(nullptr)), lastLogin(0) {}

User::User(int id, const std::string& username, const std::string& password,
           const std::string& role, const std::string& email, bool isActive)
    : id(id), username(username), role(role), email(email), isActive(isActive),
      createdAt(std::time(nullptr)), lastLogin(0)
{
    std::hash<std::string> hasher;
    passwordHash = std::to_string(hasher(password));
}

int User::getId() const { return id; }
std::string User::getUsername() const { return username; }
std::string User::getPasswordHash() const { return passwordHash; }
std::string User::getRole() const { return role; }
std::string User::getEmail() const { return email; }
bool User::getIsActive() const { return isActive; }
std::time_t User::getCreatedAt() const { return createdAt; }
std::time_t User::getLastLogin() const { return lastLogin; }

void User::setUsername(const std::string& u) { username = u; }
void User::setPasswordHash(const std::string& password) {
    std::hash<std::string> hasher;
    passwordHash = std::to_string(hasher(password));
}
void User::setRole(const std::string& r) { role = r; }
void User::setEmail(const std::string& e) { email = e; }
void User::setIsActive(bool status) { isActive = status; }
void User::setLastLogin(std::time_t login) { lastLogin = login; }

bool User::checkPassword(const std::string& password) const {
    std::hash<std::string> hasher;
    return std::to_string(hasher(password)) == passwordHash;
}

void User::updateLoginTime() { lastLogin = std::time(nullptr); }

bool User::hasPermission(const std::string& requiredRole) const {
    return role == requiredRole || role == "Admin";
}
