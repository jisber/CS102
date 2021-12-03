#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>

//Jacob_Isber, Lab 9, Cosc102

using namespace std;

//Declared Variable

int Tcards[52];
//These are the card assignments an array

string cardAssignment[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

//These are the suite assignments in an array

string suiteAssignment[] = {"H","C","D","S"};


//This is the get random function prototype

int GetRandom(int , int);

//This is the DealCard prototype function

string DealCard(int[] , int);


//This is the ScoreHand prototype function

int ScoreHand(int[] , int);
//This starts my int main function

int main() {

	//Declared variables, i was made unsigned because of a compiler warning
	int Tscore;
	unsigned int i;

	//This is a vecotr to allow my original score to be stored into to. 
	vector<string> PlayerCard, DealerCard;

	string firstCard, secondCard, HoS;

	//This is a srand function that sets the seed of the random number generator

	srand (time(NULL));

	//First round of drawing for dealer

	firstCard = DealCard(Tcards, 1);
	secondCard = DealCard(Tcards, 1);
	Tscore = ScoreHand(Tcards, 1);

	//Pushes back original dealer cards into the vector	
	DealerCard.push_back(firstCard);
	DealerCard.push_back(secondCard);


	//Outputs correct current value and card types for the dealer

	cout << "Dealer" <<  " has cards: " << firstCard;
	cout << " " << secondCard << setw(20) << " (" << Tscore << ")" << endl;

	//First round of drawing for the Player
	firstCard = DealCard(Tcards, 2);
	secondCard = DealCard(Tcards, 2);
	Tscore = ScoreHand(Tcards, 2);

	//Allows the original values to be pushed back to the vector for the player.
	PlayerCard.push_back(firstCard);
	PlayerCard.push_back(secondCard);

	//Outputs correct current value and card types for the player
	cout << "You" << " have cards: " << firstCard;
	cout << " " << secondCard << setw(22) << " (" << Tscore << ")" << endl; 

	//This is the start for the while loop to allow player and dealer to hit or stand and ask multiple times
	while(true) {
		cout << "Hit or Stand " << setw(2) << "?";
		cin >> HoS;
		cout << "\n";
		//This reads the input "hit" and deals a card to the player also allows the output of the new card types and values
		if (HoS == "hit") {
			firstCard = DealCard(Tcards,2);
			PlayerCard.push_back(firstCard);
			cout << "Dealer has cards: ";
			for (i = 0; i < DealerCard.size(); i++) {
				cout << DealerCard[i] << " ";	
			}
			cout << setw(20) << " (" << ScoreHand(Tcards, 1) << ")" << endl;

			cout << "You have cards: ";
			for(i = 0; i < PlayerCard.size(); i++) {
				cout << PlayerCard[i] << " ";
			}

			cout << setw(22) << " (" << ScoreHand(Tcards, 2) << ")" << endl; 
			//The last two if statements outputs the results.=
			if(ScoreHand(Tcards, 2) > 21) {
				cout << "Player busts, dealer wins!" << endl;
				break;
			}
			if(ScoreHand(Tcards, 2) == 21) {
				cout << "Player wins!" << endl;
				break;
			}
		}
		//This reads the input "stand" and will also auto deal the dealer if the dealers hand is < 18
		else if(HoS == "stand"){
			while(ScoreHand(Tcards, 1) < 18) {
				firstCard = DealCard(Tcards,1);
				DealerCard.push_back(firstCard);

				cout << "Dealer hits: ";
				for (i = 0; i < DealerCard.size(); i++) {
					cout << DealerCard[i] << " ";
				}
				cout << setw(20) << " (" << ScoreHand(Tcards, 1) << ")" << endl;
			
				//Attempted to out "Dealer busts" right after he/she reaches over 21 but the statement wasn't breaking although I had break in the code

				if(ScoreHand(Tcards, 1) > 21) {
					cout << "Dealer bust, player wins!" << endl;
					return 1;
				}

				if(ScoreHand(Tcards, 1) >= 18) {
				cout << "Dealer stands: ";
				for (i = 0; i < DealerCard.size(); i++) {
					cout << DealerCard[i] << " ";
				}
				cout << setw(17) << " (" << ScoreHand(Tcards, 1) << ")" << endl << endl;
				}

				cout << "Dealer has cards: ";
				for (i = 0; i < DealerCard.size(); i++) {
					cout << DealerCard[i] << " ";	
				}

				cout << setw(20) << " (" << ScoreHand(Tcards, 1) << ")" << endl;

				cout << "You have cards: ";
				for(i = 0; i < PlayerCard.size(); i++) {
					cout << PlayerCard[i] << " ";
				}

				cout << setw(22) << " (" << ScoreHand(Tcards, 2) << ")" << endl; 

			}
			//Outputs results for the scoring
	//		if(ScoreHand(Tcards, 1) > 21) {
	//			cout << "Dealer bust, player wins!" << endl;
	//			break;
	//		}
			if(ScoreHand(Tcards, 1) == ScoreHand(Tcards, 2)) {
				cout << "Player and dealer draw" << endl;
				break;
			}
			if(ScoreHand(Tcards, 1) > ScoreHand(Tcards, 2)) {
				cout << "Dealer wins!" << endl;
				break;
			}
			if(ScoreHand(Tcards, 1) < ScoreHand(Tcards, 2)) {
				cout << "Player wins!" << endl;
				break;
			}

		}


	}

	return 0;
}


//This is the get random function, which allows randomization within max and min assigned varaibles

int GetRandom(int min,int max){
	return (rand() % (max - min + 1)) + min;
}

//This is the DealCard function, the while loop with the int r = GetRandom allowes no duplicate cards to appear in the program

string DealCard(int numarr[],int person){
	int GR;
	string typeOfcard;
	bool rcard = true;

	while(rcard){
		GR= GetRandom(0,51);
		if(numarr[GR] == 0){
			typeOfcard = (cardAssignment[GR % 13] + suiteAssignment[GR / 13]);
			numarr[GR] = person;
			rcard = false;
		}
	}

	return typeOfcard;
}


//This is the ScoreHand function, reason for the temp variable was to allows me to get J, Q, K set to 10

int ScoreHand(int numarr[],int person){

	int temp, Tscore = 0;

	for(int i=0; i<52 ;i++){
		if(numarr[i] == person){
			temp = (i%13) + 1;
			if (temp >= 10) {
				temp = 10;
			}
			Tscore += temp;
		}
	}	
	return Tscore;
}
