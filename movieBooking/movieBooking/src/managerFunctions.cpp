#include "../include/managerFunctions.h"
#include "../include/city.h"

Manager manager;

Cinema Manager::findCinema(std::string nameToFind)
{
	for (size_t i = 0; i < ownedCinemas.size(); ++i)
	{
		if (ownedCinemas[i].getName() == nameToFind)
		{
			return ownedCinemas[i];
		}
	}
}

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

	std::cout << "Number of seats: ";
	int numberOfSeats;
	std::cin >> numberOfSeats;
	hall.setNumberOfSeats(numberOfSeats);
	addToFile("assets/halls.txt", std::ios::app, std::to_string(hall.getNumberOfSeats()));

	if (manager.ownedCinemas.size() == 1)
	{
		cinema.addHall(hall);
		addFragmentToFile("assets/cinemas.txt", cinema.getId(), hall.getName());
	}
	else
	{
		std::string chosenCinema;

		displayCinemas();

		std::cout << "Select cinema by ID to add hall: ";
		std::cin >> chosenCinema;
		for (Cinema& cinema : manager.ownedCinemas)
		{
			if (cinema.getId() == chosenCinema)
			{
				cinema.addHall(hall);
				addFragmentToFile("assets/cinemas.txt", cinema.getId(), hall.getName());
				break;
			}
		}
	}
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
			addToFile("assets/halls.txt", std::ios::app, "\n");
			addToFile("assets/halls.txt", std::ios::app, "\n");
			addFragmentToFile("assets/accounts.txt", manager.getEmail(), cinema.getId());
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
		currentCity.addCinema(cinema);
		addFragmentToFile("assets/cities.txt", cinemaCity, cinema.getId());
		cities.push_back(currentCity);
	}
	else
	{
		currentCity = currentCity.findCity(cinemaCity);
		currentCity.addCinema(cinema);
		addFragmentToFile("assets/cities.txt", cinemaCity, cinema.getId());
	}

	std::cout << "Cinema location: " << std::endl;
	std::string cinemaLocation = getUserInput();
	cinema.setLocation(cinemaLocation);
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getLocation());

	cinema.setOwner(baseUser.getUsername());
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getOwner());

	manager.ownedCinemas.push_back(cinema);
}

void Manager::loadCinemas(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}
	Cinema cinema;
	std::string line;
	while (std::getline(file, line))
	{
		cinema.setId(line);
		std::getline(file, line);
		cinema.setName(line);
		std::getline(file, line);
		cinema.setCity(line);
		std::getline(file, line);
		cinema.setLocation(line);
		std::getline(file, line);
		cinema.setOwner(line);
		manager.ownedCinemas.push_back(cinema);
	}
	file.close();
}

void Manager::displayCinemas()
{
	for (Cinema cinema : ownedCinemas)
	{
		std::cout << "Cinema ID: " << cinema.getId() << std::endl;
		std::cout << "Cinema Name: " << cinema.getName() << std::endl;
		std::cout << "City: " << cinema.getCity() << std::endl;
		std::cout << "Location: " << cinema.getLocation() << std::endl;
	}
}

void Manager::addMovie()
{
	std::cout << "---ADD MOVIE---" << std::endl;
	std::cin.ignore();

	std::cout << "Movie title: ";
	std::string movieTitle = getUserInput();
	movie.setTitle(movieTitle);
	std::cout << "Movie language: ";
	std::string movieLanguage = getUserInput();
	movie.setLanguage(movieLanguage);
	std::cout << "Movie genre: ";
	std::string movieGenre = getUserInput();
	movie.setGenre(movieGenre);
	std::cout << "Movie length (in minutes): ";
	int movieLength;
	std::cin >> movieLength;
	movie.setLength(movieLength);
	std::cin.ignore();
	std::cout << "Movie date (YYYY-MM-DD): ";
	std::string movieDate = getUserInput();
	movie.setDate(movieDate);
	std::cout << "Ticket price: ";
	float moviePrice;
	std::cin >> moviePrice;
	movie.setPrice(moviePrice);
	std::cin.ignore();

	Cinema cinema;
	cinema.displayCinemas(manager.ownedCinemas);
	std::cout << "Select cinema by name: " << std::endl;
	std::string cinemaName = getUserInput();
	cinema = findCinema(cinemaName);
	std::cout << "Select hall by name: " << std::endl;
	std::string hallName = getUserInput();
	Hall currentHall = cinema.findHall(hallName);
	if (currentHall.getName().empty())
	{
		std::cerr << "Hall not found in the selected cinema." << std::endl;
		return;
	}
	movie.setHall(currentHall);
	addToFile("assets/movies.txt", std::ios::app, movie.getTitle());
	addToFile("assets/movies.txt", std::ios::app, std::to_string(movie.getLength()));
	addToFile("assets/movies.txt", std::ios::app, movie.getLanguage());
	addToFile("assets/movies.txt", std::ios::app, movie.getGenre());
	addToFile("assets/movies.txt", std::ios::app, movie.getDate());
	addToFile("assets/movies.txt", std::ios::app, std::to_string(movie.getPrice()));
	addToFile("assets/movies.txt", std::ios::app, movie.getHall().getName());
}