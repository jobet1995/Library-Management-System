#include "Headers/ReportManager.h"
#include <sstream>
#include <ctime>

std::string ReportManager::generateAllBooksReport(const std::vector<Book>& books) const {
    std::stringstream ss;
    ss << "=== All Books Report ===\n";
    for (const auto& b : books) {
        ss << "ID: " << b.getId()
           << ", Title: " << b.getTitle()
           << ", Author: " << b.getAuthor()
           << ", ISBN: " << b.getISBN()
           << ", Publisher: " << b.getPublisher()
           << ", Year: " << b.getYear()
           << ", Copies: " << b.getCopies()
           << ", Available: " << b.getAvailable()
           << "\n";
    }
    return ss.str();
}

std::string ReportManager::generateAllMembersReport(const std::vector<Member>& members) const {
    std::stringstream ss;
    ss << "=== All Members Report ===\n";
    for (const auto& m : members) {
        ss << "ID: " << m.getId()
           << ", Name: " << m.getName()
           << ", Email: " << m.getEmail()
           << ", Contact: " << m.getContact()
           << ", Address: " << m.getAddress()
           << ", Membership: " << m.getMembershipType()
           << "\n";
    }
    return ss.str();
}

std::string ReportManager::generateAllBorrowsReport(const std::vector<Borrow>& borrows) const {
    std::stringstream ss;
    ss << "=== All Borrows Report ===\n";
    for (const auto& b : borrows) {
        ss << "Borrow ID: " << b.getBorrowId()
           << ", Book ID: " << b.getBookId()
           << ", Member ID: " << b.getMemberId()
           << ", Borrow Date: " << b.getBorrowDate()
           << ", Due Date: " << b.getDueDate()
           << ", Return Date: " << b.getReturnDate()
           << ", Fine: " << b.getFine()
           << ", Returned: " << (b.getIsReturned() ? "Yes" : "No")
           << "\n";
    }
    return ss.str();
}

std::string ReportManager::generateOverdueBorrowsReport(const std::vector<Borrow>& borrows) const {
    std::stringstream ss;
    ss << "=== Overdue Borrows Report ===\n";
    std::time_t now = std::time(nullptr);
    for (const auto& b : borrows) {
        if (!b.getIsReturned() && b.getDueDate() < now) {
            ss << "Borrow ID: " << b.getBorrowId()
               << ", Book ID: " << b.getBookId()
               << ", Member ID: " << b.getMemberId()
               << ", Due Date: " << b.getDueDate()
               << "\n";
        }
    }
    return ss.str();
}

std::string ReportManager::generateAllUsersReport(const std::vector<User>& users) const {
    std::stringstream ss;
    ss << "=== All Users Report ===\n";
    for (const auto& u : users) {
        ss << "ID: " << u.getId()
           << ", Username: " << u.getUsername()
           << ", Role: " << u.getRole()
           << ", Email: " << u.getEmail()
           << ", Active: " << (u.getIsActive() ? "Yes" : "No")
           << "\n";
    }
    return ss.str();
}
