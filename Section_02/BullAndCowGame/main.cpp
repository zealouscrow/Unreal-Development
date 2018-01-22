// Main

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
void ShowGuess();

// Entry point for the application
int main() {
	constexpr int NUMBER_ITERATIONS = 5;
	PrintIntro();

	for (int count = 1; count <= NUMBER_ITERATIONS; count++) {
		GetGuess();
		ShowGuess();

		cout << endl;
	}

	cout << endl;

	return 0;
}

// Introduces the game
void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a simple and fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	return;
}

// Retrieve guess as a string from user input
string GetGuess() {
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	
	return Guess;
}

// Shows the guess back to the user.
void ShowGuess() {
	string Guess = GetGuess();
	cout << "Your guess is: " << Guess << endl;
}
