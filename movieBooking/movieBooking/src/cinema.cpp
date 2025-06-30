#include "../include/cinema.h"
#include<sstream>

Cinema cinema;

std::string Cinema::getName()
{
	return name;
}

std::string Cinema::getCity()
{
	return city;
}
std::string Cinema::getLocation()
{
	return location;
}
std::string Cinema::getId()
{
	return id;
}
std::string Cinema::getOwner()
{
	return owner;
}
std::vector <Hall>& Cinema::getHalls()
{
	return halls;
}
std::vector <Movie> Cinema::getMovies()
{
	return movies;
}

void Cinema::setName(std::string newName)
{
	name = newName;
}
void Cinema::setCity(std::string newCity)
{
	city = newCity;
}
void Cinema::setLocation(std::string newLocation)
{
	location = newLocation;
}
void Cinema::setId(std::string newID)
{
	id = newID;
}
void Cinema::setOwner(std::string newOwner)
{
	owner = newOwner;
}

bool Cinema::validCinema(const std::string& fileName, std::string idToFind, std::string nameToFind)
{
	std::ifstream file;
	file.open(fileName);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return false;
	}
	else
	{
		std::string id, name;
		while (std::getline(file, id))
		{
			if (id == idToFind)
			{
				std::getline(file, name);
				if (name == nameToFind)
				{
					file.close();
					return true;
				}
			}
		}
		file.close();
		return false;
	}
}

void Cinema::displayCinemas(std::vector<Cinema> cinemas)
{
	for (size_t i = 0; i < cinemas.size(); i++)
	{
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Cinema Name: " << cinemas[i].getName() << std::endl;
		std::cout << "City: " << cinemas[i].getCity() << std::endl;
		std::cout << "Location: " << cinemas[i].getLocation() << std::endl;
		std::cout << "Owner: " << cinemas[i].getOwner() << std::endl;
		std::cout << "------------------------" << std::endl;
	}
}

void Cinema::addHall(Hall hall)
{
	halls.push_back(hall);
}

void Cinema::addMovie(Movie movie)
{
	movies.push_back(movie);
}

Hall& Cinema::findHall(std::string idToFind)
{
	for (size_t i = 0; i < halls.size(); i++)
	{
		if (halls[i].getId() == idToFind)
		{
			return halls[i];
		}
	}
	Hall emptyHall;
	return emptyHall;
}

void Cinema::loadHalls(const std::string& cinemaFileName, const std::string& hallFileName)
{
	std::ifstream cinemaFile(cinemaFileName);
	if (!cinemaFile.is_open()) {
		std::cerr << "Error opening cinema file: " << cinemaFileName << std::endl;
		return;
	}

	std::ifstream hallFile(hallFileName);
	if (!hallFile.is_open()) {
		std::cerr << "Error opening hall file: " << hallFileName << std::endl;
		return;
	}

	std::string line;
	while (std::getline(cinemaFile, line)) {
		if (line == this->id) {
			std::string hallsLine;
			if (!std::getline(cinemaFile, hallsLine)) {
			
				break;
			}

			std::istringstream iss(hallsLine);
			std::string hallId;

			while (iss >> hallId) {
				hallFile.clear();
				hallFile.seekg(0);

				std::string id, name, location, sizeStr, rowsStr;

				while (std::getline(hallFile, id)) {
					if (!std::getline(hallFile, name) ||
						!std::getline(hallFile, location) ||
						!std::getline(hallFile, sizeStr) ||
						!std::getline(hallFile, rowsStr)) {
						
						break;
					}

					if (id == hallId) {
						Hall hall;
						hall.setId(id);
						hall.setName(name);
						hall.setLocation(location);
						hall.setNumberOfSeats(std::stoi(sizeStr));
						int numRows = std::stoi(rowsStr);
						hall.setRows(numRows);

						std::vector<std::string> layout;
						for (int i = 0; i < numRows; ++i)
						{
							std::string layoutLine;
							if (!std::getline(hallFile, layoutLine)) {
								
								break;
							}
							layout.push_back(layoutLine);
						}
						hall.setSeatLayout(layout);
						this->addHall(hall);
						break;
					}
				}
			}
			break;
		}
	}
	cinemaFile.close();
	hallFile.close();
}



void Cinema::loadMovies(const std::string& cinemaFileName, const std::string& movieFileName)
{
	std::ifstream cinemaFile(cinemaFileName);
	if (!cinemaFile.is_open())
	{
		std::cerr << "Error opening cinema file: " << cinemaFileName << std::endl;
		return;
	}

	std::ifstream movieFile(movieFileName);
	if (!movieFile.is_open())
	{
		std::cerr << "Error opening movie file: " << movieFileName << std::endl;
		return;
	}

	std::string line;
	while (std::getline(cinemaFile, line))
	{
		if (line == this->id)
		{

			std::getline(cinemaFile, line);
			std::string moviesLine;
			if (std::getline(cinemaFile, moviesLine))
			{

				std::istringstream iss(moviesLine);
				std::string movieId;
				while (iss >> movieId)
				{

					movieFile.clear();
					movieFile.seekg(0);

					std::string id, title, language, genre, date, hallId;
					int length;
					float price;

					while (std::getline(movieFile, id))
					{
						if (!std::getline(movieFile, title) ||
							!std::getline(movieFile, language) ||
							!std::getline(movieFile, genre) ||
							!(movieFile >> length) ||
							!movieFile.ignore() ||
							!std::getline(movieFile, date) ||
							!(movieFile >> price) ||
							!movieFile.ignore() ||
							!std::getline(movieFile, hallId))
						{
							break;
						}

						if (id == movieId)
						{

							Movie movie;
							movie.setId(id);
							movie.setTitle(title);
							movie.setLanguage(language);
							movie.setGenre(genre);
							movie.setLength(length);
							movie.setDate(date);
							movie.setPrice(price);

							Hall& hall = findHall(hallId);
							if (!hall.getName().empty())
							{
								movie.setHall(hall);
							}
							else
							{

							}

							this->addMovie(movie);
							break;
						}
					}
				}
			}
			else
			{

			}
			break;
		}
	}

	cinemaFile.close();
	movieFile.close();
}



void Cinema::dispalyMovies()
{
	if (movies.empty())
	{
		std::cout << "No movies available." << std::endl;
		return;
	}
	std::cout << "Movies in " << name << " cinema:" << std::endl;
	for (Movie& movie : movies)
	{
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Movie Title: " << movie.getTitle() << std::endl;
		std::cout << "Language: " << movie.getLanguage() << std::endl;
		std::cout << "Genre: " << movie.getGenre() << std::endl;
		std::cout << "Length: " << movie.getLength() << " minutes" << std::endl;
		std::cout << "Date: " << movie.getDate() << std::endl;
		std::cout << "Price: $" << movie.getPrice() << std::endl;
		std::cout << "Hall: " << movie.getHall().getName() << std::endl;
		std::cout << "------------------------" << std::endl;
	}
}

void Cinema::displayHalls()
{
	if (halls.empty())
	{
		std::cout << "No halls available." << std::endl;
		return;
	}
	for (Hall& hall : halls)
	{
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Hall Name: " << hall.getName() << std::endl;
		std::cout << "Location: " << hall.getLocation() << std::endl;
		std::cout << "Number of Seats: " << hall.getNumberOfSeats() << std::endl;
		hall.displayLayout();
		std::cout << "------------------------" << std::endl;
	}
}

Movie& Cinema::findMovie(std::string nameToFind)
{
	for (size_t i = 0; i < movies.size(); i++)
	{
		if (movies[i].getTitle() == nameToFind)
		{
			return movies[i];
		}
	}
	std::cerr << "Movie not found: " << nameToFind << std::endl;
	static Movie emptyMovie; // Return a static empty movie if not found
	return emptyMovie;
}