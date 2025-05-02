#include "../include/users.h"
#include <fstream>
#include<string>
#include <iostream>

User user;

void addToFile(std::fstream& file, const std::string& fileName, std::ios_base::openmode mode, std::string& input)
{
	file.open(fileName, mode);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}
	else
	{
		std::getline(std::cin, input);
		file << input << std::endl;
		file.close();
	}
}