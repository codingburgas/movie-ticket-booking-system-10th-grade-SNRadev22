#include "../include/loginRgister.h"
#include "../include/cinema.h"
#include "../include/baseUser.h"
#include "../include/mainMenu.h"
#include "../include/Utility.h"
#include "../include/managerFunctions.h"
#include<fstream>
#include<string>
#include "../include/city.h"
#include "../include/user.h"
#include "../include/admin.h"

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
	std::cout << std::endl << "---LOGIN---" << std::endl;

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
			else if (baseUser.getRank() == ADMIN)
			{
				admin = Admin(baseUser);

			}
			else if (baseUser.getRank() == USER)
			{
				user = User(baseUser);
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
		std::cout << std::endl << "---REGISTER---" << std::endl;
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
	std::cout << std::endl << "---REGISTER---" << std::endl;
	std::cin.ignore();
	while (true)
	{
		std::cout << "Email: ";
		std::string email = getUserInput();
		baseUser.setEmail(email);
		if (exists("assets/accounts.txt", baseUser.getEmail()) || baseUser.getEmail().find("@") == std::string::npos || baseUser.getEmail().find(".") == std::string::npos)
		{
			std::cerr << "Email already exists or is invalid." << std::endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: ";
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
	std::cout << "Password: ";
	std::string password = getUserInput();
	baseUser.setPassword(password);

	baseUser.setRank("USER");

	addToFile("assets/accounts.txt", std::ios::app, baseUser.getEmail());
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getUsername());
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getPassword());
	addToFile("assets/accounts.txt", std::ios::app, std::string("USER"));

	selectMainMenu();
}

void drawRegisterAdmin()
{
	std::cout << std::endl << "---REGISTER---" << std::endl;
	std::cin.ignore();

	while (true)
	{
		std::cout << "Email: ";
		std::string email = getUserInput();
		baseUser.setEmail(email);
		if (exists("assets/accounts.txt", baseUser.getEmail()) || baseUser.getEmail().find("@") == std::string::npos || baseUser.getEmail().find(".") == std::string::npos)
		{
			std::cerr << "Email already exists or is invalid." << std::endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: ";
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
	std::cout << "Password: ";
	std::string password = getUserInput();
	baseUser.setPassword(password);

	std::string cinemaId;
	std::string cinemaName;

	while (true)
	{
		std::cout << "Cinema id: ";
		cinemaId = getUserInput();
		std::cout << "Cinema name: ";
		 cinemaName = getUserInput();
		if (baseUser.validAdmin("assets/cinemas.txt", cinemaId, cinemaName))
		{
			break;
		}
		else
		{
			std::cerr << "Invalid cinema ID or name." << std::endl;
		}

	}
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getEmail());
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, cinemaId);
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getUsername());
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getPassword());
	addToFile("assets/accounts.txt", std::ios::app, "ADMIN");
	admin = Admin(baseUser);
	admin.setCinema(admin.findWorkingCinema(cinemaId));

	selectMainMenu();
}

void drawRegisterManager()
{
	std::cout << std::endl << "---REGISTER---" << std::endl;
	std::cin.ignore();

	while (true)
	{
		std::cout << "Email: ";
		std::string email = getUserInput();
		baseUser.setEmail(email);
		if (exists("assets/accounts.txt", baseUser.getEmail()) || baseUser.getEmail().find("@") == std::string::npos || baseUser.getEmail().find(".") == std::string::npos)
		{
			std::cerr << "Email already exists or is invalid." << std::endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		std::cout << "Username: ";
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

	std::cout << "Password: ";
	std::string password = getUserInput();
	baseUser.setPassword(password);
	baseUser.setRank("MANAGER");

	addToFile("assets/accounts.txt", std::ios::app, baseUser.getEmail());
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, "");
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getUsername());
	addToFile("assets/accounts.txt", std::ios::app, baseUser.getPassword());
	addToFile("assets/accounts.txt", std::ios::app, "MANAGER");

	manager = Manager(baseUser);
	manager.addCinema();

	selectMainMenu();
}