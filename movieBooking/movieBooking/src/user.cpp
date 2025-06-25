#include "../include/user.h"
#include <vector>
#include "../include/Utility.h"

User user;
City currentCity;

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
			getline(file, city);
		}

		std::string chosenCityName;
		std::cin.ignore();
		while (true)
		{
			chosenCityName = getUserInput();
			if (exists("assets/cities.txt", chosenCityName))
			{
				currentCity = currentCity.findCity(chosenCityName);
				browseCinemas(currentCity);
				file.close();
				break;
			}
			else
			{
				std::cout << "There are no cinemas in this city!" << std::endl;
			}
		}
	}
}

void User::browseCinemas(City city)
{
		cinema.displayCinemas(city.getCinemas());

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