#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <stdexcept>


const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";



Presenter::newQuotationData* data;


View::View()
{
	SetConsoleTitleW(L"Biblioteca | QUARK");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete m_presenter;
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}



void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;

	do
	{
		std::system("cls");
		showText("BIBLIOTECA | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Seleccione una opción del menu:");
		showText("");
		showText("1- Libros");
		showText("2- Socios");
		showText("3- Prestamos");
		showText("4- Salir");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_MENU);
		showText("");
	} while (!exitCondition);
}

//========== BOOK MENU
void View::showBookMenu()
{

	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls"); 
		showText("BIBLIOTECA | LIBROS");
		showText("---------------------------------------------------");
		showText("Presiona 4 (cuatro) para volver al menú principal");
		showText("---------------------------------------------------");
		
		m_presenter->getBookList();

		showText("---------------------------------------------------");
		showText("Selecciona una opción del menú:");
		showText("1- Agregar Libro");
		showText("2- Agregar Ejemplar");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_BOOKS);
		
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showBookMenu_AddBook()
{
	std::string bookName = "";
	std::string bookAutorName = "";
	std::string bookISBN = "";

	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | ADD BOOK");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 1: Ingresa el nombre del libro");
		showText("---------------------------------------------------");

		std::cin >> bookName;

		showText("---------------------------------------------------");
		showText("Paso 2: Ingresa el nombre del autor del libro");
		showText("---------------------------------------------------");

		std::cin >> bookAutorName;

		showText("---------------------------------------------------");
		showText("Paso 3: Ingresa el ISBN del libro");
		showText("---------------------------------------------------");

		std::cin >> bookISBN;

		showText("---------------------------------------------------");

		std::system("cls");

		m_presenter->addBook(bookName, bookISBN, bookAutorName);

	} while (!exitCondition);

	loadMenu(STEP_BOOKS);
}

void View::showBookMenu_AddCopy()
{
	std::string editionNumberText = "";
	int editionNumber;
	std::string bookLocation = "";
	std::string bookISBN = "";

	bool exitCondition = true;
	bool validData = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | AGREGAR EJEMPLAR");
		showText("---------------------------------------------------");
		showText("Paso 1: Ingresa el ISBN del libro");
		showText("---------------------------------------------------");

		std::cin >> bookISBN;

		if (m_presenter->getBookByISBN(bookISBN))
		{
			do {
				showText("---------------------------------------------------");
				showText("Paso 2: Ingresa el numero de edicion del ejemplar del libro");
				showText("---------------------------------------------------");

				std::cin >> editionNumberText;
				try {
					editionNumber = std::stoi(editionNumberText);
					validData = true;
				}
				catch (const std::invalid_argument& e) {
					showText("El dato ingresado es invalido.");
					validData = false;
				}
			} while (!validData);

			showText("---------------------------------------------------");
			showText("Paso 3: Ingresa la ubicacion del ejemplar del libro");
			showText("---------------------------------------------------");

			std::cin >> bookLocation;

			showText("---------------------------------------------------");

			std::system("cls");

			m_presenter->addCopy(bookISBN, bookLocation, editionNumber);

		}

		
	} while (!exitCondition);

	loadMenu(STEP_BOOKS);
}

//================

//========== MEMBER MENU
void View::showMemberMenu()
{

	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | SOCIOS");
		showText("---------------------------------------------------");
		showText("Presiona 4 (cuatro) para volver al menú principal");
		showText("---------------------------------------------------");
		m_presenter->getMemberList();
		showText("---------------------------------------------------");
		showText("Selecciona una opción del menú:");
		showText("1- Agregar Socio");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_MEMBERS);

	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showMemberMenu_AddMember()
{
	std::string name = "";
	std::string lastname = "";
	std::string vipText = "";
	std::string monthlyFeeText = "";
	bool isVIP = false;
	float monthlyFee = 0;

	bool exitCondition = true;
	bool validData = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | ADD MEMBER");
		showText("---------------------------------------------------");
		showText("Paso 1: Ingresa el nombre del nuevo socio");
		showText("---------------------------------------------------");

		std::cin >> name;

		showText("---------------------------------------------------");
		showText("Paso 2: Ingresa el apellido del nuevo socio");
		showText("---------------------------------------------------");

		std::cin >> lastname;

		do {
			showText("---------------------------------------------------");
			showText("Paso 3: ¿Es VIP? S-Si/N-No");
			showText("---------------------------------------------------");

			std::cin >> vipText;
			if (!vipText.compare("S") || !vipText.compare("Si"))
			{
				isVIP = true;
				validData = true;
			}
			else if (!vipText.compare("N") || !vipText.compare("No"))
			{
				isVIP = false;
				validData = true;
			}
			else {
				showText("El dato ingresado es invalido.");
				validData = false;
			}
		} while (!validData);
		showText("---------------------------------------------------");

		if (isVIP) {
			do {
				showText("---------------------------------------------------");
				showText("Paso 4: Ingresar cuota mensual");
				showText("---------------------------------------------------");

				std::cin >> monthlyFeeText;
				try {
					monthlyFee = std::stof(monthlyFeeText);
					validData = true;
				}
				catch (const std::invalid_argument& e) {
					showText("El dato ingresado es invalido.");
					validData = false;
				}
			} while (!validData);
		}

		std::system("cls");

		m_presenter->addMember(name, lastname, isVIP, monthlyFee);


		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MEMBERS);
}

//================

//========== LOANS MENU
void View::showLoansMenu()
{
	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | PRESTAMOS");
		showText("---------------------------------------------------");
		showText("Presiona 4 (cuatro) para volver al menú principal");
		showText("---------------------------------------------------");
		//prestamos list
		showText("---------------------------------------------------");
		showText("Selecciona una opción del menú:");
		showText("1- Realizar Prestamo");
		showText("2- Realizar Devolucion");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_LOANS);

	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showLoansMenu_AddLoan()
{
	std::string memberIDText = "";
	int memberID;
	std::string bookISBN = "";

	bool exitCondition = true;
	bool validData = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | REALIZAR PRESTAMO");
		
		do {
			showText("---------------------------------------------------");
			showText("Paso 1: Ingresa el ISBN del libro");
			showText("---------------------------------------------------");

			std::cin >> bookISBN;
			if (!m_presenter->checkForCopies(bookISBN))
			{
				exitCondition = false;
				break;
			}
			
		} while (!validData);

		if (!exitCondition) break;

		do {
			showText("---------------------------------------------------");
			showText("Paso 2: Ingresa el ID del socio");
			showText("---------------------------------------------------");

			std::cin >> memberIDText;
			try {
				memberID = std::stoi(memberIDText);
				validData = true;
			}
			catch (const std::invalid_argument& e) {
				showText("El dato ingresado es invalido.");
				validData = false;
			}

			if (!m_presenter->checkForMember(memberID))
			{
				exitCondition = false;
				break;
			}

		} while (!validData);

		if (exitCondition)
		{
			m_presenter->addLoan(memberID, bookISBN);
		}

	} while (!exitCondition);

	loadMenu(STEP_LOANS);
}

void View::showLoansMenu_ReturnCopy()
{
	std::string loanIDText = "";
	int loanID;

	bool exitCondition = true;
	bool validData = true;
	do
	{
		std::system("cls");
		showText("BIBLIOTECA | DEVOLVER EJEMPLAR");
		showText("---------------------------------------------------");
		do {
			showText("---------------------------------------------------");
			showText("Paso 1: Ingresa el ID del prestamo");
			showText("---------------------------------------------------");

			std::cin >> loanIDText;
			try {
				loanID = std::stoi(loanIDText);
				validData = true;
			}
			catch (const std::invalid_argument& e) {
				showText("El dato ingresado es invalido.");
				validData = false;
				continue;
			}


		} while (!validData);
		
		m_presenter->tryReturnLoan(loanID);

	} while (!exitCondition);

	loadMenu(STEP_LOANS);
}

//================


void View::runOption(const char* option, bool& exitCondition, std::string step)
{
	std::string str_option = std::string(option);
	if (str_option.compare("1") && str_option.compare("2") && str_option.compare("3") && str_option.compare("4"))
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
		return;
	}


	if (str_option == "1")
	{
		if (!step.compare(STEP_MENU))
		{
			loadMenu(STEP_BOOKS);
		}
		else if (!step.compare(STEP_BOOKS))
		{
			loadMenu(STEP_ADD_BOOK);
		}
		else if (!step.compare(STEP_MEMBERS))
		{
			loadMenu(STEP_ADD_MEMBER);
		}
		else if (!step.compare(STEP_LOANS))
		{
			loadMenu(STEP_ADD_LOAN);
		}
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		if (!step.compare(STEP_MENU))
		{
			loadMenu(STEP_MEMBERS);
		}
		else if (!step.compare(STEP_BOOKS))
		{
			loadMenu(STEP_ADD_COPY);
		}
		else if (!step.compare(STEP_LOANS))
		{
			loadMenu(STEP_RETURN_LOAN);
		}
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		if (!step.compare(STEP_MENU))
		{
			loadMenu(STEP_LOANS);
		}
		
		exitCondition = false;
	}
	else if (str_option == "4")
	{
		std::string exitMessage = "Volviendo al menú principal...";
		if (!step.compare(STEP_MENU))
		{
			exitMessage = "Saliendo...";
		}
		else if (!step.compare(STEP_BOOKS))
		{
			loadMenu(STEP_MENU);
		}
		else if (!step.compare(STEP_LOANS))
		{
			loadMenu(STEP_MENU);
		}

		showText(exitMessage);
		std::cin.get();
		exitCondition = true;
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}

void View::loadMenu(std::string step)
{
	if (!step.compare(STEP_MENU))
	{
		showMainMenu();
	}
	else if (!step.compare(STEP_BOOKS))
	{
		showBookMenu();
	}
	else if (!step.compare(STEP_ADD_BOOK))
	{
		showBookMenu_AddBook();
	}
	else if (!step.compare(STEP_ADD_COPY))
	{
		showBookMenu_AddCopy();
	}
	else if (!step.compare(STEP_MEMBERS))
	{
		showMemberMenu();
	}
	else if (!step.compare(STEP_ADD_MEMBER))
	{
		showMemberMenu_AddMember();
	}
	else if (!step.compare(STEP_LOANS))
	{
		showLoansMenu();
	}
	else if (!step.compare(STEP_ADD_LOAN))
	{
		showLoansMenu_AddLoan();
	}
	else if (!step.compare(STEP_RETURN_LOAN))
	{
		showLoansMenu_ReturnCopy();
	}
}

