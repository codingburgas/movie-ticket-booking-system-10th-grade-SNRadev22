#include "../include/loginRgister.h"
#include "../include/cinema.h"
#include "../include/users.h"
#include<fstream>
#include<string>

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

	while (true)
	{
		std::cout << "Username: ";
		std::cin >> user.username;
		std::cout << std::endl;
		std::cout << "Password: ";
		std::cin >> user.password;

		if (!validAccount("assets/accounts.txt", user.username, user.password))
		{
			std::cerr << "Invalid username or password." << std::endl;
		}
		else
		{
			std::cout << "Login successful!" << std::endl;
			break;
		}
	}
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
	while (true)
	{
		std::cout << "Email: " << std::endl;
		user.email = getUserInput();
		if (exists("assets/accounts.txt", user.email))
		{
			std::cerr << "Email already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, user.email);
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: " << std::endl;
		user.username = getUserInput();
		if (exists("assets/accounts.txt", user.username))
		{
			std::cerr << "Username already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, user.username);
			break;
		}
	}
	std::cout << "Password: " << std::endl;
	user.password = getUserInput();
	addToFile("assets/accounts.txt", std::ios::app, user.password);

	user.userRank = User::USER;
	addToFile("assets/accounts.txt", std::ios::app, std::string("USER"));
}

void drawRegisterAdmin()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cin.ignore();

	while (true)
	{
		std::cout << "Email: " << std::endl;
		user.email = getUserInput();
		if (exists("assets/accounts.txt", user.email))
		{
			std::cerr << "Email already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, user.email);
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: " << std::endl;
		user.username = getUserInput();
		if (exists("assets/accounts.txt", user.username))
		{
			std::cerr << "Username already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, user.username);
			break;
		}
	}
	std::cout << "Password: " << std::endl;
	user.password = getUserInput();
	addToFile("assets/accounts.txt", std::ios::app, user.password);

	std::cout << "Cinema id: " << std::endl;
	addToFile("assets/accounts.txt", std::ios::app, user.password);

	user.userRank = User::ADMIN;
}

void drawRegisterManager()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cin.ignore();
	while (true)
	{
		std::cout << "Email: " << std::endl;
		user.email = getUserInput();
		if (exists("assets/accounts.txt", user.email))
		{
			std::cerr << "Email already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, user.email);
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: " << std::endl;
		user.username = getUserInput();
		if (exists("assets/accounts.txt", user.username))
		{
			std::cerr << "Username already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, user.username);
			break;
		}
	}
	std::cout << "Password: " << std::endl;
	user.password = getUserInput();
	addToFile("assets/accounts.txt", std::ios::app, user.password);

	std::cout << "Cinema id: " << std::endl;
	cinema.id = getUserInput();
	if (exists("assets/cinemas.txt", cinema.id))
	{
		std::cerr << "Cinema id already exists." << std::endl;
	}
	else
	{
		addToFile("assets/cinemas.txt", std::ios::app, cinema.id);
	}

	while (true)
	{
		std::cout << "Cinema name: " << std::endl;
		cinema.name = getUserInput();
		if (exists("assets/cinemas.txt", cinema.name))
		{
			std::cerr << "Cinema name already exists." << std::endl;
			return;
		}
		else
		{
			addToFile("assets/cinemas.txt", std::ios::app, cinema.name);
			break;
		}
	}

	std::cout << "Cinema city: " << std::endl;
	cinema.city = getUserInput();
	addToFile("assets/cinemas.txt", std::ios::app, cinema.city);

	std::cout << "Cinema location: " << std::endl;
	cinema.location = getUserInput();
	addToFile("assets/cinemas.txt", std::ios::app, cinema.location);

	user.userRank = User::MANAGER;
}