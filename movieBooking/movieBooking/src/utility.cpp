#include "../include/Utility.h"

std::string getUserInput()
{
	std::string userInput;
	while (true)
	{
		std::getline(std::cin, userInput);
		if (userInput.empty())
		{
			std::cerr << "Input cannot be empty." << std::endl;
		}
		else
		{
			return userInput;
		}
	}
}

bool exists(const std::string fileName, std::string input)
{
	std::ifstream file;
	std::string toCheck;
	file.open(fileName);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		file.close();
		return false;
	}
	else
	{
		while (std::getline(file, toCheck))
		{
			if (toCheck == input)
			{
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
}

void addToFile(const std::string& fileName, std::ios_base::openmode mode, const std::string& input)
{
	std::ofstream file;
	file.open(fileName, mode);
	if (!file)
	{
		std::cerr << "Error opening file: " << fileName << std::endl;
		return;
	}
	else
	{
		file << input << std::endl;
		file.close();
	}

}

void addFragmentToFile(const std::string fileName, std::string toFind, std::string toAdd, int skips)
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
			if (line == toFind)
			{
				lines.push_back(line);
				for (int i = 0; i < skips; i++)
				{
					getline(file, line);
					lines.push_back(line);
				}

				std::cout << "line found" << std::endl;
				getline(file, line);
				line += " " + toAdd;
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

City& findCity(std::string nameToFind)
{
	for (size_t i = 0; i < cities.size(); i++)
	{
		if (cities[i].getName() == nameToFind)
		{
			return cities[i];
		}
	}
}

void editFile(const std::string& fileName, const std::string& toFind, const std::string& toAdd)
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
			if (line == toFind)
			{
				line = toAdd;
			}
			lines.push_back(line);
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