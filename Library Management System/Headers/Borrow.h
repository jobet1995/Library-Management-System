#ifndef BORROW_H
#define BORROW_H

#include <string>
#include <ctime>

class Borrow {
private:
    int borrowId;
    int bookId;
    int memberId;
    std::time_t borrowDate;
    std::time_t dueDate;
    std::time_t returnDate;
    double fine;
    bool isReturned;

public:
    Borrow();
    Borrow(int borrowId, int bookId, int memberId, std::time_t borrowDate, int borrowDays = 14);

    int getBorrowId() const;
    int getBookId() const;
    int getMemberId() const;
    std::time_t getBorrowDate() const;
    std::time_t getDueDate() const;
    std::time_t getReturnDate() const;
    double getFine() const;
    bool getIsReturned() const;

    void setBorrowDate(std::time_t date);
    void setDueDate(std::time_t date);
    void setReturnDate(std::time_t date);
    void setFine(double f);
    void setIsReturned(bool status);

    bool markAsReturned(std::time_t returnDate, double finePerDay = 0.0);
    double calculateFine(double finePerDay = 0.0) const; 
    bool isOverdue() const;    
    int daysOverDue() const;
};
#endif
