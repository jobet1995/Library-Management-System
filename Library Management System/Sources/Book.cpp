#include "Headers/Books.h"
#include <algorithm>
#include <iostream>

Book::Book()
    : id(0), title(""), author(""), isbn(""), publisher(""), category(""),
      edition(""), year(0), totalCopies(0), availableCopies(0), coverImagePath(""),
      isReferenceOnly(false) {}

Book::Book(int id, const std::string& title, const std::string& author,
           const std::string& isbn, const std::string& publisher,
           const std::string& category, const std::string& edition,
           int year, int totalCopies, const std::string& coverImagePath,
           bool isReferenceOnly)
    : id(id), title(title), author(author), isbn(isbn), publisher(publisher),
      category(category), edition(edition), year(year), totalCopies(totalCopies),
      availableCopies(totalCopies), coverImagePath(coverImagePath),
      isReferenceOnly(isReferenceOnly) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return isbn; }
std::string Book::getPublisher() const { return publisher; }
std::string Book::getCategory() const { return category; }
std::string Book::getEdition() const { return edition; }
int Book::getYear() const { return year; }
int Book::getTotalCopies() const { return totalCopies; }
int Book::getAvailableCopies() const { return availableCopies; }
std::string Book::getCoverImagePath() const { return coverImagePath; }
bool Book::getIsReferenceOnly() const { return isReferenceOnly; }
std::vector<int> Book::getBorrowerHistory() const { return borrowerHistory; }

void Book::setTitle(const std::string& t) { title = t; }
void Book::setAuthor(const std::string& a) { author = a; }
void Book::setISBN(const std::string& i) { isbn = i; }
void Book::setPublisher(const std::string& p) { publisher = p; }
void Book::setCategory(const std::string& c) { category = c; }
void Book::setEdition(const std::string& e) { edition = e; }
void Book::setYear(int y) { year = y; }
void Book::setTotalCopies(int copies) {
    totalCopies = copies;
    if (availableCopies > totalCopies)
        availableCopies = totalCopies;
}
void Book::setAvailableCopies(int copies) {
    availableCopies = std::min(copies, totalCopies);
}
void Book::setCoverImagePath(const std::string& path) { coverImagePath = path; }
void Book::setIsReferenceOnly(bool referenceOnly) { isReferenceOnly = referenceOnly; }

bool Book::isAvailable() const {
    return availableCopies > 0 && !isReferenceOnly;
}

bool Book::borrowBook(int memberId) {
    if(!isAvailable()) {
        std::cout << "Book \"" << title << "\" is not available for borrowing.\n";
        return false;
    }

    --availableCopies;
    addToBorrowerHistory(memberId);
    std::cout << "Book \"" << title << "\" borrowed successfully by Member ID: " << memberId << "\n";
    return true;
}

bool Book::returnBook(int memberId) {
    if(availableCopies >= totalCopies) {
        std::cout << "All copies of \"" << title << "\" are already in the library.\n";
        return false;
    }

    ++availableCopies;
    std::cout << "Book \"" << title << "\" returned successfully by Member ID: " << memberId << "\n";
    return true;
}

void Book::addToBorrowerHistory(int memberId) {
    borrowerHistory.push_back(memberId);
}