#include "Borrow.h"
#include <iostream>
#include <ctime>
#include <cmath>

Borrow::Borrow()
    : borrowId(0), bookId(0), memberId(0),
      borrowDate(std::time(nullptr)), dueDate(0),
      returnDate(0), fine(0.0), isReturned(false) {}

Borrow::Borrow(int borrowId, int bookId, int memberId, std::time_t borrowDate, int borrowDays)
    : borrowId(borrowId), bookId(bookId), memberId(memberId),
      borrowDate(borrowDate), returnDate(0), fine(0.0), isReturned(false) {
    dueDate = borrowDate + borrowDays * 24 * 60 * 60;
}

int Borrow::getBorrowId() const { return borrowId; }
int Borrow::getBookId() const { return bookId; }
int Borrow::getMemberId() const { return memberId; }
std::time_t Borrow::getBorrowDate() const { return borrowDate; }
std::time_t Borrow::getDueDate() const { return dueDate; }
std::time_t Borrow::getReturnDate() const { return returnDate; }
double Borrow::getFine() const { return fine; }
bool Borrow::getIsReturned() const { return isReturned; }

void Borrow::setBorrowDate(std::time_t date) { borrowDate = date; }
void Borrow::setDueDate(std::time_t date) { dueDate = date; }
void Borrow::setReturnDate(std::time_t date) { returnDate = date; }
void Borrow::setFine(double f) { fine = f; }
void Borrow::setIsReturned(bool status) { isReturned = status; }

bool Borrow::markAsReturned(std::time_t returnDateTime, double finePerDay) {
    if (isReturned) {
        std::cout << "Borrow ID " << borrowId << " is already returned.\n";
        return false;
    }

    returnDate = returnDateTime;
    isReturned = true;
    fine = calculateFine(finePerDay);

    std::cout << "Borrow ID " << borrowId << " marked as returned.\n";
    if (fine > 0.0)
        std::cout << "Fine due: $" << fine << "\n";

    return true;
}


double Borrow::calculateFine(double finePerDay) const {
    if (!isReturned) {
        std::time_t now = std::time(nullptr);
        int overdueDays = static_cast<int>(std::difftime(now, dueDate) / (24 * 60 * 60));
        return (overdueDays > 0) ? overdueDays * finePerDay : 0.0;
    } else {
        int overdueDays = static_cast<int>(std::difftime(returnDate, dueDate) / (24 * 60 * 60));
        return (overdueDays > 0) ? overdueDays * finePerDay : 0.0;
    }
}

bool Borrow::isOverdue() const {
    if (isReturned)
        return returnDate > dueDate;
    else {
        std::time_t now = std::time(nullptr);
        return now > dueDate;
    }
}

int Borrow::daysOverDue() const {
    std::time_t referenceTime = isReturned ? returnDate : std::time(nullptr);
    int overdueDays = static_cast<int>(std::difftime(referenceTime, dueDate) / (24 * 60 * 60));
    return (overdueDays > 0) ? overdueDays : 0;
}
