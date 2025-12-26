#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <vector>
#include "Book.h"

class InventoryManager {
private:
    std::vector<Book> books;

public:
    InventoryManager();

    void addBook(const Book& book);
    bool updateBook(const Book& book);
    bool removeBook(int bookId);
    Book* getBookById(int bookId);
    std::vector<Book> getAllBooks() const;

    bool borrowBook(int bookId, int memberId);
    bool returnBook(int bookId, int memberId);

    int getTotalCopies(int bookId) const;
    int getAvailableCopies(int bookId) const;
    bool isBookAvailable(int bookId) const;
};

#endif
