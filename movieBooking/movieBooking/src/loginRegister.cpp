#include "../include/loginRgister.h"
#include "../include/cinema.h"
#include "../include/users.h"
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
	std::cin.ignore();
	std::cout << "Email: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.email);

	std::cout << "Username: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.username);

	std::cout << "Password: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.password);

	user.userRank = User::USER;
}

void drawRegisterAdmin()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cin.ignore();
	std::cout << "Email: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.email);

	std::cout << "Username: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.username);

	std::cout << "Password: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.password);

	std::cout << "Cinema id: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.password);

	user.userRank = User::ADMIN;
}

void drawRegisterManager()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cin.ignore();
	std::cout << "Email: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.email);

	std::cout << "Username: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.username);

	std::cout << "Password: " << std::endl;
	addToFile(accounts, "assets/accounts.txt", std::ios::app, user.password);

	std::cout << "Cinema id: " << std::endl;
	addToFile(accounts, "assets/cinemas.txt", std::ios::app, cinema.id);

	std::cout << "Cinema name: " << std::endl;
	addToFile(accounts, "assets/cinemas.txt", std::ios::app, cinema.name);

	std::cout << "Cinema city: " << std::endl;
	addToFile(accounts, "assets/cinemas.txt", std::ios::app, cinema.city);

	std::cout << "Cinema location: " << std::endl;
	addToFile(accounts, "assets/cinemas.txt", std::ios::app, cinema.location);

	user.userRank = User::MANAGER;
}