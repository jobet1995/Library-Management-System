#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>

class User {
private:
    int id;
    std::string username;
    std::string passwordHash;
    std::string role;
    std::string email;
    bool isActive;
    std::time_t createdAt;
    std::time_t lastLogin;

public:
    User();
    User(int id, const std::string& username, const std::string& password,
         const std::string& role, const std::string& email, bool isActive = true);

    int getId() const;
    std::string getUsername() const;
    std::string getPasswordHash() const;
    std::string getRole() const;
    std::string getEmail() const;
    bool getIsActive() const;
    std::time_t getCreatedAt() const;
    std::time_t getLastLogin() const;

    void setUsername(const std::string& username);
    void setPasswordHash(const std::string& password);
    void setRole(const std::string& role);
    void setEmail(const std::string& email);
    void setIsActive(bool status);
    void setLastLogin(std::time_t loginTime);

    bool checkPassword(const std::string& password) const;
    void updateLoginTime();
    bool hasPermission(const std::string& requiredRole) const;
};

#endif