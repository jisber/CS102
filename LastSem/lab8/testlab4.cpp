#include <iostream>
#include <string>
#include<cstdlib>
#include<iomanip>

//Jacob_Isber, Lab 8, Cosc102

using namespace std;

//Declared Variables

string typeOfcard, firstCard, secondCard;
int Tcards[52], numOfPlayers, GR;
bool rcard;

//These are the card assignments an array

string cardAssignment[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

//These are the suite assignments in an array

string suiteAssignment[] = {"H","C","D","S"};


//This is the get random function, which allows randomization within max and min assigned varaibles

int GetRandom(int min,int max){
return (rand() % (max - min + 1)) + min;
}


//This is the DealCard function, the while loop with the int r = GetRandom allowes no duplicate cards to appear in the program

string DealCard(int numarr[],int person){
	rcard = true;
	
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

//This starts my int main function

int main() {

int Tscore;	

//Asking user to input the ammount of players into the game, also does not allow more than 26 players in the game			

	cout << "How many players? ";
		cin >> numOfPlayers;
	
	if(numOfPlayers > 26) {
		cout << "Too many players and not enough cards. " << endl;
	return 2;
	
	}

//This is a srand function that sets the seed of the random number generator
	
	srand (time(NULL));

//Gives the cards to the assigned players
	
	for(int j=1; j <= numOfPlayers; j++){
        firstCard = DealCard(Tcards, j);
		secondCard = DealCard(Tcards, j);
		Tscore = ScoreHand(Tcards, j);
    
//Outputs the correct values aswell as the needed lines.

	cout << "Player " << j << " has cards: " << firstCard;
	cout << " " << secondCard << setw(20) << " (" << Tscore << ")" << endl;
                
 }
                  
return 0;
}
