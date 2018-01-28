/*
Header file accompanying FBullCowGame.cpp.
Includes an additional helper struct and enum.

Author: https://github.com/zealouscrow

*/

#pragma once
#include <string>
#include <list>
#include <vector>

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
	FString GenerateHiddenWord();
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
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	std::vector<FString> ThreeLetter = { "cat", "bat", "cue", "doe", "mow", "sad", "tan", "you" };
	std::vector<FString> FourLetter = { "find", "jump", "myth", "cats", "dogs", "yelp", "goes", "sand", "each" };
	std::vector<FString> FiveLetter = {"brick", "waltz", "plane", "blank", "nymph", "leans", "baked", "court" };
	std::vector<FString> SixLetter = { "drying", "flutes", "scream", "daikon","umbral", "sailor","magpie", "broken" };
};