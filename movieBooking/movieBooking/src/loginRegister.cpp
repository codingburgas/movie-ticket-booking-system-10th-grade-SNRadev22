#include "../include/loginRgister.h"
#include "../include/users.h"
#include "users.cpp"
#include<fstream>
#include<string>

std::fstream accounts;

void drawHomePage()
{
	int choice;
	while (true)
	{
		std::cout << "---CINEMABOOKING---" << std::endl;
		std::cout << "1.Login" << std::endl;
		std::cout << "2.Register" << std::endl;
		std::cout << "3.Exit" << std::endl;
		std::cout << "What would you like to do today? ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			drawLoginPage();
			break;

		case 2:
			drawRegisterPage();
			break;

		case 3:
			break;
		}
	}
}

void drawLoginPage()
{
	std::cout << "---LOGIN---" << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
}

void drawRegisterPage()
{
	int choice;
	while (true)
	{
		std::cout << "---REGISTER---" << std::endl;
		std::cout << "1.As user" << std::endl;
		std::cout << "2.As admin " << std::endl;
		std::cout << "3.As manager " << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			drawRegisterUser();
			break;

		case 2:
			drawRegisterAdmin();
			break;

		case 3:
			drawRegisterManager();
			break;
		}
	}

}

void drawRegisterUser()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "Email: ";
	accounts.open("../assets/accounts.txt", std::ios::app);
	std::cin.ignore();
	std::getline(accounts, user.email);
	accounts.close();

	std::cout << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
}

void drawRegisterAdmin()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "Email: ";
	std::cout << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
	std::cout << std::endl;
	std::cout << "Cinema id: ";
}

void drawRegisterManager()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "Email: ";
	std::cout << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
	std::cout << std::endl;
	std::cout << "Cinema id: ";
	std::cout << std::endl;
	std::cout << "Cinema name: ";
	std::cout << std::endl;
	std::cout << "Cinema city: ";
	std::cout << std::endl;
	std::cout << "Cinema location: ";
}