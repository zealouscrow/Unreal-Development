#pragma once
#include <string>
class FBullCowGame {
public:
	void Reset(); // TODO: make a more rich return value
	int GetCurrentTry();
	bool IsGameWon();
	int GetMaxTries();
	bool CheckGuessValidity(std::string);



// Private variables = member variables
private:
	int MyMaxTries = 5;
	int MyCurrentTry = 1;
};