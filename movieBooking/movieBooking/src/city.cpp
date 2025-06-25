#include "../include/city.h"
#include <sstream>

std::vector<City> cities;

City City::findCity(std::string nameToFind)
{
	for (size_t i = 0; i < cities.size(); ++i)
	{
		if (cities[i].name == nameToFind)
		{
			return cities[i];
		}
	}
}

void City::addCinemaToFile(const std::string fileName, std::string nameToFind, std::string cinemaId)
{
	std::fstream file;
	std::vector<std::string> lines;
	std::string line;
	file.open(fileName, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Error while opening file!" << std::endl;
	}
	else
	{
		while (getline(file, line))
		{
			lines.push_back(line);
			if (line == nameToFind)
			{
				getline(file, line);
				line += " " + cinemaId;
				lines.push_back(line);
				break;
			}
		}

		while (getline(file, line))
		{
			lines.push_back(line);
		}

		file.close();
		file.open(fileName, std::ios::out | std::ios::trunc);

		for (size_t i = 0; i < lines.size(); i++)
		{
			file << lines[i] << std::endl;
		}

		file.close();
	}
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
		if (getline(cityFile, line))  // The line of cinema IDs
		{
			std::istringstream iss(line);
			std::string idToFind;

			while (iss >> idToFind)
			{
				// Reset cinema file to the beginning
				cinemaFile.clear();
				cinemaFile.seekg(0);

				std::string id, name, city, location, owner;
				while (getline(cinemaFile, id))
				{
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