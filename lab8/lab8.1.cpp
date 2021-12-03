//Jacob Isber
//Lab8
//3/18/19
//**********The only problem I had with this code was left justifying. I tried multiple ways and it just wouldn't work. my left "(" would shift to the left.**********
//Revision 1.4

#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector> 

using namespace std;

//Function Prototypes
int GetRandom(int, int);
string DealCard(int [], int);
int ScoreHand( int [], int);
void AceFunc(int);
void AceFuncLoop(int);

//Declared global variables and arrays
string cardArray[] = {"A", "2", "3","4","5","6","7","8","9","10","J","Q","K"};
const string suitArray[] = {"H","D","S","C"};
int deckArray[52] = {0};
int Ace = 0;
int Ace1 = 0;

	string cardOne, cardTwo, HS;
	int TotalScore, AcePoint;;

	vector<string> PlayerCard, DealerCard;

int main() {

//Declared variables for main function
//	string cardOne, cardTwo, HS;
//	int TotalScore, AcePoint;;

//Initializes player and dealer vectors
//`	vector<string> PlayerCard, DealerCard;
	
	srand(time(NULL));

//Deals cards to dealer
	cardOne = DealCard(deckArray, 1);
	cardTwo = DealCard(deckArray, 1);
	TotalScore = ScoreHand(deckArray, 1);

//Stores dealer cards into a vector
	DealerCard.push_back(cardOne);
	DealerCard.push_back(cardTwo);

//Lines 45-58 checks to see if dealer should choose if ace is worth 1 or 11.
	if (cardOne == "AS" || cardOne == "AH" || cardOne == "AC" || cardOne == "AD" )  {
			if(ScoreHand(deckArray, 1) + 10 == 20 || ScoreHand(deckArray, 1) + 10 ==  21) {
				Ace1 += 10;
				TotalScore = ScoreHand(deckArray, 1);
			}
	}

	if (cardTwo == "AS" || cardTwo == "AH" || cardTwo == "AC" || cardTwo == "AD" )  {
			if(ScoreHand(deckArray, 1) + 10 == 20  || ScoreHand(deckArray, 1) + 10 == 21) {
				Ace1 += 10;
				TotalScore = ScoreHand(deckArray, 1);
			}
	}
 	
	cout << "Dealer has cards: "  << cardOne << " " << cardTwo << " " << setw(20)  <<  " (" << TotalScore << ")"  << endl;
	
//Deals cards to player 
	cardOne = DealCard(deckArray, 2);
	cardTwo = DealCard(deckArray, 2);
	TotalScore = ScoreHand(deckArray, 2);

//Storing player cards into a vector
	PlayerCard.push_back(cardOne);
	PlayerCard.push_back(cardTwo);


	cout << "You have cards: " << cardOne << " " << cardTwo << " " << setw(20) << " (" << TotalScore  << ")"  << endl;


	if(ScoreHand(deckArray, 1) == 21) {
cout << "Dealer wins! "<< endl;
		return 7;
	}
	
	AceFunc(1);

//Lines 74-101 checks and asks user if they want an ace worth 1 or 11
//AceFunc(1);
//Checks to see if player has won.		
	if (ScoreHand(deckArray, 2) == 21) {
				cout << "Player wins!" << endl;
					return 5;
				}

//Starts while loop to ask player to hit or stand
	while(true) {
		
		cout << "Hit or stand      ?: ";
		cin >> HS;
		cout << endl;
	
//Checks to see if user has inputed hit
		if ((HS == "Hit") || (HS == "hit")) {

//Dealers one aditional card to player.			
			cardOne = DealCard(deckArray, 2);
			TotalScore = ScoreHand(deckArray, 2);
			PlayerCard.push_back(cardOne);

			cout << "Dealer has cards : ";
			for (unsigned int i = 0; i < DealerCard.size(); i++) {
				cout << DealerCard.at(i) << " ";	
			}
		
			cout << setw(20) << "(" <<  ScoreHand(deckArray, 1) << ")";
			cout << endl;
		
			cout << "You have cards : ";
			for (unsigned int i = 0; i < PlayerCard.size(); i++) {
				cout << PlayerCard.at(i) << " "; 
			}
				cout << setw(20) << "(" << ScoreHand(deckArray, 2) << ")";
				cout << endl;

				 AceFuncLoop(1);
//Again lines 142 - 170 checks if user wants and ace to be worth a 1 or 11
//AceFuncLoop(1)

//Line 172-182 checks players score to see if they have won or busted
			if (ScoreHand(deckArray, 2) >  21) {
				cout << "Player busts, dealer wins!" << endl;
				break;
			}
			else if(ScoreHand(deckArray, 2) == 21) {
				cout << "Player wins!" << endl;
				break;
			}
		}

//Checks if user inputes stand
		else if ((HS == "Stand") || (HS == "stand")) {
			if (ScoreHand(deckArray, 1) > ScoreHand(deckArray, 2)){
				cout << "Dealer wins!" << endl;
				return 4;
			}

//Another while loop to check and see if dealer needs to hit.
			while (ScoreHand(deckArray, 1) < 18) {

//If dealer needs to hit, deal another card.				
				cardOne = DealCard(deckArray, 1);
				DealerCard.push_back(cardOne);

//Lines 198 - 210 checks to see if dealer needs to choose 1 or an 11 for an ace.				
				if (cardOne == "AS" || cardOne == "AH" || cardOne == "AC" || cardOne == "AD" )  {
					if(ScoreHand(deckArray, 1) + 10 == 20 || ScoreHand(deckArray, 1) + 10 ==  21) {
						Ace1 += 10;
						TotalScore = ScoreHand(deckArray, 1);
					}
				}

				if (cardTwo == "AS" || cardTwo == "AH" || cardTwo == "AC" || cardTwo == "AD" )  {
					if(ScoreHand(deckArray, 1) + 10 == 20  || ScoreHand(deckArray, 1) + 10 == 21) {
						Ace1 += 10;
						TotalScore = ScoreHand(deckArray, 1);
					}
				}


				cout << "Dealer hits :";
					for (unsigned int i = 0; i < DealerCard.size(); i++) {
						cout << DealerCard.at(i) << " ";	
					}
				cout << setw(20) << "(" << ScoreHand(deckArray, 1) << ")";
				cout << endl;
	
//Checks to make sure if dealer busts.				
				if(ScoreHand(deckArray, 1) > 21) {
					cout << "Dealer busts, player wins!" << endl;
					return 1;
				}

				 if (ScoreHand(deckArray, 1) >= 18) {
					cout << "Dealer Stands: ";
					for (unsigned int i = 0; i < DealerCard.size(); i++) {
						cout << DealerCard.at(i) << " ";
					}
					cout << setw(20) << "(" << ScoreHand(deckArray, 1) << ")" << endl << endl;
				}

					cout << "Dealer has cards: ";
					for (unsigned int i = 0; i < DealerCard.size(); i++) {
						cout << DealerCard[i] << " ";
					}
					cout << setw(20) << "(" << ScoreHand(deckArray, 1) << ")";
					cout << endl;
					
					cout << "You have cards : ";
					for (unsigned int i = 0; i < PlayerCard.size(); i++) {
						cout << PlayerCard.at(i) << " "; 
					}

				cout << setw(20) << "(" << ScoreHand(deckArray, 2) << ")";
				cout << endl;
				cout << endl;
				
			}

//Checks to see all conditions and output results.			
				if (ScoreHand(deckArray, 1) < ScoreHand(deckArray, 2)) {
				cout << "Player wins!" << endl;
					return 2;
				}
				if (ScoreHand(deckArray, 1) == ScoreHand(deckArray, 2)) {
				cout << "Player and Dealer draw." << endl;
					return 3;
				}
				if (ScoreHand(deckArray, 1) > ScoreHand(deckArray, 2)){
					cout << "Dealer wins!" << endl;
					return 4;
					}
	

		}
	}
	return 0;
}

//GetRandom function

int GetRandom(int min, int max) {
	return (rand() %(max - min + 1)) + min;
}

//DealCard function
string DealCard(int deckArray[], int Player) {
	bool randomCard = true;
	int RN;
	string cardType;

	while(randomCard) {
		RN = GetRandom(0, 51);
		if(deckArray[RN] == 0) {
			cardType = (cardArray[RN % 13] + suitArray[RN / 13]);
			deckArray[RN] = Player;
			randomCard = false;
		}
	}
	return cardType;
}

//ScoreHand function
int ScoreHand(int deckArray[], int Player) {
	int tempValue;
	int TotalScore = 0;
	for (int i = 0; i < 52; i++) { 
		if(deckArray[i] == Player) {
			tempValue = (i%13) + 1;
			if(tempValue >= 10) {
				tempValue = 10;
			}
		TotalScore += tempValue;
		}
	}
	if (Player == 2) {
		TotalScore += Ace;
	}
	if(Player == 1) {
		TotalScore += Ace1;
	}
		return TotalScore;
}
void AceFunc(int Player) {
	if (cardOne == "AS" || cardOne == "AH" || cardOne == "AC" || cardOne == "AD" )  {
		cout << "Would you like your Ace to be worth 1 or 11? (1)/(11) ";
		cin >> AcePoint;
			if(AcePoint == 11) { 
				Ace += 10;
				TotalScore = ScoreHand(deckArray, 2);
				cout << "You have cards: " << cardOne << " " << cardTwo << " " << setw(20) << "(" << TotalScore << ")"  << endl;

			}
			else {
				cout << "You have cards: " << cardOne << " " << cardTwo << " " << setw(20) << "(" << TotalScore << ")"  << endl;

			}
	}
		if (cardTwo == "AS" || cardTwo == "AH" || cardTwo == "AC" || cardTwo == "AD" )  {
		cout << "Would you like your Ace to be worth 1 or 11? (1)/(11) ";
		cin >> AcePoint;
			if(AcePoint == 11) { 
				Ace += 10;
				TotalScore = ScoreHand(deckArray, 2);
				cout << "You have cards: " << cardOne << " " << cardTwo << " " << setw(20) << "(" << TotalScore << ")"  << endl;

			}
			else {
				cout << "You have cards: " << cardOne << " " << cardTwo << " " << setw(20) << "(" << TotalScore << ")"  << endl;

			}
	}
}

void AceFuncLoop(int Player) {
			if (cardOne == "AS" || cardOne == "AH" || cardOne == "AC" || cardOne == "AD" )  {
				cout << "Would you like your Ace to be worth 1 or 11? (1)/(11) ";
				cin >> AcePoint;
					if(AcePoint == 11) { 
						Ace += 10;
						TotalScore = ScoreHand(deckArray, 2);
						cout << "You have cards: ";
						for (unsigned int i = 0; i < PlayerCard.size(); i++) {
							cout << PlayerCard.at(i) << " "; 
						}
					cout << setw(20) << "(" << ScoreHand(deckArray, 2) << ")";
					cout << endl;



					}
				else {
					cout << "You have cards: ";
					for (unsigned int i = 0; i < PlayerCard.size(); i++) {
						cout << PlayerCard.at(i) << " "; 
					}
					cout << setw(20) << "(" << ScoreHand(deckArray, 2) << ")";
					cout << endl;



				}
			}

		if (cardTwo == "AS" || cardTwo == "AH" || cardTwo == "AC" || cardTwo == "AD" )  {
			cout << "Would you like your Ace to be worth 1 or 11? (1)/(11) ";
			cin >> AcePoint;
				if(AcePoint == 11) { 
					Ace += 10;
					TotalScore = ScoreHand(deckArray, 2);
					cout << "You have cards: "; 
					for (unsigned int i = 0; i < PlayerCard.size(); i++) {
						cout << PlayerCard.at(i) << " "; 
					}
				cout << setw(20) << "(" << ScoreHand(deckArray, 2) << ")";
				cout << endl;



				}
				else {
					cout << "You have cards: "; 
					for (unsigned int i = 0; i < PlayerCard.size(); i++) {
						cout << PlayerCard.at(i) << " "; 
					}
					cout << setw(20) << "(" << ScoreHand(deckArray, 2) << ")";
					cout << endl;



				}
		}
}
