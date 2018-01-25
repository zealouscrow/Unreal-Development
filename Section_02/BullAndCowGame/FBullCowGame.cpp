#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}


bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}


// Receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {

	MyCurrentTry++;
	FBullCowCount Count;

	//Loop through all letters in guess
	int32 HiddenWordLength = GetHiddenWordLength();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		
		//Compare letters against hidden word
		for(int32 j = 0; j < HiddenWordLength; j++) { 
			// If they match then
			if (GetHiddenWord()[j] == Guess[i]) {
					//If they're in the same place, increment bulls
					if (i == j) { Count.Bulls++; }
					//Else increment cows
					else { Count.Cows++; }

			}
		}
	}
	
	return Count;
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return GetHiddenWordLength(); }
