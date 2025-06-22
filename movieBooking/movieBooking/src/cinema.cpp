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