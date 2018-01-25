#pragma once
#include <string>

using int32 = int;
using FString = std::string;

// Structure handling values of bulls and cows
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame {
public:
	FBullCowGame();

	void Reset(); // TODO: make a more rich return value
	int GetCurrentTry() const;
	bool IsGameWon() const;
	int GetMaxTries() const;
	FString GetHiddenWord() const;
	int32 GetHiddenWordLength() const;
	bool CheckGuessValidity(FString Guess);

	FBullCowCount SubmitGuess(FString);



// Private variables = member variables
private:
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};