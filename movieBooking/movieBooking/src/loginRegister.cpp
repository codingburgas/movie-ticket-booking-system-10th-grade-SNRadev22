#include "../include/loginRgister.h"
#include "../include/cinema.h"
#include "../include/baseUser.h"
#include "../include/mainMenu.h"
#include "../include/Utility.h"
#include "../include/managerFunctions.h"
#include<fstream>
#include<string>
#include "../include/city.h"

BaseUser user;
City city;

void drawHomePage()
{
	city.loadCities("assets/cities.txt");
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
			exit(3);
			break;
		}
	}
}

void drawLoginPage()
{
	std::string username;
	std::string password;
	std::cout << "---LOGIN---" << std::endl;

	while (true)
	{
		std::cout << "Username: ";
		std::cin >> username;
		baseUser.setUsername(username);
		std::cout << std::endl;
		std::cout << "Password: ";
		std::cin >> password;
		baseUser.setPassword(password);

		if (!baseUser.validAccount("assets/accounts.txt", baseUser.getUsername(), baseUser.getPassword()))
		{
			std::cerr << "Invalid username or password." << std::endl;
		}
		else
		{
			std::cout << "Login successful!" << std::endl;
			if (baseUser.getRank() == MANAGER)
			{
				manager = Manager(baseUser);
				manager.loadOwnedCinemas("assets/accounts.txt", manager.getEmail());
			}
			break;
		}
	}
	selectMainMenu();
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
		std::string email = getUserInput();
		baseUser.setEmail(email);
		if (exists("assets/accounts.txt", baseUser.getEmail()))
		{
			std::cerr << "Email already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, baseUser.getEmail());
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: " << std::endl;
		std::string username = getUserInput();
		baseUser.setUsername(username);
		if (exists("assets/accounts.txt", baseUser.getUsername()))
		{
			std::cerr << "Username already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, baseUser.getUsername());
			break;
		}
	}
	std::cout << "Password: " << std::endl;
	std::string password = getUserInput();
	baseUser.setPassword(password);
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getPassword());

	baseUser.setRank("USER");
	addToFile("assets/accounts.txt", std::ios::app, std::string("USER"));

	selectMainMenu();
}

void drawRegisterAdmin()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cin.ignore();

	while (true)
	{
		std::cout << "Email: " << std::endl;
		std::string email = getUserInput();
		baseUser.setEmail(email);
		if (exists("assets/accounts.txt", baseUser.getEmail()))
		{
			std::cerr << "Email already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, baseUser.getEmail());
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: " << std::endl;
		std::string username = getUserInput();
		baseUser.setUsername(username);
		if (exists("assets/accounts.txt", baseUser.getUsername()))
		{
			std::cerr << "Username already exists." << std::endl;
		}
		else
		{
			addToFile("assets/accounts.txt", std::ios::app, baseUser.getUsername());
			break;
		}
	}
	std::cout << "Password: " << std::endl;
	std::string password = getUserInput();
	baseUser.setPassword(password);
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getPassword());

	while (true)
	{
		std::cout << "Cinema's id: ";
		std::string id;
		std::cin >> id;
		cinema.setId(id);
		std::cout << std::endl;

		std::cout << "Cinema's name: ";
		std::string name;
		getline(std::cin, name);
		cinema.setName(name);
		if (!cinema.validCinema("assets/cinemas.txt", cinema.getId(), cinema.getName()))
		{
			std::cerr << "Invalid cinema." << std::endl;
		}
		else
		{
			std::cout << "Login successful!" << std::endl;
			break;
		}
	}
	user.setRank("ADMIN");
	addToFile("assets/accounts.txt", std::ios::app, std::string("ADMIN"));

	selectMainMenu();
}

void drawRegisterManager()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cin.ignore();
	while (true)
	{
		std::cout << "Email: " << std::endl;
		std::string email = getUserInput();
		baseUser.setEmail(email);
		if (exists("assets/accounts.txt", baseUser.getEmail()))
		{
			std::cerr << "Email already exists." << std::endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: " << std::endl;
		std::string username = getUserInput();
		baseUser.setUsername(username);
		if (exists("assets/accounts.txt", baseUser.getUsername()))
		{
			std::cerr << "Username already exists." << std::endl;
		}
		else
		{
			break;
		}
	}
	std::cout << "Password: " << std::endl;
	std::string password = getUserInput();
	baseUser.setPassword(password);

	addToFile("assets/accounts.txt", std::ios::app, baseUser.getEmail());
	addToFile("assets/accounts.txt", std::ios::app, "");
	manager.addCinema();
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getUsername());
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getPassword());

	baseUser.setRank("MANAGER");
	addToFile("assets/accounts.txt", std::ios::app, std::string("MANAGER"));

	selectMainMenu();
}