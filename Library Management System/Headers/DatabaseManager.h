#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <vector>
#include "Book.h"
#include "Member.h"
#include "Borrow.h"
#include "User.h"
#include "NotificationManager.h"

class DatabaseManager {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Borrow> borrows;
    std::vector<User> users;
    NotificationManager notifications;

public:
    DatabaseManager();

    // Book operations
    void addBook(const Book& book);
    bool updateBook(const Book& book);
    bool deleteBook(int bookId);
    std::vector<Book> getAllBooks() const;
    Book* getBookById(int bookId);

    // Member operations
    void addMember(const Member& member);
    bool updateMember(const Member& member);
    bool deleteMember(int memberId);
    std::vector<Member> getAllMembers() const;
    Member* getMemberById(int memberId);

    // Borrow operations
    void addBorrow(const Borrow& borrow);
    bool updateBorrow(const Borrow& borrow);
    bool deleteBorrow(int borrowId);
    std::vector<Borrow> getAllBorrows() const;
    Borrow* getBorrowById(int borrowId);

    // User operations
    void addUser(const User& user);
    bool updateUser(const User& user);
    bool deleteUser(int userId);
    std::vector<User> getAllUsers() const;
    User* getUserById(int userId);

    // Notification operations
    void addNotification(const std::string& message);
    std::vector<Notification> getAllNotifications() const;
    std::vector<Notification> getUnreadNotifications() const;
    void markNotificationAsRead(int id);
    void clearAllNotifications();
};

#endif
