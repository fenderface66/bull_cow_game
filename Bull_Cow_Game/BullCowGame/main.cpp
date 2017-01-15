#include <iostream>
#include <string>


using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool	AskToPlayAgain();

//Entry point for application
int main() {
	
	PrintIntro();	
	PlayGame();
	AskToPlayAgain();
	//Exit the application
	return 0;
}

void PrintIntro() {
	//Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to bulls and cows, a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	//Loop for the number of turns asking for guesses
	constexpr int LIMIT = 5;
	for (int count = 1; count <= LIMIT; count++) {
		string Guess = GetGuess();
		cout << "Your guess was " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() {
	//Get guess from the user
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()  {
	cout << "Do you want to play again?";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
