#include "../include/users.h"
#include <fstream>
#include<string>
#include <iostream>

void addToFile(std::fstream file, std::string fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
	std::cin.ignore();
	std::getline(file, user.email);
	file.close();
}