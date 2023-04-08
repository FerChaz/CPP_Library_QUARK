
#ifndef _LIBRARY_
#define _LIBRARY_

#include <string>
#include <vector>
#include "Member.h"
#include "Book.h"
#include "BookLoan.h"

class Library
{
private:
    std::vector<Member> members;
    std::vector<Book> books;
    std::vector<BookLoan> loans;


public:
    std::vector<Member> getMembers() const;
    std::vector<Book> getBooks() const;
    std::vector<BookLoan> getLoans() const;

    void addBook(Book newBook);
    void addMember(Member newMember);
    void addLoan(BookLoan newLoan);

    int getMembersQuantity() const;
    Book* getBookByISBN(std::string ISBN);
    Member* getMemberByID(int id);
};

#endif