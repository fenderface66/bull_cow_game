#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() //default constructor
{
	Reset();
}


int32 FBullCowGame::GetCurrentTry() const	{	return MyCurrentTry;	}
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const	{	return bGameWon;	}

int32 FBullCowGame::GetMaxTries()	const {
	TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, {4, 7}, {5,9}, {6,11} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

bool FBullCowGame::isIsogram(FString Word) const	
{	

	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) {	return true;	}

	TMap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word) { // for all letters of the word

	Letter = tolower(Letter);

		// if the letter is in the map
	if (LetterSeen[Letter]) { return false; } //we do NOT have an isogram
	else {
		LetterSeen[Letter] = true;
	} 

	}
	return true;	
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word) {
		// if not a lowercase letter
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

	bGameWon = false;
	MyMaxTries = GetMaxTries();
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{
	//if the guess isn't an isogram
	if (!isIsogram(Guess)) { 
		return EGuessStatus::Not_Isogram;
	}
	//if the guess isn't lowercase
	else if (!IsLowerCase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

	//if the guess length is wrong

	//otherwise
	return EGuessStatus::OK;
}

// Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// Increment the turn number
	MyCurrentTry++;

	// Setup a return variable
	FBullCowCount BullCowCount;

	// Loop though all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {
		//Compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {

			// If they match then
			if (Guess[j] == MyHiddenWord[i]) {
				// If they're in the same place
				if (i == j) {
					BullCowCount.Bulls++; //Increment Bulls
				}
				else {
					BullCowCount.Cows++; //Must be a cow
				}
			}
		}
	}


	// Check if user has won
	if (BullCowCount.Bulls == HiddenWordLength) {
		bGameWon = true;
	}
	else {
		bGameWon = false;
	}
	IsGameWon();

	// Compare letters against the hidden word

	return BullCowCount;
}


