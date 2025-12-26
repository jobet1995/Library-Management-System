#include "Headers/InventoryManager.h"
#include <algorithm>

InventoryManager::InventoryManager() {}

void InventoryManager::addBook(const Book& book) {
    books.push_back(book);
}

bool InventoryManager::updateBook(const Book& book) {
    for (auto& b : books) {
        if (b.getId() == book.getId()) {
            b = book;
            return true;
        }
    }
    return false;
}

bool InventoryManager::removeBook(int bookId) {
    auto it = std::remove_if(books.begin(), books.end(), [bookId](const Book& b) { return b.getId() == bookId; });
    if (it != books.end()) {
        books.erase(it, books.end());
        return true;
    }
    return false;
}

Book* InventoryManager::getBookById(int bookId) {
    for (auto& b : books) {
        if (b.getId() == bookId) return &b;
    }
    return nullptr;
}

std::vector<Book> InventoryManager::getAllBooks() const {
    return books;
}

bool InventoryManager::borrowBook(int bookId, int memberId) {
    Book* book = getBookById(bookId);
    if (book && book->isAvailable() && !book->getIsReferenceOnly()) {
        book->borrowBook(memberId);
        return true;
    }
    return false;
}

bool InventoryManager::returnBook(int bookId, int memberId) {
    Book* book = getBookById(bookId);
    if (book) {
        return book->returnBook(memberId);
    }
    return false;
}

int InventoryManager::getTotalCopies(int bookId) const {
    for (const auto& b : books) {
        if (b.getId() == bookId) return b.getTotalCopies();
    }
    return 0;
}

int InventoryManager::getAvailableCopies(int bookId) const {
    for (const auto& b : books) {
        if (b.getId() == bookId) return b.getAvailableCopies();
    }
    return 0;
}

bool InventoryManager::isBookAvailable(int bookId) const {
    for (const auto& b : books) {
        if (b.getId() == bookId) return b.isAvailable();
    }
    return false;
}
