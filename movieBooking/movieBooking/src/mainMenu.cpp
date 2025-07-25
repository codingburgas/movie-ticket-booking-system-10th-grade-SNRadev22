#include "../include/mainMenu.h"
#include "../include/baseUser.h"
#include "../include/managerFunctions.h"
#include "../include/user.h"

void selectMainMenu()
{
	switch (baseUser.getRank())
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
		std::cout << std::endl << "---CINEMABOOKING---" << std::endl;
		std::cout << "1. Browse booking offers" << std::endl;
		std::cout << "2. See your bookings" << std::endl;
		std::cout << "3. Search for a movie" << std::endl;
		std::cout << "4.Exit" << std::endl;
		std::cout << "What would you like to do today? ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			user.browseOffers();
			break;

		case 2:
			user.viewBookings();
			break;

		case 3:
		{
			std::fstream file;
			std::string cityName;

			file.open("assets/cities.txt");
			if (!file.is_open())
			{
				std::cerr << "Error while opening file!" << std::endl;
			}
			else
			{
				while (getline(file, cityName))
				{
					std::cout << cityName << std::endl;
					getline(file, cityName);
				}
				std::string chosenCityName = getUserInput();
				City& city = findCity(chosenCityName);

				user.searchMovies(city.getCinemas());
				break;
			}
		}
		case 4:
			exit(0);
			}
		}
}

		void mainMenuAdmin()
		{
			int choice;
			while (true)
			{
				std::cout << std::endl << "---CINEMABOOKING---" << std::endl;
				std::cout << "1. Add offers" << std::endl;
				std::cout << "2. Edit offers" << std::endl;
				std::cout << "3.Exit" << std::endl;
				std::cout << "What would you like to do today? ";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					manager.addMovie();
					break;

				case 2:
					manager.editMovie();
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
		std::cout << std::endl << "---CINEMABOOKING---" << std::endl;
		std::cout << "1. Add offers" << std::endl;
		std::cout << "2. Edit offers" << std::endl;
		std::cout << "3. Add halls" << std::endl;
		std::cout << "4. Edit halls" << std::endl;
		std::cout << "5. Add cinema" << std::endl;
		std::cout << "6. Edit cinema" << std::endl;
		std::cout << "7.Exit" << std::endl;
		std::cout << "What would you like to do today? ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			manager.addMovie();
			break;

		case 2:
			manager.editMovie();
			break;

		case 3:
			manager.addHalls();
			break;

		case 4:
			manager.editHall();
			break;

		case 5:
			manager.addCinema();
			break;
		case 6:
			manager.editCinema();
			break;

		case 7:
			exit(0);
			break;
		}
	}
}