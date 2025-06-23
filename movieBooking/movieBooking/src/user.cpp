#include "../include/user.h"
#include <vector>
#include "../include/Utility.h"

User user;

void User::browseOffers()
{
	std::fstream file;
	std::string city;

	file.open("assets/cities.txt");
	if (!file.is_open())
	{
		std::cerr << "Error while opening file!" << std::endl;
	}
	else
	{
		while (getline(file, city))
		{
			std::cout << city << std::endl;
		}

		std::string chosenCity;
		std::cin.ignore();
		while (true)
		{
			chosenCity = getUserInput();
			if (exists("assets/cities.txt", chosenCity))
			{
				break;
			}
			else
			{
				std::cout << "There are no cinemas in this city!" << std::endl;
			}
		}
	}
}

void User::browseCinemas()
{
	std::fstream file;
	std::string cinema;
	file.open("assets/cinemas.txt");
	if (!file.is_open())
	{
		std::cerr << "Error while opening file!" << std::endl;
	}
	else
	{
		while (getline(file, cinema))
		{
			std::cout << cinema << std::endl;
		}
		std::string chosenCinema;
		std::cin.ignore();
		while (true)
		{
			chosenCinema = getUserInput();
			if (exists("assets/cinemas.txt", chosenCinema))
			{
				break;
			}
			else
			{
				std::cout << "There are no cinemas with this name!" << std::endl;
			}
		}
	}
}