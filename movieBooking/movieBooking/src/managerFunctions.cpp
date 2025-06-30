#include "../include/managerFunctions.h"
#include "../include/city.h"
#include <sstream>

Manager manager;

Cinema& Manager::findCinema(std::string nameToFind)
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
						cinema.loadMovies("assets/cinemas.txt", "assets/movies.txt");

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
	std::cout << std::endl << "---ADD HALLS---" << std::endl;
	std::cin.ignore();

	std::cout << "Hall id: ";
	std::string hallId = getUserInput();
	hall.setId(hallId);
	addToFile("assets/halls.txt", std::ios::app, hall.getId());

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

	std::cout << "Now you'll add the seat layout! " << std::endl;
	hall.setLayout();

	if (this->ownedCinemas.size() == 1)
	{
		displayCinemas();
		manager.ownedCinemas[0].addHall(hall);
		addFragmentToFile("assets/cinemas.txt", cinema.getId(), hall.getId(), 0);
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
				addFragmentToFile("assets/cinemas.txt", cinema.getId(), hall.getId(), 0);
				break;
			}
		}
	}
}

void Manager::editHall()
{
	std::cout << std::endl << "---EDIT HALL---" << std::endl;
	if (this->ownedCinemas.size() == 1)
	{
		Hall& hall = this->ownedCinemas[0].getHalls()[0];
		this->ownedCinemas[0].displayHalls();
		std::cout << "What do you want to edit?" << std::endl;
		std::cout << "1. Name" << std::endl;
		std::cout << "2. Location" << std::endl;
		std::cout << "3. Number of seats" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			std::cout << "Enter new name: ";
			std::cin.ignore();
			std::string newName = getUserInput();
			editFile("assets/halls.txt", hall.getName(), newName);
			hall.setName(newName);
			break;
		}
		case 2: {
			std::cout << "Enter new location: ";
			std::cin.ignore();
			std::string newLocation = getUserInput();
			editFile("assets/halls.txt", hall.getLocation(), newLocation);
			hall.setLocation(newLocation);
			break;
		}
		case 3: {
			std::cout << "Enter new number of seats: ";
			std::cin.ignore();
			int newSeats;
			std::cin >> newSeats;
			editFile("assets/halls.txt", std::to_string(hall.getNumberOfSeats()), std::to_string(newSeats));
			hall.setNumberOfSeats(newSeats);
			break;
		}
		default:
			std::cerr << "Invalid choice." << std::endl;
			return;
		}
	}
	else
	{
		displayCinemas();
		std::cout << "Select cinema by name to edit hall: ";
		std::string cinemaName = getUserInput();
		Cinema& cinema = findCinema(cinemaName);

		cinema.displayHalls();

		std::cout << "Select hall by name to edit: ";
		std::string hallId = getUserInput();
		Hall& hall = cinema.findHall(hallId);
		std::cout << "What do you want to edit?" << std::endl;
		std::cout << "1. Name" << std::endl;
		std::cout << "2. Location" << std::endl;
		std::cout << "3. Number of seats" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			std::cout << "Enter new name: ";
			std::cin.ignore();
			std::string newName = getUserInput();
			editFile("assets/halls.txt", hall.getName(), newName);
			hall.setName(newName);
			break;
		}
		case 2: {
			std::cout << "Enter new location: ";
			std::cin.ignore();
			std::string newLocation = getUserInput();
			editFile("assets/halls.txt", hall.getLocation(), newLocation);
			hall.setLocation(newLocation);
			break;
		}
		case 3: {
			std::cout << "Enter new number of seats: ";
			std::cin.ignore();
			int newSeats;
			std::cin >> newSeats;
			editFile("assets/halls.txt", std::to_string(hall.getNumberOfSeats()), std::to_string(newSeats));
			hall.setNumberOfSeats(newSeats);
			break;
		}
		default:
			std::cerr << "Invalid choice." << std::endl;
			return;
		}
	}
}

void Manager::addCinema()
{
	std::cout << std::endl << "---ADD CINEMA---" << std::endl;

	while (true)
	{
		std::cout << "Cinema id: ";
		std::cin.ignore();
		std::string cinemaId = getUserInput();
		cinema.setId(cinemaId);
		if (exists("assets/cinemas.txt", cinema.getId()))
		{
			std::cerr << "Cinema id already exists." << std::endl;
		}
		else
		{
			addFragmentToFile("assets/accounts.txt", manager.getEmail(), cinema.getId(), 0);
			addToFile("assets/cinemas.txt", std::ios::app, cinema.getId());
			addToFile("assets/cinemas.txt", std::ios::app, "");
			addToFile("assets/cinemas.txt", std::ios::app, "");
			break;
		}
	}

	while (true)
	{
		std::cout << "Cinema name: ";
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

	std::cout << "Cinema city: ";
	std::string cinemaCity = getUserInput();
	cinema.setCity(cinemaCity);
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getCity());
	if (!exists("assets/cities.txt", cinema.getCity()))
	{
		addToFile("assets/cities.txt", std::ios::app, cinema.getCity());
		City currentCity;
		currentCity.setName(cinemaCity);
		currentCity.addCinema(cinema);
		addFragmentToFile("assets/cities.txt", cinemaCity, cinema.getId(), 0);
		cities.push_back(currentCity);
	}
	else
	{
		City& currentCity = findCity(cinemaCity);
		currentCity.addCinema(cinema);
		addFragmentToFile("assets/cities.txt", cinemaCity, cinema.getId(), 0);
	}

	std::cout << "Cinema location: ";
	std::string cinemaLocation = getUserInput();
	cinema.setLocation(cinemaLocation);
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getLocation());

	cinema.setOwner(baseUser.getUsername());
	addToFile("assets/cinemas.txt", std::ios::app, cinema.getOwner());

	manager.ownedCinemas.push_back(cinema);
}

void Manager::editCinema()
{
	std::cout << std::endl << "---EDIT CINEMA---" << std::endl;
	std::cin.ignore();
	if (this->ownedCinemas.size() == 1)
	{
		this->ownedCinemas[0].displayCinemas(ownedCinemas);
		std::cout << "What do you want to edit?" << std::endl;
		std::cout << "1. Name" << std::endl;
		std::cout << "2. City" << std::endl;
		std::cout << "3. Location" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			std::cout << "Enter new name: ";
			std::cin.ignore();
			std::string newName = getUserInput();
			editFile("assets/cinemas.txt", this->ownedCinemas[0].getName(), newName);
			this->ownedCinemas[0].setName(newName);
			break;
		}
		case 2: {
			std::cout << "Enter new city: ";
			std::cin.ignore();
			std::string newCity = getUserInput();
			editFile("assets/cinemas.txt", this->ownedCinemas[0].getCity(), newCity);
			this->ownedCinemas[0].setCity(newCity);
			break;
		}
		case 3: {
			std::cout << "Enter new location: ";
			std::cin.ignore();
			std::string newLocation = getUserInput();
			editFile("assets/cinemas.txt", this->ownedCinemas[0].getLocation(), newLocation);
			this->ownedCinemas[0].setLocation(newLocation);
			break;
		}
		default:
			std::cerr << "Invalid choice." << std::endl;
			return;
		}
	}
	else
	{
		displayCinemas();
		std::cout << "Select cinema by name to edit: ";
		std::string cinemaName = getUserInput();
		Cinema& cinema = findCinema(cinemaName);
		std::cout << "What do you want to edit?" << std::endl;
		std::cout << "1. Name" << std::endl;
		std::cout << "2. City" << std::endl;
		std::cout << "3. Location" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			std::cout << "Enter new name: ";
			std::cin.ignore();
			std::string newName = getUserInput();
			editFile("assets/cinemas.txt", cinema.getName(), newName);
			cinema.setName(newName);
			break;
		}
		case 2: {
			std::cout << "Enter new city: ";
			std::cin.ignore();
			std::string newCity = getUserInput();
			editFile("assets/cinemas.txt", cinema.getCity(), newCity);
			cinema.setCity(newCity);
			break;
		}
		case 3: {
			std::cout << "Enter new location: ";
			std::cin.ignore();
			std::string newLocation = getUserInput();
			editFile("assets/cinemas.txt", cinema.getLocation(), newLocation);
			cinema.setLocation(newLocation);
			break;
		}
		default:
			std::cerr << "Invalid choice." << std::endl;
			return;
		}
	}
}

void Manager::displayCinemas()
{
	for (Cinema cinema : ownedCinemas)
	{
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Cinema ID: " << cinema.getId() << std::endl;
		std::cout << "Cinema Name: " << cinema.getName() << std::endl;
		std::cout << "City: " << cinema.getCity() << std::endl;
		std::cout << "Location: " << cinema.getLocation() << std::endl;
		std::cout << "------------------------" << std::endl;
	}
}

void Manager::addMovie()
{
	std::cout << std::endl << "---ADD MOVIE---" << std::endl;
	std::cin.ignore();

	std::cout << "Show ID: ";
	std::string showId = getUserInput();
	movie.setId(showId);
	addToFile("assets/movies.txt", std::ios::app, movie.getId());

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
	addToFile("assets/movies.txt", std::ios::app, movie.getDate());
	std::cout << "Ticket price: ";
	float moviePrice;
	std::cin >> moviePrice;
	movie.setPrice(moviePrice);
	std::cin.ignore();
	addToFile("assets/movies.txt", std::ios::app, std::to_string(movie.getPrice()));

	cinema.displayCinemas(manager.ownedCinemas);
	std::cout << "Select cinema by name: ";
	std::string cinemaName = getUserInput();
	Cinema& cinema = findCinema(cinemaName);

	cinema.displayHalls();
	std::cout << "Select hall by Id: ";
	std::string hallId = getUserInput();
	Hall& currentHall = cinema.findHall(hallId);
	if (currentHall.getName().empty())
	{
		std::cerr << "Hall not found in the selected cinema." << std::endl;
		return;
	}
	movie.setHall(currentHall);
	addToFile("assets/movies.txt", std::ios::app, movie.getHall().getId());

	cinema.addMovie(movie);
	addFragmentToFile("assets/cinemas.txt", cinema.getId(), movie.getId(), 1);
}

void Manager::editMovie()
{
	std::cout << std::endl << "---EDIT MOVIE---" << std::endl;
	if (this->ownedCinemas.size() == 1)
	{
		this->ownedCinemas[0].dispalyMovies();
		std::cout << "Select movie by name to edit: ";
		std::string movieName = getUserInput();
		Movie& movie = this->ownedCinemas[0].findMovie(movieName);

		std::cout << "What do you want to edit?" << std::endl;
		std::cout << "1. Title" << std::endl;
		std::cout << "2. Language" << std::endl;
		std::cout << "3. Genre" << std::endl;
		std::cout << "4. Length" << std::endl;
		std::cout << "5. Date" << std::endl;
		std::cout << "6. Price" << std::endl;
		int choice;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 1: {
			std::cout << "Enter new title: ";
			std::cin.ignore();
			std::string newTitle = getUserInput();
			editFile("assets/movies.txt", movie.getTitle(), newTitle);
			movie.setTitle(newTitle);
			break;
		}
		case 2: {
			std::cout << "Enter new language: ";
			std::cin.ignore();
			std::string newLanguage = getUserInput();
			editFile("assets/movies.txt", movie.getLanguage(), newLanguage);
			movie.setLanguage(newLanguage);
			break;
		}
		case 3: {
			std::cout << "Enter new genre: ";
			std::cin.ignore();
			std::string newGenre = getUserInput();
			editFile("assets/movies.txt", movie.getGenre(), newGenre);
			movie.setGenre(newGenre);
			break;
		}
		case 4: {
			std::cout << "Enter new length (in minutes): ";
			std::cin.ignore();
			int newLength;
			std::cin >> newLength;
			editFile("assets/movies.txt", std::to_string(movie.getLength()), std::to_string(newLength));
			movie.setLength(newLength);
			break;
		}
		case 5: {
			std::cout << "Enter new date (YYYY-MM-DD): ";
			std::cin.ignore();
			std::string newDate = getUserInput();
			editFile("assets/movies.txt", movie.getDate(), newDate);
			movie.setDate(newDate);
			break;
		}
		case 6: {
			std::cout << "Enter new price: ";
			std::cin.ignore();
			float newPrice;
			std::cin >> newPrice;
			editFile("assets/movies.txt", std::to_string(movie.getPrice()), std::to_string(newPrice));
			movie.setPrice(newPrice);
			break;
		}
		default:
			std::cerr << "Invalid choice." << std::endl;
			return;
		}
	}
	else
	{
		std::string chosenCinema;
		displayCinemas();
		std::cout << "Select cinema by name to edit movie: ";
		std::cin >> chosenCinema;
		Cinema& cinema = findCinema(chosenCinema);
		cinema.dispalyMovies();
		std::cout << "Select movie by name to edit: ";
		std::string movieName = getUserInput();
		Movie& movie = cinema.findMovie(movieName);

		std::cout << "What do you want to edit?" << std::endl;
		std::cout << "1. Title" << std::endl;
		std::cout << "2. Language" << std::endl;
		std::cout << "3. Genre" << std::endl;
		std::cout << "4. Length" << std::endl;
		std::cout << "5. Date" << std::endl;
		std::cout << "6. Price" << std::endl;
		int choice;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 1: {
			std::cout << "Enter new title: ";
			std::cin.ignore();
			std::string newTitle = getUserInput();
			editFile("assets/movies.txt", movie.getTitle(), newTitle);
			movie.setTitle(newTitle);
			break;
		}
		case 2: {
			std::cout << "Enter new language: ";
			std::cin.ignore();
			std::string newLanguage = getUserInput();
			editFile("assets/movies.txt", movie.getLanguage(), newLanguage);
			movie.setLanguage(newLanguage);
			break;
		}
		case 3: {
			std::cout << "Enter new genre: ";
			std::cin.ignore();
			std::string newGenre = getUserInput();
			editFile("assets/movies.txt", movie.getGenre(), newGenre);
			movie.setGenre(newGenre);
			break;
		}
		case 4: {
			std::cout << "Enter new length (in minutes): ";
			std::cin.ignore();
			int newLength;
			std::cin >> newLength;
			editFile("assets/movies.txt", std::to_string(movie.getLength()), std::to_string(newLength));
			movie.setLength(newLength);
			break;
		}
		case 5:
		{
			std::cout << "Enter new date (YYYY-MM-DD): ";
			std::cin.ignore();
			std::string newDate = getUserInput();
			editFile("assets/movies.txt", movie.getDate(), newDate);
			movie.setDate(newDate);
			break;
		}
		case 6: {
			std::cout << "Enter new price: ";
			std::cin.ignore();
			float newPrice;
			std::cin >> newPrice;
			editFile("assets/movies.txt", std::to_string(movie.getPrice()), std::to_string(newPrice));
			movie.setPrice(newPrice);
			break;
		}
		default:
			std::cerr << "Invalid choice." << std::endl;
			return;
		}
	}
}