#include "BookLoan.h"

BookLoan BookLoan::nullLoan = BookLoan();

std::string BookLoan::getBookISBN() const
{
    return borrowedCopy->getBookISBN();
}

std::string BookLoan::getMemberName() const
{
    return member->getFullName();
}

std::string BookLoan::getLoanDate() const
{
    return loanDate;
}

std::string BookLoan::getLoanState() const
{
    return loanState;
}

int BookLoan::getLoanId() const
{
    return loanID;
}

void BookLoan::setLoanState(std::string state)
{
    loanDate = state;
}

Copy* BookLoan::getBorrowedCopy() const
{
    return borrowedCopy;
}
