#include "Library.h"

std::vector<Member> Library::getMembers() const
{
    return members;
}

std::vector<Book> Library::getBooks() const
{
    return books;
}

std::vector<BookLoan> Library::getLoans() const
{
    return loans;
}

void Library::addBook(Book newBook)
{
    books.push_back(newBook);
}

void Library::addMember(Member newMember)
{
    members.push_back(newMember);
}

void Library::addLoan(BookLoan newLoan)
{
    loans.push_back(newLoan);
}

int Library::getMembersQuantity() const
{
    return static_cast<int>(members.size());
}

Book* Library::getBookByISBN(std::string ISBN)
{
    Book* bookToReturn = nullptr;
    for (size_t i = 0; i < books.size(); i++)
    {
        if (!books[i].getISBN().compare(ISBN))
        {
            bookToReturn = &books[i];
        }
    }

    return bookToReturn;
}

Member* Library::getMemberByID(int id)
{
    Member* memberToReturn = nullptr;
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].getID() == id) 
        {
            memberToReturn = &members[i];
        }
    }

    return memberToReturn;
}
