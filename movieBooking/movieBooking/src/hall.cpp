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
int Hall::getRows()
{
	return rows;
}
int Hall::getNumberOfSeats()
{
	return numberOfSeats;
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
void Hall::setNumberOfSeats(int seats)
{
	numberOfSeats = seats;
}
void Hall::setRows(int newRows)
{
	rows = newRows;
}

void Hall::setLayout()
{
	int numOfRows;
	std::cout << "Enter number of rows: ";
	std::cin >> numOfRows;
	rows = numOfRows;
	std::cin.ignore();

	for (size_t i = 0; i < rows; i++)
	{
		std::cout << "Enter layout for row " << i + 1 << ": ";
		std::cin.getline(seatLayout[i], 100);
	}
}

void Hall::displayLayout()
{
	std::cout << "Seat Layout: " << std::endl;
	for (size_t i = 0; i < rows; i++)
	{
		std::cout << seatLayout[i] << std::endl;
	}
}