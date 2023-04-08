#pragma once
#ifndef _VIEW_
#define _VIEW_

#include <string>
#include <map>
#include "Presenter.h"


class View : public IView
{
private:
	Presenter* m_presenter;
	void showMainMenu();

	void showBookMenu();
	void showBookMenu_AddBook();
	void showBookMenu_AddCopy();

	void showMemberMenu();
	void showMemberMenu_AddMember();

	void showLoansMenu();
	void showLoansMenu_AddLoan();
	void showLoansMenu_ReturnCopy();


	void runOption(const char* option, bool& exitCondition, std::string step);
	void loadMenu(std::string step);
public:
	View();
	~View() override;
	void showText(const std::string& text) override;
};

#endif