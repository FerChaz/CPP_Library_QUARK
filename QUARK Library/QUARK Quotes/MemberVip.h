#pragma once
#ifndef _MEMBERVIP_
#define _MEMBERVIP_

#include "Member.h"
#include <vector>
#include <string>

class MemberVip : public Member
{
private:
    float monthlyFee;

public:
    MemberVip(std::string name, std::string lastname, int id, float monthlyFee) : Member(name, lastname, id), monthlyFee(monthlyFee) 
    {
        isVIP = true;
    }

    bool canBorrow() const override; 
};

#endif