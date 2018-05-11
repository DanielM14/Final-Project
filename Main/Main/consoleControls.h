#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <time.h>

#include "shopControl.h"

// Declaring functions before hand
std::string TransformTextCasing(std::string type, std::string text);
void TransformTextColor();
void WelcomeMessage();
int RandomNumberGenerator(int maxNumber);

// Setting random number for the user cash
double userCurrencyAmount = RandomNumberGenerator(500);


std::string TransformTextCasing(std::string type, std::string text)
{
	std::transform(type.begin(), type.end(), type.begin(), ::tolower); // lowers the type so if they do "loWeR" it will become "lower"
	if (type == "lower")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::tolower); // transforms the string text to lower "aBCdEfgHijKlmnOP" to "abcdefghijlmnop"
	}
	else if (type == "upper")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	}
	return text;
}

void TransformTextColor()
{
	SetConsoleTitle(TEXT("Text Color Changer"));
	system("cls");
	int userNumberChoice;
	std::cout << "Avaliable colors below:\n\n";
	
	if (MoreTextColors == true)
	{
		// Outputing every possible combination if the user HAS MoreTextColors
		for (int x = 1; x < 255; x++)
		{
			// Changes text color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			std::cout << x << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\n\nWhat number would you like: ";
		std::cin >> userNumberChoice;

		if (userNumberChoice <= 255 && userNumberChoice >= 1)
		{
			// Changes text color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), userNumberChoice);
			std::cout << "Successfully changed text color!" << std::endl;
		}
	}
	else if (MoreTextColors == false)
	{
		// Outputing every possible combination if the user DOESNT have MoreTextColor
		for (int x = 1; x < 16; x++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			std::cout << x << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\n\nWhat number would you like: ";
		std::cin >> userNumberChoice;

		if (userNumberChoice <= 16 && userNumberChoice >= 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), userNumberChoice);
			std::cout << "Successfully changed text color!" << std::endl;
		}
	}
}

void WelcomeMessage() // Displays welcome message 
{
	std::cout << "|************************************|" << std::endl;
	std::cout << "||||||Welcome to That one Casino||||||" << std::endl;
	std::cout << "|************************************|" << std::endl;
}

// Little RNG
int RandomNumberGenerator(int maxNumber)
{
	srand(time(NULL));
	return rand() % maxNumber + 1;
}