#include "../include/hall.h"

std::string Hall::getName()
{
	return name;
}
std::string Hall::getLocation()
{
	return location;
}

void Hall::setName(std::string newName)
{
	name = newName;
}
void Hall::setLocation(std::string newLocation)
{
	location = newLocation;
}