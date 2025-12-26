#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include <ctime>

class Member {
private:
    int id;
    std::string name;
    std::string email;
    std::string contact;
    std::string address;
    std:: string membershipType;
    std::string profileImagePath;
    std::time_t joinedAt;
    std::vector<int> borrowedBooks;
    std::vector<int> history;

public:
    Member();
    Member(int id, const std::string& name, const std::string& email,
           const std::string& contact, const std::string& address,
           const std::string& membershipType,
           const std::string& profileImagePath = "");

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getContact() const;
    std::string getAddress() const;
    std::string getMembershipType() const;
    std::string getProfileImagePath() const;
    std::time_t getJoinedAt() const;
    std::vector<int> getBorrowedBooks() const;
    std::vector<int> getBorrowHistory() const;

    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setContact(const std::string& contact);
    void setAddress(const std::string& address);
    void setMembershipType(const std::string& type);
    void setProfileImagePath(const std::string& path);

    bool borrowBook(int bookId);
    bool returnBook(int bookId);
    void addToHistory(int bookId);

    int getCurrentBorrowCount() const;
    bool hasBorrowedBook(int bookId) const;
};
#endif