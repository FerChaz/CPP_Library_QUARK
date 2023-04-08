#ifndef _BOOKLOAN_
#define _BOOKLOAN_

#include "Copy.h"
#include "Member.h"
#include <string>
#include <ctime>
#include <iostream>
#include <chrono>

class BookLoan
{
private:
    int loanID;
    Copy* borrowedCopy;
    Member* member;
    std::string loanState;
    std::string loanDate;

public:
    static BookLoan nullLoan;
    BookLoan() {}
    BookLoan(Copy* borrowedCopy, Member* member, int id) : borrowedCopy(borrowedCopy), member(member), loanState("PRESTADO"), loanID(id)
    {
        time_t now = time(NULL);
        //char *str = ctime(&now);
        char str[26] = {};
        ctime_s(str, 26, &now);

        loanDate = str;
    }

    std::string getBookISBN() const;
    std::string getMemberName() const;
    std::string getLoanDate() const;
    std::string getLoanState() const;
    int getLoanId() const;
    void setLoanState(std::string state);
    Copy* getBorrowedCopy() const;
};

#endif