#include "Book.h"

std::string Book::getName() const
{
    return name;
}

std::string Book::getISBN() const
{
    return ISBN;
}

std::string Book::getAutor() const
{
    return autor;
}

int Book::getCopiesQuantity() const
{
    return copies.size();
}

bool Book::areCopiesAvailable() const
{
    return copies.size() >= 1 ? true : false;
}

void Book::addCopy(Copy* newCopy)
{
    copies.push_back(newCopy);
}

void Book::returnCopy(Copy* copyToReturn) 
{
    copies.push_back(copyToReturn);
}

Copy* Book::lendCopy()
{
    Copy* copyToLend = copies[copies.size() - 1];
    copies.erase(copies.end() - 1);
    return copyToLend;
}
