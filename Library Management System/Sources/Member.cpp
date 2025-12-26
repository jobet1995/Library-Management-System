#include "Headers/Member.h"
#include <algorithm>
#include <iostream>
#include <ctime>

Member::Member()
    : id(0), name(""), email(""), contact(""), address(""),
      membershipType("Regular"), profileImagePath(""), joinedAt(std::time(nullptr)) {}

Member::Member(int id, const std::string& name, const std::string& email,
               const std::string& contact, const std::string& address,
               const std::string& membershipType, const std::string& profileImagePath)
    : id(id), name(name), email(email), contact(contact), address(address),
      membershipType(membershipType), profileImagePath(profileImagePath),
      joinedAt(std::time(nullptr)) {}

int Member::getId() const { return id; }
std::string Member::getName() const { return name; }
std::string Member::getEmail() const { return email; }
std::string Member::getContact() const { return contact; }
std::string Member::getAddress() const { return address; }
std::string Member::getMembershipType() const { return membershipType; }
std::string Member::getProfileImagePath() const { return profileImagePath; }
std::time_t Member::getJoinedAt() const { return joinedAt; }
std::vector<int> Member::getBorrowedBooks() const { return borrowedBooks; }
std::vector<int> Member::getBorrowHistory() const { return history; }

void Member::setName(const std::string& n) { name = n; }
void Member::setEmail(const std::string& e) { email = e; }
void Member::setContact(const std::string& c) { contact = c; }
void Member::setAddress(const std::string& a) { address = a; }
void Member::setMembershipType(const std::string& type) { membershipType = type; }
void Member::setProfileImagePath(const std::string& path) { profileImagePath = path; }

bool Member::borrowBook(int bookId) {
    if(hasBorrowedBook(bookId)) {
        std::cout << "Book ID " << bookId << " is already borrowed by this member.\n";
        return false;
    }

    borrowedBooks.push_back(bookId);
    addToHistory(bookId);
    std::cout << "Book ID " << bookId << " successfully borrowed by Member ID: " << id << "\n";
    return true;
}

bool Member::returnBook(int bookId) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it == borrowedBooks.end()) {
        std::cout << "Book ID " << bookId << " is not currently borrowed by this member.\n";
        return false;
    }

    borrowedBooks.erase(it);
    std::cout << "Book ID " << bookId << " successfully returned by Member ID: " << id << "\n";
    return true;
}

void Member::addToHistory(int bookId) {
    history.push_back(bookId);
}

int Member::getCurrentBorrowCount() const {
    return borrowedBooks.size();
}

bool Member::hasBorrowedBook(int bookId) const {
    return std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId) != borrowedBooks.end();
}
