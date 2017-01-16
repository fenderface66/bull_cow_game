#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool PlayAgain();

//Instantiate
FBullCowGame BCGame;

//Entry point for application
int main() {
	
	do {
		PrintIntro();
		PlayGame();
	} while (PlayAgain());
	
	//Exit the application
	return 0;
}

void PrintIntro() {
	//Introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to bulls and cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {

	int MaxTries = BCGame.GetMaxTries();
	//Loop for the number of turns asking for guesses
	constexpr int LIMIT = 5;

	//TODO change from FOR to WHILE loop once we are validating tries
	for (int count = 1; count <= LIMIT; count++) {
		std::string Guess = GetGuess(); //TODO make loop checking valid

		// Submit valid guess to the game
		// Print number of bulls and cows
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
	//TODO summarise game
}

std::string GetGuess() {

	int CurrentTry = BCGame.GetCurrentTry();

	//Get guess from the user
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool PlayAgain()  {

	BCGame.Reset();

	std::cout << "Do you want to play again?";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}
