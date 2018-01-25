#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	//If guess isn't an isogram
	if (false) {
		return EGuessStatus::Not_Isogram;
	}

	//If guess isn't all lowercase
	else if (false) {
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

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return GetHiddenWord().length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

