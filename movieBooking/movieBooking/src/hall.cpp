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

void Hall::editSeatLayout(int row, int seat)
{
	if (row < 0 || row >= rows)
	{
		std::cerr << "Invalid row number." << std::endl;
		return;
	}
	else
	{
		if (seat < 0 || seat >= seatLayout[row].size())
		{
			std::cerr << "Invalid seat number." << std::endl;
			return;
		}
		else
		{
			if (seatLayout[row][seat] == 'X')
			{
				std::cerr << "Seat already booked." << std::endl;
				return;
			}
			{
				seatLayout[row][seat] = 'X';
				std::cout << "Seat booked successfully." << std::endl;
			}
		}
	}
}

void Hall::saveToFile(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cerr << "Could not open file for reading: " << filename << std::endl;
		return;
	}

	std::ostringstream newFileContent;
	std::string line;

	while (std::getline(inFile, line)) {
		if (line == id) {
			// Found this hall's block — overwrite with updated data
			newFileContent << id << "\n";
			newFileContent << name << "\n";
			newFileContent << location << "\n";
			newFileContent << std::to_string(numberOfSeats) << "\n";
			newFileContent << std::to_string(rows) << "\n";
			for (const std::string& row : seatLayout) {
				newFileContent << row << "\n";
			}

			// Skip over old block lines
			for (int i = 0; i < 4 + rows; ++i) {
				std::getline(inFile, line); // discard old lines
			}
		}
		else {
			newFileContent << line << "\n";
		}
	}

	inFile.close();

	// Now write everything back
	std::ofstream outFile(filename, std::ios::trunc);
	if (!outFile.is_open()) {
		std::cerr << "Could not open file for writing: " << filename << std::endl;
		return;
	}
	outFile << newFileContent.str();
	outFile.close();

	std::cout << "Hall layout saved successfully.\n";
}