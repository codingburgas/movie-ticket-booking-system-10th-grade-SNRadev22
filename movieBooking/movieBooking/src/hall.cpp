#include "../include/hall.h"
#include "../include/Utility.h"

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
void Hall::setSeatLayout(std::vector<std::string> newLayout)
{
	seatLayout = newLayout;
}

void Hall::setLayout()
{
	int numOfRows;
	std::cout << "Enter number of rows: ";
	std::cin >> numOfRows;
	rows = numOfRows;
	addToFile("assets/halls.txt", std::ios::app, std::to_string(rows));
	std::cin.ignore();

	for (int i = 0; i < rows; ++i)
	{
		std::string rowLayout;
		std::cout << "Enter layout for row " << i + 1 << ": ";
		std::getline(std::cin, rowLayout);

		seatLayout.push_back(rowLayout);
		addToFile("assets/halls.txt", std::ios::app, rowLayout);
	}
}

void Hall::displayLayout()
{
	std::cout << "Seat Layout: " << std::endl;
	for (std::string& row : seatLayout)
	{
		std::cout << row << std::endl;
	}
}