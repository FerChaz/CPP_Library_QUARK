#pragma once
#ifndef _PRESENTER_
#define _PRESENTER_

#include "IView.h"
#include "Library.h"
#include <string>

class Presenter
{
private:
	IView* view;
	Library* library;
public: 
	struct newQuotationData {
		bool garmentFeature1;
		bool garmentFeature2;
		bool garmentIsPremium;
		std::string garmentString;
		float unitPrice;
		int quantity;
	};

	Presenter(IView* view);
	~Presenter();


	void getBookList();
	void addBook(std::string name, std::string ISBN, std::string autor);
	bool getBookByISBN(std::string ISBN);
	void addCopy(std::string ISBN, std::string location, int editionNumber);

	void getMemberList();
	void addMember(std::string name, std::string lastname, bool isVIP, float monthlyFee);

	void getLoansList();
	void addLoan(int memberID, std::string ISBN);
	bool checkForCopies(std::string ISBN);
	bool checkForMember(int id);
	bool tryReturnLoan(int id);

	

	
};

#endif