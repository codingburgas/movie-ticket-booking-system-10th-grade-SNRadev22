#include "../include/hall.h"

Hall hall;

std::string Hall::getId()
{
	return id;
}
std::string Hall::getName()
{
	return name;
}
std::string Hall::getLocation()
{
	return location;
}

void Hall::setId(std::string newId)
{
	id = newId;
}
void Hall::setName(std::string newName)
{
	name = newName;
}
void Hall::setLocation(std::string newLocation)
{
	location = newLocation;
}

int Hall::getNumberOfSeats()
{
	return numberOfSeats;
}

void Hall::setNumberOfSeats(int seats)
{
	numberOfSeats = seats;
}