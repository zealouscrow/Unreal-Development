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
FString GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	
	std::cout << "  ___      _ _                   _    ___               " << std::endl;
	std::cout << " | _ )_  _| | |___  __ _ _ _  __| |  / __|_____ __ _____" << std::endl;
	std::cout << " | _ \\ || | | (_-< / _` | ' \\/ _` | | (__/ _ \\ V  V (_-<" << std::endl;
	std::cout << " |___/\\_,_|_|_/__/ \\__,_|_||_\\__,_|  \\___\\___/\\_/\\_//__/\n" << std::endl;
	
	std::cout << " Welcome to Bulls and Cows, a simple and fun word game.\n";
	std::cout << " Can you guess the " << WordLength;
	std::cout << " letter isogram I'm thinking of?\n" << std::endl;
	return;
}


// Set game to run for a given number of allowed guesses
void PlayGame() {
	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// While game is NOT won and there are tries remaining, loop asking for guesses
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
		
		FString Guess = GetValidGuess();
		
		//Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	std::cout << std::endl;

	PrintGameSummary();
	
}

// Loops continually until the user gives a valid guess
FString GetValidGuess() {
	FString Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	while (true) {
	std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
	
	getline(std::cin, Guess); // Receive guess string
	Status = BCGame.CheckGuessValidity(Guess);
	
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters.\n";
			break;
		
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a fully lowercase word.\n";
			break;

		default:
			return Guess; // When status is OK we proceed

		}

		std::cout << std::endl;
	}
	
}

// Ask for user input (Y/N) to determine whether to restart game or exit
bool AskToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word? (Y/N): ";

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


void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations! You won!\n";
	}
	else {
		std::cout << "Sorry, you didn't guess the correct word. Better luck next time.\n";
	}
}