#include "../include/admin.h"

Admin admin;

Cinema& Admin::getCinema()
{
	return workingCinema;
}

void Admin::setCinema(Cinema cinema)
{
	workingCinema = cinema;
}

Cinema& Admin::findWorkingCinema(std::string idToFind)
{
    for (City& city : cities) {
        for (Cinema& cinema : city.getCinemas()) {
            if (cinema.getId() == idToFind) {
				return cinema;
            }
        }
    }
}

void Admin::loadWorkingCinema(const std::string& accountFile, const std::string& adminEmail) {
	std::ifstream accounts(accountFile);
	if (!accounts.is_open()) {
		std::cerr << "Error opening file: " << accountFile << std::endl;
		return;
	}

	std::string line;
	bool found = false;

	while (std::getline(accounts, line)) {
		if (line == adminEmail) {
			found = true;
			break;
		}
	}

	if (!found) {
		std::cerr << "Admin with email " << adminEmail << " not found." << std::endl;
		accounts.close();
		return;
	}

	// Skip next 2 lines (empty fields)
	std::getline(accounts, line);
	std::getline(accounts, line);

	// 4th line is cinema ID
	std::string cinemaId;
	if (!std::getline(accounts, cinemaId)) {
		std::cerr << "Failed to read cinema ID for admin." << std::endl;
		accounts.close();
		return;
	}

	accounts.close();

	// Now search for that cinema in the cinema file
	std::ifstream cinemaFile("assets/cinemas.txt");
	if (!cinemaFile.is_open()) {
		std::cerr << "Error opening file: assets/cinemas.txt" << std::endl;
		return;
	}

	while (std::getline(cinemaFile, line)) {
		std::string id = line;
		std::string skipHalls, name, city, location, owner;

		if (!std::getline(cinemaFile, skipHalls) ||
			!std::getline(cinemaFile, name) ||
			!std::getline(cinemaFile, city) ||
			!std::getline(cinemaFile, location) ||
			!std::getline(cinemaFile, owner)) {
			break; // Bad format
		}

		if (id == cinemaId) {
			Cinema c;
			c.setId(id);
			c.setName(name);
			c.setCity(city);
			c.setLocation(location);
			c.setOwner(owner);
			c.loadHalls("assets/cinemas.txt", "assets/halls.txt");
			workingCinema = c;
			break;
		}
	}

	cinemaFile.close();
}