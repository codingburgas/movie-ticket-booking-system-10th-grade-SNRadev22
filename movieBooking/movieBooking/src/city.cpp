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
	std::fstream file(fileName, std::ios::in);
	std::string line;
	std::string id;

	if (!file.is_open())
	{
		std::cerr << "Error while opening file!" << std::endl;
		return;
	}

	while (getline(file, line))
	{
		City city;
		city.setName(line);

		if (getline(file, line))
		{
			std::istringstream iss(line);
			while (iss >> id) 
			{
				city.addCinema(id);
			}
		}

		cities.push_back(city);
	}

	file.close();
}

void City::addCinema(std::string cinemaId)
{
	cinemas.push_back(cinemaId);
}

std::string City::getName()
{
	return name;
}

std::vector<std::string> City::getCinemas()
{
	return cinemas;
}

void City::setName(std::string newName)
{
	name = newName;
}

void City::setCinemas(std::vector<std::string> cinemasList)
{
	cinemas = cinemasList;
}