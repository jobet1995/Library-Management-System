#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include <ctime>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string isbn;
    std::string publisher;
    std::string category;
    std::string edition;
    int year;
    int totalCopies;
    int availableCopies;
    std::string coverImagePath;
    bool isReferenceOnly;
    std::vector<int> borrowerHistory;
public:
    Book();
    Book(int id, const std::string& title, const std::string& author,
        const std::string& isbn, const std::string& publisher,
        const std::string& category, const std::string& edition,
        int year, int totalCopies, const std::string& coverImagePath,
        bool isReferenceOnly = false);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    std::string getPublisher() const;
    std::string getCategory() const;
    std::string getEdition() const;
    int getYear() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;
    std::string getCoverImagePath() const;
    bool getIsReferenceOnly() const;
    std::vector<int> getBorrowerHistory() const;

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setISBN(const std::string& isbn);
    void setPublisher(const std::string& publisher);
    void setCategory(const std::string& category);
    void setEdition(const std::string& edition);
    void setYear(int year);
    void setTotalCopies(int copies);
    void setAvailableCopies(int copies);
    void setCoverImagePath(const std::string& path);
    void setIsReferenceOnly(bool referenceOnly);

    bool borrowBook(int memberId);
    bool returnBook(int memberId);
    bool isAvailable() const;
    void addToBorrowerHistory(int memberId);

};

#endif