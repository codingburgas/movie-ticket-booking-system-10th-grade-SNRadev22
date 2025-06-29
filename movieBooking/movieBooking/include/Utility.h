#pragma once
#include "baseUser.h"
#include<iostream>
#include<fstream>
#include "city.h"

void drawHomePage();
std::string getUserInput();
bool exists(const std::string fileName, std::string input);
void addToFile(const std::string& fileName, std::ios_base::openmode mode, const std::string& input);
void editFile(const std::string& fileName, const std::string& toFind, const std::string& toAdd);
void addFragmentToFile(const std::string fileName, std::string toFind, std::string toAdd, int skips);

City& findCity(std::string nameToFind);