#pragma once
#include <string>

using int32 = int;
using FString = std::string;

// Structure handling values of bulls and cows
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase

};

class FBullCowGame {
public:
	FBullCowGame();

	void Reset();
	int GetCurrentTry() const;
	bool IsGameWon() const;
	int GetMaxTries() const;
	FString GetHiddenWord() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString Guess) const;

	FBullCowCount SubmitValidGuess(FString);



// Private variables = member variables
private:
	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;

	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};