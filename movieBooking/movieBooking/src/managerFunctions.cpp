#include "../include/managerFunctions.h"
#include "../include/city.h"

Hall hall;
Manager manager;

void Manager::addHalls()
{
	std::cout << "---ADD HALLS---" << std::endl;
	std::cin.ignore();

	std::cout << "Hall name: ";
	std::string hallName = getUserInput();
	hall.setName(hallName);
	addToFile("assets/halls.txt", std::ios::app, hall.getName());

	std::cout << "Hall location: ";
	std::string hallLocation = getUserInput();
	hall.setLocation(hallLocation);
	addToFile("assets/halls.txt", std::ios::app, hall.getLocation());
}

void Manager::addCinema()
{
	City currentCity;

	std::cout << "---ADD CINEMA---" << std::endl;

	while (true)
	{
		std::cout << "Cinema id: " << std::endl;
		std::string cinemaId = getUserInput();
		cinema.setId(cinemaId);
		if (exists("assets/cinemas.txt", cinema.getId()))
		{
			std::cerr << "Cinema id already exists." << std::endl;
		}
		else
		{
			addToFile("assets/cinemas.txt", std::ios::app, cinema.getId());
			break;
		}
	}

	while (true)
	{
		std::cout << "Cinema name: " << std::endl;
		std::string cinemaName = getUserInput();
		cinema.setName(cinemaName);
		if (exists("assets/cinemas.txt", cinema.getName()))
		{
			std::cerr << "Cinema name already exists." << std::endl;
			return;
		}
		else
		{
			addToFile("assets/cinemas.txt", std::ios::app, cinema.getName());
			break;
		}
	}

	std::cout << "Cinema city: " << std::endl;
	std::string cinemaCity = getUserInput();
	cinema.setCity(cinemaCity);
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getCity());
	if (!exists("assets/cities.txt", cinema.getCity()))
	{
		addToFile("assets/cities.txt", std::ios::app, cinema.getCity());
		currentCity.setName(cinemaCity);
		currentCity.addCinema(cinema.getId());
		currentCity.addCinemaToFile("assets/cities.txt", cinemaCity, cinema.getId());
		cities.push_back(currentCity);
	}
	else
	{
		currentCity = currentCity.findCity(cinemaCity);
		currentCity.addCinema(cinema.getId());
		currentCity.addCinemaToFile("assets/cities.txt", cinemaCity, cinema.getId());
	}

	std::cout << "Cinema location: " << std::endl;
	std::string cinemaLocation = getUserInput();
	cinema.setLocation(cinemaLocation);
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getLocation());

	cinema.setOwner(baseUser.getUsername());
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getOwner());

	manager.ownedCinemas.push_back(cinema);
}