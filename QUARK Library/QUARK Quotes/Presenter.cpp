#include "Presenter.h"
#include "MemberVip.h"
#include <typeinfo>
#include <ctime>
#include <stdexcept>


Presenter::Presenter(IView* view) : view(view)
{
	library = new Library();
	
}

Presenter::~Presenter()
{
	delete library;
}

 void Presenter::getBookList()
{
	 std::vector<Book> books = library->getBooks();
	 for (int i = 0; i < books.size(); i++)
	 {
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Titulo: ") + books[i].getName());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("ISBN: ") + books[i].getISBN());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Autor: ") + books[i].getAutor());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Ejemplares: ")+ std::to_string(books[i].getCopiesQuantity()));
		 view->showText("---------------------------------------------------");
		 view->showText("");
	 }
}

 void Presenter::addBook(std::string name, std::string ISBN, std::string autor)
 {
	 Book newBook = Book(name, ISBN, autor);
	 library->addBook(newBook);
 }

 bool Presenter::getBookByISBN(std::string ISBN)
 {
	 Book* book = library->getBookByISBN(ISBN);
	 return book == nullptr ? false : true;
 }

 void Presenter::addCopy(std::string ISBN, std::string location, int editionNumber)
 {
	 Book* book = library->getBookByISBN(ISBN);
	 Copy newCopy = Copy(editionNumber, ISBN, location);
	 book->addCopy(&newCopy);
 }

 void Presenter::getMemberList()
 {
	 std::vector<Member> members = library->getMembers();
	 for (int i = 0; i < members.size(); i++)
	 {
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Nombre: ") + members[i].getFullName());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Id: ") + std::to_string(members[i].getID()));
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Es Vip: ") + std::to_string(members[i].getIsVIP()));
		 view->showText("---------------------------------------------------");
		 view->showText("");
	 }
 }

 void Presenter::addMember(std::string name, std::string lastname, bool isVIP, float monthlyFee)
 {
	 if (isVIP)
	 {
		 Member newMember = MemberVip(name, lastname, static_cast<int>(library->getMembers().size()) + 1, monthlyFee);
		 library->addMember(newMember);
	 }
	 else {
		 Member newMember = Member(name, lastname, static_cast<int>(library->getMembers().size()) + 1);
		 library->addMember(newMember);
	 }
 }

 void Presenter::getLoansList()
 {
	 std::vector<BookLoan> loans = library->getLoans();
	 for (int i = 0; i < loans.size(); i++)
	 {
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Libro ISBN: ") + loans[i].getBookISBN());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Socio: ") + loans[i].getMemberName());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("Date: ") + loans[i].getLoanDate());
		 view->showText("---------------------------------------------------");
		 view->showText(std::string("State: ") + loans[i].getLoanState());
		 view->showText("---------------------------------------------------");
		 view->showText("");
	 }
 }

 void Presenter::addLoan(int memberID, std::string ISBN)
 {
	 Copy* copyToGive = library->getBookByISBN(ISBN)->lendCopy();
	 Member* memberToLend = library->getMemberByID(memberID);

	 BookLoan newLoan = BookLoan(copyToGive, memberToLend, static_cast<int>(library->getLoans().size()) + 1);
 }

 bool Presenter::checkForCopies(std::string ISBN)
 {
	 try {
		 return library->getBookByISBN(ISBN)->areCopiesAvailable();
	 }
	 catch (const std::invalid_argument& e){
		 return false;
	 }
	 
 }

 bool Presenter::checkForMember(int id)
 {
	 bool isMember = false;
	 std::vector<Member> members = library->getMembers();

	 for (int i = 0; i < members.size(); i++)
	 {
		 if (members[i].getID() == id)
		 {
			 isMember = true;
			 break;
		 }
	 }

	 return isMember;
 }

 bool Presenter::tryReturnLoan(int id)
 {
	 BookLoan loanToReturn = BookLoan::nullLoan;
	 std::vector<BookLoan> loans = library->getLoans();

	 for (int i = 0; i < loans.size(); i++)
	 {
		 if (loans[i].getLoanId() == id && !loans[i].getLoanState().compare("PRESTADO"))
		 {
			 loanToReturn = loans[i];
		 }
	 }

	 try {
		 loanToReturn.setLoanState("DEVUELTO");
		 Copy* copyToReturn = loanToReturn.getBorrowedCopy();
		 library->getBookByISBN(loanToReturn.getBookISBN())->addCopy(copyToReturn);
	 }
	 catch (const std::invalid_argument& e) {
		 return false;
	 }
 }

