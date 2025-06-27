#include "../include/city.h"
#include <sstream>

std::vector<City> cities;

City City::findCity(std::string nameToFind)
{
	for (size_t i = 0; i < cities.size(); i++)
	{
		if (cities[i].name == nameToFind)
		{
			return cities[i];
		}
	}
}

Cinema City::findCinema(std::string nameToFind)
{
	for (size_t i = 0; i < cinemas.size(); i++)
	{
		if (cinemas[i].getName() == nameToFind)
		{
			return cinemas[i];
		}
	}
	std::cerr << "Cinema not found!" << std::endl;
	return Cinema();
}

void City::loadCities(const std::string fileName)
{
	std::ifstream cityFile(fileName);
	if (!cityFile.is_open())
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

	City currentCity;
	std::string cityName;
	while (getline(cityFile, cityName))
	{
		currentCity.setName(cityName);

		std::string line;
		if (getline(cityFile, line))
		{
			std::istringstream iss(line);
			std::string idToFind;

			while (iss >> idToFind)
			{
				cinemaFile.clear();
				cinemaFile.seekg(0);

				std::string id, name, city, location, owner, skipHalls;
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

						currentCity.addCinema(cinema);
						break;
					}
				}
			}
		}

		cities.push_back(currentCity);
	}

	cityFile.close();
	cinemaFile.close();
}

void City::addCinema(Cinema cinema)
{
	cinemas.push_back(cinema);
}

std::string City::getName()
{
	return name;
}

std::vector<Cinema> City::getCinemas()
{
	return cinemas;
}

void City::setName(std::string newName)
{
	name = newName;
}

void City::setCinemas(std::vector<Cinema> cinemasList)
{
	cinemas = cinemasList;
}