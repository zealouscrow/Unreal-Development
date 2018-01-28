/* 
Implements back-end game logic, making use of a class file and
various helper methods to run the game and handle/validate user input.
A simple word game based upon isograms.
For the main entry point, see main.cpp.

Author: https://github.com/zealouscrow

*/

#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;


// Default constructor
FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); } 

// Resets game to base state, generating a new word and bringing tries back down to one
void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = GenerateHiddenWord();
	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	
	return;
}

// Generates a randomised hidden word from premade sets established in member variables
FString FBullCowGame::GenerateHiddenWord() {
	// Generates a number between 1 and 4 that chooses which word length is used
	int32 ListChoice = (rand() % 4 + 1);
	// Generates a number between 0 and 7 to determine the index of the vector used
	int32 WordChoice = (rand() % 7);
	
	if (ListChoice == 1) { return ThreeLetter[WordChoice]; }
	else if (ListChoice == 2) { return FourLetter[WordChoice]; }
	else if (ListChoice == 3) { return FiveLetter[WordChoice]; }
	else if (ListChoice == 4) { return SixLetter[WordChoice]; }
}

// Checks each condition for a guess to be valid and returns the appropriate status
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
	
	// If the number of bulls matches the word length, player has won
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

// Checks that all characters in the guess are lowercase
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

// Maps number of tries to the length of the word in play
int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ { 3,5 },{ 4,7 },{ 5,10 },{ 6,15 } };
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

// Other getter methods
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return GetHiddenWord().length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

