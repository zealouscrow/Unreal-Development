/* Console executable, making use of the BullCow class.
This acts as the view in an MVC pattern and is responsible for all
user interaction.
For game logic, see FBullCowGame.cpp.

Author: https://github.com/zealouscrow

*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FString GetGuess();
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
	int32 WordLength = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows, a simple and fun word game.\n";
	std::cout << "Can you guess the " << WordLength;
	std::cout << " letter isogram I'm thinking of?\n" << std::endl;
	return;
}

// Set game to run for a given number of allowed guesses
void PlayGame() {
	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//TODO: change from for to while loop
	for (int32 count = 1; count <= MaxTries; count++) {
		FString Guess = GetGuess(); //TODO: guess validation

		//Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}

	//TODO: add a summary of the game

	std::cout << std::endl;
}

// Retrieve guess as a string from user input
FString GetGuess() {
	FString Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);
	
	return Guess;
}

// Ask for user input (Y/N) to determine whether to restart game or exit
bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (Y/N): ";

	while (true) {
		FString Response = "";

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
