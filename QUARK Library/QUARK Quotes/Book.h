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
    std::string autor;
    std::vector<Copy*> copies;

public:
    Book(std::string name, std::string ISBN, std::string autor) :
        name(name), ISBN(ISBN), autor(autor) {}

    std::string getName() const;
    std::string getISBN() const;
    std::string getAutor() const;
    int getCopiesQuantity() const;

    bool areCopiesAvailable() const;
    void addCopy(Copy* newCopy);
    void returnCopy(Copy* copyToReturn);
    Copy* lendCopy();
};

#endif