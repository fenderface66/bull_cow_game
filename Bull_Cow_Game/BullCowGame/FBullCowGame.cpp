#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries()	const {	return MyMaxTries;	}
int32 FBullCowGame::GetCurrentTry() const	{	return MyCurrentTry;	}
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const	{	return false;	}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "Planet";
	
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{
	//if the guess isn't an isogram
	if (false) { 
		return EGuessStatus::Not_Isogram;
	}
	//if the guess isn't lowercase
	else if (false) {
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
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
				if (i = j) {
					BullCowCount.Bulls++; //Increment Bulls
				}
				else {
					BullCowCount.Cows++; //Must be a cow
				}
			}
		}
	}
	// Compare letters against the hidden word

	return BullCowCount;
}
