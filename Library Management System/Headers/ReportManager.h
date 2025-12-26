#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Borrow.h"
#include "User.h"

class ReportManager {
public:
    std::string generateAllBooksReport(const std::vector<Book>& books) const;
    std::string generateAllMembersReport(const std::vector<Member>& members) const;
    std::string generateAllBorrowsReport(const std::vector<Borrow>& borrows) const;
    std::string generateOverdueBorrowsReport(const std::vector<Borrow>& borrows) const;
    std::string generateAllUsersReport(const std::vector<User>& users) const;
};

#endif
