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
				Cinema cinema = city.findCinema(chosenCinema);
				browseMovies(cinema);
				break;
			}
			else
			{
				std::cout << "There are no cinemas with this name!" << std::endl;
			}
		}
	}

void User::browseMovies(Cinema cinema)
{
	cinema.displayMovies(cinema.getMovies());
	std::string chosenMovie;
	std::cin.ignore();
	while (true)
	{
		chosenMovie = getUserInput();
		if (exists("assets/movies.txt", chosenMovie))
		{
			// Logic to book a ticket or view details can be added here
			std::cout << "You have selected the movie: " << chosenMovie << std::endl;
			break;
		}
		else
		{
			std::cout << "There are no movies with this title!" << std::endl;
		}
	}
}