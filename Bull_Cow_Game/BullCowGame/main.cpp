/* This is the console executable, that makes use od the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all user
interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//Prototyping for unreal
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool PlayAgain();
void PrintGameSummary();

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

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {

	int32 MaxTries = BCGame.GetMaxTries();
	//Loop for the number of turns asking for guesses
	constexpr int32 LIMIT = 5;

	//TODO change from FOR to WHILE loop once we are validating tries
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess(); //TODO make loop checking valid

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls =" << BullCowCount.Bulls;
		std::cout << ". Cows =" << BullCowCount.Cows << "\n\n";


		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
	//TODO summarise game
	PrintGameSummary();
	return;
}

FText GetValidGuess() {

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {

		//Get guess from the user
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word \n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters \n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter an in lowercase \n\n";
			break;
		case EGuessStatus::OK:
			return Guess;
			break;
		default:
			return Guess;
			break;
		}
	} while (Status != EGuessStatus::OK); //Keep looping until we get no more errors 	
}

bool PlayAgain()  {

	BCGame.Reset();

	std::cout << "Do you want to play again with the same word?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN! \n";
	}
	else {
		std::cout << "BETTER LUCK NEXT TIME \n";
	}
}

