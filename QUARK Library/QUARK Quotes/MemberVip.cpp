#include "MemberVip.h"

bool MemberVip::canBorrow() const
{
	return borrowedCopies.size() == 3 ? false : true;
}