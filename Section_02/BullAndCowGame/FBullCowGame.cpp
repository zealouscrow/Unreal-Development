/* 
Implements back-end game logic, making use of a class file and
various helper methods to run the game and handle/validate user input.
For the main entry point, see main.cpp.

Author: https://github.com/zealouscrow

*/


#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); } // default constructor


void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = GenerateHiddenWord();
	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	
	return;
}

// Generates a randomised hidden word from premade sets established in member variables
FString FBullCowGame::GenerateHiddenWord() {
	int32 ListChoice = (rand() % 4 + 1);
	int32 WordChoice = (rand() % 7);
	
	if (ListChoice == 1) { return ThreeLetter[WordChoice]; }
	else if (ListChoice == 2) { return FourLetter[WordChoice]; }
	else if (ListChoice == 3) { return FiveLetter[WordChoice]; }
	else if (ListChoice == 4) { return SixLetter[WordChoice]; }
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	//If guess isn't an isogram
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}

	//If guess isn't all lowercase
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}

	//If guess length is wrong
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}

	//otherwise
	else return EGuessStatus::OK;

}


// Receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

	MyCurrentTry++;
	FBullCowCount Count;
	int32 WordLength = GetHiddenWordLength(); // Assuming same length as guess

	//Loop through all letters in hidden word
	for (int32 i = 0; i < WordLength; i++) {
		
		//Compare letters against guess
		for(int32 j = 0; j < WordLength; j++) { 
			// If they match then
			if (GetHiddenWord()[j] == Guess[i]) {
					//If they're in the same place, increment bulls
					if (i == j) { Count.Bulls++; }
					//Else increment cows
					else { Count.Cows++; }

			}
		}
	}
	
	if (Count.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return Count;
}


// Checks guess string is a valid isogram
bool FBullCowGame::IsIsogram(FString Word) const {
	// Treat 0 and 1 letter words as isograms.
	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen;

	// Loop through the guess character by character
	for (auto Letter : Word) {
		// Force letter to be lowercase
		Letter = tolower(Letter);

		// If letter exists in map we do not have an isogream
		if (LetterSeen[Letter]) { return false; }
		else {
			LetterSeen[Letter] = true;
		}
	}

	// If all characters are cycled through without returning false, return true
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	//Strings of 0 length are lowercase
	if (Word.length() == 0) { return true; }

	// If at any point a character is uppercase, break the loop and return
	for (auto Letter : Word) {
		if (!islower(Letter)) { return false; }
	}

	// If all characters are lowercase proceed
	return true;
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,6}, {5,8}, {6,10} };
	return WordLengthToMaxTries[GetHiddenWordLength()];
}
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return GetHiddenWord().length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

