#include "Member.h"

using namespace std;

Member Member::nullMember = Member();

std::string Member::getFullName() const
{
	return name + " " + lastname;
}

int Member::getID() const
{
	return memberID;
}

bool Member::getIsVIP() const
{
	return isVIP;
}

bool Member::canBorrow() const
{
	return borrowedCopies.size() == 1 ? false : true;
}

void Member::requestCopy(Copy requestedCopy)
{
	borrowedCopies.push_back(requestedCopy);
}

void Member::returnCopy(Copy copyToReturn)
{
	int copyPosition = 0;
	for (int i = 0; i < borrowedCopies.size(); i++)
	{
		if (borrowedCopies[i].getBookISBN() == copyToReturn.getBookISBN()) break;
		copyPosition++;
	}
	
	borrowedCopies.erase(borrowedCopies.begin() + copyPosition);
}