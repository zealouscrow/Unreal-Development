// Main

#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// Entry point for the application
int main() {
	
	PrintIntro();

	do {
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

// Introduce the game
void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a simple and fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n" << std::endl;
	return;
}

// Set game to run for a given number of allowed guesses
void PlayGame() {
	
	int MaxTries = BCGame.GetMaxTries();

	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess is: " << Guess << std::endl;

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

// Retrieve guess as a std::string from user input
std::string GetGuess() {
	std::string Guess = "";
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);
	
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (Y/N): ";

	while (true) {
		std::string Response = "";
		getline(std::cin, Response);
		if (Response[0] == 'y' || Response[0] == 'Y'){
			return true;
		}
		else if (Response[0] == 'n' || Response[0] == 'N') {
			return false;
		}

		std::cout << "Please enter either Y or N: ";
	}
}
