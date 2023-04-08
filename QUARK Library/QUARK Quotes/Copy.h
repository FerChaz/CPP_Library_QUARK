#pragma once
#ifndef _COPY_
#define _COPY_

#include <string>

class Copy
{
private:
	int editionNumber;
    std::string bookISBN;
    std::string location;

public:
    Copy() {}
    Copy(int editionNumber, std::string bookISBN, std::string location) : editionNumber(editionNumber), bookISBN(bookISBN), location(location) {}

    std::string getBookISBN() const;
};

#endif