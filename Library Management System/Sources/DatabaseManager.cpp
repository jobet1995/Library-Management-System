#include "Headers/DatabaseManager.h"
#include <algorithm>

DatabaseManager::DatabaseManager() {}

// ================== Book operations ==================
void DatabaseManager::addBook(const Book& book) {
    books.push_back(book);
}

bool DatabaseManager::updateBook(const Book& book) {
    for (auto& b : books) {
        if (b.getId() == book.getId()) {
            b = book;
            return true;
        }
    }
    return false;
}

bool DatabaseManager::deleteBook(int bookId) {
    auto it = std::remove_if(books.begin(), books.end(), [bookId](const Book& b){ return b.getId() == bookId; });
    if (it != books.end()) {
        books.erase(it, books.end());
        return true;
    }
    return false;
}

std::vector<Book> DatabaseManager::getAllBooks() const {
    return books;
}

Book* DatabaseManager::getBookById(int bookId) {
    for (auto& b : books) {
        if (b.getId() == bookId) return &b;
    }
    return nullptr;
}

// ================== Member operations ==================
void DatabaseManager::addMember(const Member& member) {
    members.push_back(member);
}

bool DatabaseManager::updateMember(const Member& member) {
    for (auto& m : members) {
        if (m.getId() == member.getId()) {
            m = member;
            return true;
        }
    }
    return false;
}

bool DatabaseManager::deleteMember(int memberId) {
    auto it = std::remove_if(members.begin(), members.end(), [memberId](const Member& m){ return m.getId() == memberId; });
    if (it != members.end()) {
        members.erase(it, members.end());
        return true;
    }
    return false;
}

std::vector<Member> DatabaseManager::getAllMembers() const {
    return members;
}

Member* DatabaseManager::getMemberById(int memberId) {
    for (auto& m : members) {
        if (m.getId() == memberId) return &m;
    }
    return nullptr;
}

// ================== Borrow operations ==================
void DatabaseManager::addBorrow(const Borrow& borrow) {
    borrows.push_back(borrow);
}

bool DatabaseManager::updateBorrow(const Borrow& borrow) {
    for (auto& b : borrows) {
        if (b.getBorrowId() == borrow.getBorrowId()) {
            b = borrow;
            return true;
        }
    }
    return false;
}

bool DatabaseManager::deleteBorrow(int borrowId) {
    auto it = std::remove_if(borrows.begin(), borrows.end(), [borrowId](const Borrow& b){ return b.getBorrowId() == borrowId; });
    if (it != borrows.end()) {
        borrows.erase(it, borrows.end());
        return true;
    }
    return false;
}

std::vector<Borrow> DatabaseManager::getAllBorrows() const {
    return borrows;
}

Borrow* DatabaseManager::getBorrowById(int borrowId) {
    for (auto& b : borrows) {
        if (b.getBorrowId() == borrowId) return &b;
    }
    return nullptr;
}

// ================== User operations ==================
void DatabaseManager::addUser(const User& user) {
    users.push_back(user);
}

bool DatabaseManager::updateUser(const User& user) {
    for (auto& u : users) {
        if (u.getId() == user.getId()) {
            u = user;
            return true;
        }
    }
    return false;
}

bool DatabaseManager::deleteUser(int userId) {
    auto it = std::remove_if(users.begin(), users.end(), [userId](const User& u){ return u.getId() == userId; });
    if (it != users.end()) {
        users.erase(it, users.end());
        return true;
    }
    return false;
}

std::vector<User> DatabaseManager::getAllUsers() const {
    return users;
}

User* DatabaseManager::getUserById(int userId) {
    for (auto& u : users) {
        if (u.getId() == userId) return &u;
    }
    return nullptr;
}

// ================== Notification operations ==================
void DatabaseManager::addNotification(const std::string& message) {
    notifications.addNotification(message);
}

std::vector<Notification> DatabaseManager::getAllNotifications() const {
    return notifications.getAllNotifications();
}

std::vector<Notification> DatabaseManager::getUnreadNotifications() const {
    return notifications.getUnreadNotifications();
}

void DatabaseManager::markNotificationAsRead(int id) {
    notifications.markAsRead(id);
}

void DatabaseManager::clearAllNotifications() {
    notifications.clearAll();
}
