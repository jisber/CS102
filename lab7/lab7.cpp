//Jacob Isber
//Lab7
//3/05/2019
#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>

using namespace std;

//Function Prototypes;
int GetRandom(int, int);
string DealCard(int [], int);
int ScoreHand(int [], int);

//Declared arrays.
const string cardArray[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const string suitArray[] = { "H", "D", "S", "C"};
int deckArray[52] = {0};

int main() {

//Declared variables within the int main function. 
	string cardOne, cardTwo;
	int Totalscore;
	int numOfplayers;

//Inputs and error checks the number of players.
	cout << "How many players? ";
	cin >> numOfplayers;

	if(numOfplayers > 26) {
		cout << "Too many players." << endl;
		return 1;
	}

//Random Number Seed
	srand(time(NULL));

//Calls all three functions and loops through and assigns values.
	for(int i = 1; i <= numOfplayers; i++){
		cardOne = DealCard(deckArray, i);
		cardTwo = DealCard(deckArray, i);
		Totalscore = ScoreHand(deckArray, i);

//Outputs cards and score.
		cout << "Player " << setw(2) << left << i  << " has cards: " << setw(1) << cardOne;
		cout << " " << cardTwo;
		cout << setw(15) << right << setw(15) << " (" << right << Totalscore << right  <<  ")" << endl;
	}

	return 0;
}

//GetRandom fucntion to randomize numebes.
int GetRandom(int min, int max) {

	return (rand() % max - min);
}

//DealCard function to deal cards to players.
string DealCard(int deckArray[], int Player) {
	bool randomCard = true;	
	int RN;
	string cardType;

	while (randomCard) {
		RN = GetRandom(0,52);
		if(deckArray[RN] == 0) {
			cardType = (cardArray[RN % 13] + suitArray[RN / 13]);
			deckArray[RN] = Player;
			randomCard = false;
		}
	}
	return cardType; 
}

//ScoreHand function allows scoring to occure.
int ScoreHand(int deckArray[], int Player) {
	int tempValue;
	int Totalscore = 0;
	for(int i = 0; i < 52; i++) {
		if(deckArray[i] == Player) {
			tempValue = (i%13) + 1;
			if (tempValue >= 10) {
				tempValue = 10;
			}
			Totalscore += tempValue;
		}
		}
		return Totalscore;
	}

