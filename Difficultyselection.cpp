#include "Difficultyselection.h"
#include <iostream>
#include <string>
#include <conio.h> 

DifficultySelection::DifficultySelection() 
{

}

DifficultySelection::~DifficultySelection() 
{

}

void DifficultySelection::selectDifficulty()
{
	difficulty = 1;
	selected = false;

	const int W_KEY = 'w';
	const int S_KEY = 's';
	const int Z_KEY = 'z';

	while (!selected) // Display UI until a choice is made
	{
		system("cls"); // Clear screen (Windows)

		std::cout << "This is the difficulty selection menu" << std::endl;
		std::cout << "Select your game difficulty: " << std::endl;
		std::cout << (difficulty == 1 ? "-> Easy " : "   Easy") << std::endl;
		std::cout << (difficulty == 2 ? "-> Normal " : "   Normal") << std::endl;
		std::cout << (difficulty == 3 ? "-> Hard " : "   Hard") << std::endl;
		std::cout << (difficulty == 4 ? "-> Oblivion " : "   Oblivion") << std::endl;
		std::cout << "\nUse 'W' and 'S' to navigate, 'Z' to select." << std::endl;


		key = _getch(); // Read a single character

		// Use a switch statement to handle key presses
		switch (key)
		{
		case W_KEY:
			difficulty = (difficulty > 1) ? difficulty - 1 : 4;
			break;

		case S_KEY:
			difficulty = (difficulty < 4) ? difficulty + 1 : 1;
			break;

		case Z_KEY:
			selected = true; // Set flag to exit the loop
			break;
		}
	}

	system("cls");
	std::cout << "The Difficulty you have selected: ";
	switch (difficulty)
	{
	case 1:
		std::cout << "Easy" << std::endl;
		break;
	case 2:
		std::cout << "Normal" << std::endl;
		break;
	case 3:
		std::cout << "Hard" << std::endl;
		break;
	case 4:
		std::cout << "Oblivion" << std::endl;
		break;
	}
}

void DifficultySelection::setDifficulty()
{
	if (difficulty == 1) // Easy difficulty
	{
		difficultyGrade = 'E';
	}
	if (difficulty == 2) // Normal difficulty
	{
		difficultyGrade = 'N';
	}
	if (difficulty == 3) // Hard difficulty
	{
		difficultyGrade = 'H';
	}
	if (difficulty == 4) // Oblivion difficulty
	{
		difficultyGrade = 'O';
	}
}

char DifficultySelection::getDifficultyGrade()
{
	return difficultyGrade;
}