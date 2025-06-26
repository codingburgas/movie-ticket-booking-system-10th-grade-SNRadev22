#include "../include/cinema.h"

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