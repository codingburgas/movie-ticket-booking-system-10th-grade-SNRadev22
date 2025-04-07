#include "../include/loginRgister.h"

void drawHomePage()
{
	std::cout << "---CINEMABOOKING---" << std::endl;
	std::cout << "1.Login" << std::endl;
	std::cout << "2.Register" << std::endl;
	std::cout << "3.Exit" << std::endl;
}

void drawLoginPage()
{
	std::cout << "---LOGIN---" << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
}

void drawRegisterPage()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "1.As user" << std::endl;
	std::cout << "2.As admin " << std::endl;
	std::cout << "3.As manager " << std::endl;
}

void drawRegisterUser()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "Email: ";
	std::cout << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
}

void drawRegisterAdmin()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "Email: ";
	std::cout << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
	std::cout << std::endl;
	std::cout << "Cinema id: ";
}

void drawRegisterManager()
{
	std::cout << "---REGISTER---" << std::endl;
	std::cout << "Email: ";
	std::cout << std::endl;
	std::cout << "Username: ";
	std::cout << std::endl;
	std::cout << "Password: ";
	std::cout << std::endl;
	std::cout << "Cinema id: ";
	std::cout << std::endl;
	std::cout << "Cinema name: ";
	std::cout << std::endl;
	std::cout << "Cinema city: ";
	std::cout << std::endl;
	std::cout << "Cinema location: ";
}