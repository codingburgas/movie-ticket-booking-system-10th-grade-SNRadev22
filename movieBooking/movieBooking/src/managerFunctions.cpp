#include "../include/managerFunctions.h"
#include "../include/city.h"
#include <sstream>

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

void Manager::loadOwnedCinemas(const std::string fileName, std::string managerEmailToFInd)
{

	std::ifstream accountsFile(fileName);
	if (!accountsFile.is_open())
	{
		std::cerr << "Error while opening file: " << fileName << std::endl;
		return;
	}

	std::ifstream cinemaFile("assets/cinemas.txt");
	if (!cinemaFile.is_open())
	{
		std::cerr << "Error while opening file: assets/cinemas.txt" << std::endl;
		return;
	}

	bool found = false;
	std::string managerEmail;
	while (getline(accountsFile, managerEmail))
	{
		if (managerEmail == managerEmailToFInd)
		{
			found = true;
			break;
		}
	}
	if (found == true)
	{
		std::cout << "Manager with email " << managerEmailToFInd << " found." << std::endl;
		std::string line;
		if (getline(accountsFile, line))
		{
			std::istringstream iss(line);
			std::string idToFind;

			while (iss >> idToFind)
			{
				cinemaFile.clear();
				cinemaFile.seekg(0);

				std::string id, name, city, location, owner, hall, skipHalls;
				while (getline(cinemaFile, id))
				{
					getline(cinemaFile, skipHalls);
					getline(cinemaFile, name);
					getline(cinemaFile, city);
					getline(cinemaFile, location);
					getline(cinemaFile, owner);

					if (id == idToFind)
					{
						Cinema cinema;
						cinema.setId(id);
						cinema.setName(name);
						cinema.setCity(city);
						cinema.setLocation(location);
						cinema.setOwner(owner);
						cinema.loadHalls("assets/cinemas.txt", "assets/halls.txt");

						ownedCinemas.push_back(cinema);
						break;
					}
				}
			}
		}
	}
	else
	{
		std::cerr << "Manager with email " << managerEmailToFInd << " not found." << std::endl;
	}
		accountsFile.close();
		cinemaFile.close();
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
		displayCinemas();
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
			addFragmentToFile("assets/accounts.txt", manager.getEmail(), cinema.getId());
			addToFile("assets/cinemas.txt", std::ios::app, cinema.getId());
			addToFile("assets/cinemas.txt", std::ios::app, "");
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
		City currentCity;
		currentCity.setName(cinemaCity);
		currentCity.addCinema(cinema);
		addFragmentToFile("assets/cities.txt", cinemaCity, cinema.getId());
		cities.push_back(currentCity);
	}
	else
	{
		City& currentCity = findCity(cinemaCity);
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
	addToFile("assets/movies.txt", std::ios::app, movie.getTitle());

	std::cout << "Movie language: ";
	std::string movieLanguage = getUserInput();
	movie.setLanguage(movieLanguage);
	addToFile("assets/movies.txt", std::ios::app, movie.getLanguage());

	std::cout << "Movie genre: ";
	std::string movieGenre = getUserInput();
	movie.setGenre(movieGenre);
	std::cout << "Movie length (in minutes): ";
	addToFile("assets/movies.txt", std::ios::app, movie.getGenre());

	int movieLength;
	std::cin >> movieLength;
	movie.setLength(movieLength);
	addToFile("assets/movies.txt", std::ios::app, std::to_string(movie.getLength()));
	std::cin.ignore();

	std::cout << "Movie date (YYYY-MM-DD): ";
	std::string movieDate = getUserInput();
	movie.setDate(movieDate);
	std::cout << "Ticket price: ";
	float moviePrice;
	std::cin >> moviePrice;
	movie.setPrice(moviePrice);
	std::cin.ignore();
	addToFile("assets/movies.txt", std::ios::app, std::to_string(movie.getPrice()));

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
	addToFile("assets/movies.txt", std::ios::app, movie.getHall().getName());

	cinema.addMovie(movie);
}