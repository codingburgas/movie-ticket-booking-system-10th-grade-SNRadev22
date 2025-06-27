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
std::vector <Hall> Cinema::getHalls()
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

Hall Cinema::findHall(std::string nameToFind)
{
	for (size_t i = 0; i < halls.size(); i++)
	{
		if (halls[i].getName() == nameToFind)
		{
			std::cout << halls[i].getName() << std::endl;
			return halls[i];
		}
	}
	return Hall(); // Return an empty Hall if not found
}

void Cinema::displayMovies(std::vector<Movie> movies)
{
	for (size_t i = 0; i < movies.size(); i++)
	{
		std::cout << std::endl << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Movie Title: " << movies[i].getTitle() << std::endl;
		std::cout << "Language: " << movies[i].getLanguage() << std::endl;
		std::cout << "Genre: " << movies[i].getGenre() << std::endl;
		std::cout << "Length: " << movies[i].getLength() << " minutes" << std::endl;
		std::cout << "Date: " << movies[i].getDate() << std::endl;
		std::cout << "Price: $" << movies[i].getPrice() << std::endl;
		//std::cout << "Hall: " << movies[i].getHall().getName() << std::endl;
		std::cout << "------------------------" << std::endl;
	}
}

void Cinema::loadHalls(const std::string& cinemaFileName, const std::string& hallFileName)
{
	std::ifstream cinemaFile(cinemaFileName);
	if (!cinemaFile.is_open())
	{
		std::cerr << "Error opening cinema file: " << cinemaFileName << std::endl;
		return;
	}

	std::ifstream hallFile(hallFileName);
	if (!hallFile.is_open())
	{
		std::cerr << "Error opening hall file: " << hallFileName << std::endl;
		return;
	}

	std::string line;
	while (std::getline(cinemaFile, line))
	{
		if (line == this->id)
		{
			std::string hallsLine;
			if (std::getline(cinemaFile, hallsLine))
			{
				std::istringstream iss(hallsLine);
				std::string hallName;

				while (iss >> hallName)
				{
					hallFile.clear();
					hallFile.seekg(0);

					std::string name, location, sizeStr;
					while (std::getline(hallFile, name))
					{
						std::getline(hallFile, location);
						std::getline(hallFile, sizeStr);

						if (name == hallName)
						{
							Hall hall;
							hall.setName(name);
							hall.setLocation(location);
							hall.setNumberOfSeats(std::stoi(sizeStr));
							this->addHall(hall);
							break;
						}
					}
				}
			}
			break;
		}
	}

	cinemaFile.close();
	hallFile.close();
}