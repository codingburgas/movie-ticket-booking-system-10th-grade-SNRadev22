#include "../include/mainMenu.h"
#include "../include/users.h"

void selectMainMenu()
{
	switch (user.getRank())
	{
	case USER:
		mainMenuUser();
		break;
	case ADMIN:
		mainMenuAdmin();
		break;
	case MANAGER:
		mainMenuManager();
		break;
	}
}

void mainMenuUser()
{
	int choice;
	while (true)
	{
		std::cout << "---CINEMABOOKING---" << std::endl;
		std::cout << "1. Browse booking offers" << std::endl;
		std::cout << "2. See your bookings" << std::endl;
		std::cout << "3.Exit" << std::endl;
		std::cout << "What would you like to do today? ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:

			break;

		case 2:

			break;

		case 3:
			exit(0);
		}
	}
}

void mainMenuAdmin()
{
	int choice;
	while (true)
	{
		std::cout << "---CINEMABOOKING---" << std::endl;
		std::cout << "1. Add offers" << std::endl;
		std::cout << "2. Edit offers" << std::endl;
		std::cout << "3.Exit" << std::endl;
		std::cout << "What would you like to do today? ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:

			break;

		case 2:

			break;

		case 3:
			exit(0);
			break;
		}
	}
}

void mainMenuManager()
{
	int choice;
	while (true)
	{
		std::cout << "---CINEMABOOKING---" << std::endl;
		std::cout << "1. Add offers" << std::endl;
		std::cout << "2. Edit offers" << std::endl;
		std::cout << "3. Add cinema" << std::endl;
		std::cout << "4. Edit cinema" << std::endl;
		std::cout << "5.Exit" << std::endl;
		std::cout << "What would you like to do today? ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:

			break;

		case 2:

			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			exit(0);
			break;
		}
	}
}