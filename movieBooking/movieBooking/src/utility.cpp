#include "../include/Utility.h"

void drawHomePage()
{
	std::cout << "---CINEMABOOKING---" << std::endl;
	std::cout << "1.Login" << std::endl;
	std::cout << "2.Register" << std::endl;
	std::cout << "3.Exit" << std::endl;
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

		}
	}
	}
}