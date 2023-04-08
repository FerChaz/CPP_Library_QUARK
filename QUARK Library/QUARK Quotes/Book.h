#ifndef _BOOK_
#define _BOOK_

#include <string>
#include <vector>
#include "Copy.h"

class Book
{
private:
    std::string name;
    std::string ISBN;
    std::string author;
    std::vector<Copy> copies;

public:
    static Book nullBook;
    Book() {}
    Book(std::string name, std::string ISBN, std::string author) :
        name(name), ISBN(ISBN), author(author) {}

    std::string getName() const;
    std::string getISBN() const;
    std::string getAuthor() const;
    int getCopiesQuantity() const;

    bool areCopiesAvailable() const;
    void addCopy(Copy newCopy);
    void returnCopy(Copy copyToReturn);
    Copy lendCopy();

    bool operator==(const Book& other) const {
        return (name == other.name && author == other.author && ISBN == other.ISBN);
    }
};

#endif