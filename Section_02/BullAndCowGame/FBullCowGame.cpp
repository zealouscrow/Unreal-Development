#include "FBullCowGame.h"

void FBullCowGame::Reset() {
}

int FBullCowGame::GetCurrentTry() {
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() {
	return false;
}

int FBullCowGame::GetMaxTries() {
	return MyMaxTries;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}
