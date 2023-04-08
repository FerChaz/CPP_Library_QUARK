#pragma once

#ifndef _MEMBER_
#define _MEMBER_

#include "Copy.h"
#include <string>
#include <vector>

class Member
{ 
protected:
    std::string name;
    std::string lastname;
    int memberID;
    bool isVIP = false;
    std::vector<Copy> borrowedCopies;

public:
    Member(std::string name, std::string lastname, int id) : name(name), lastname(lastname), memberID(id) {}

    virtual std::string getFullName() const;
    virtual int getID() const; 
    virtual bool getIsVIP() const;

    virtual bool canBorrow() const;
    void requestCopy(Copy requestedCopy);
    void returnCopy(Copy copyToReturn);
};

#endif