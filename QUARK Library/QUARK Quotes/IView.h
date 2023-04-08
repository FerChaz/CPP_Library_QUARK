#pragma once
#ifndef _IVIEW_
#define _IVIEW_

#include <string>

class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const std::string& text) = 0;

	const std::string STEP_MENU = "MenuPrincipal";

	const std::string STEP_BOOKS = "Libros";
	const std::string STEP_ADD_BOOK = "AddLibro";
	const std::string STEP_ADD_COPY = "AddEjemplar";

	const std::string STEP_MEMBERS = "Members";
	const std::string STEP_ADD_MEMBER = "AddMember";

	const std::string STEP_LOANS = "Loans";
	const std::string STEP_ADD_LOAN = "AddLoans";
	const std::string STEP_RETURN_LOAN = "ReturnLoans";

};

#endif