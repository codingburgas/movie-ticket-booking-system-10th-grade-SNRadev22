#include "../include/managerFunctions.h"

Hall hall;

void addHalls()
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

void addCinema()
{
	std::cout << "---ADD CINEMA---" << std::endl;

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

	std::cout << "Cinema location: " << std::endl;
	std::string cinemaLocation = getUserInput();
	cinema.setLocation(cinemaLocation);
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getLocation());

	cinema.setOwner(user.getUsername());
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getOwner());
}