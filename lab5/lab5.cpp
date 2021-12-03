//Jacob Isber
//lab 5
//R 1.3

#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;

int main() {
	
	int Sbal = 1000, seed, bet, maxW, minW, maxB, minB;
	bool done;
	int reel[3];
	bool first = true;

	vector <int> bVec;
	vector <int> wVec;

//Inputs seeds and while loop is to error check.

	cout << "Input a seed: ";

	while(!(cin >> seed)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Input a seed: ";
	}
	cout << endl;

//Random Seed input.
	srand(seed);
		

//Start of while to to loob back the program.
	while (!done) {
		cout << "Your money: $" << Sbal << endl;
		cout << "Place a bet: $";
		
		while(!(cin >> bet)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Place a bet: $";
		}
//Error checks the bet to see if it is les than 0 and to see if it is the first time.

		if ((bet == 0) && (first == true)) {
			cout << endl;
			cout << "You walked away without playing." << endl;
			return 2;
		}

		if ((bet == 0) && (first == false)) {
			break;
		}

		if (bet > Sbal){
			cout << "Not enough money to place bet.";
			cout << endl;
			break;
		}

//Does math for the starting balance and the vector stores the bet. 
		Sbal -= bet;
		bVec.push_back(bet);

//Randomizes the wheel from 2-7 for the array
			
			for (int i = 0; i < 3; i++) {
				reel[i] = 2+rand()%(7-2+1);
				cout << reel[i] << " ";
			}
			cout << endl;
//if (7 && (reel[0] && reel[1] && reel[2]))
		if((reel[0] == 7) && (reel[1] == 7) && (reel[2] == 7)) {
			bet *= 10;
		}

//else if (( reel[0] && reel[1] && reel[2]))

//Checks to see if the reels lands on the winning numbers
		else if((reel[0] == reel[1]) && (reel[0] == reel[2]) && (reel[1] == reel[2])){
			bet *= 5;
		}

		else if((reel[0] == reel[1]) || (reel[0] == reel[2]) || (reel[2] == reel[1])){
			bet *= 2;
		}
		else {
			bet *= 0;
		}
		
//Checks to see if user lost

		if( bet > 0) {
			cout << "You won $" << bet << "!" << endl;
		}
		else {
			cout << "You didn't win." << endl;
		}

//Pushes back the bet into another array.

		wVec.push_back(bet);
		Sbal += bet;
		
		cout << endl;

		if (Sbal == 0) {
			cout << "You are out of money!" << endl;
			break;
		}
		cout << endl;
		first = false;
	}
	

	cout << endl;

//The next lines these just call back the user bets from the vectors and outputs to see how much the user wagere.

	for(int i = 0; i < bVec.size(); i++) {
		cout << "You wagered $" <<  bVec.at(i) << " and won $" << wVec.at(i) << "." << endl; 
	}
	
	cout << endl;

//Max and Min function

	maxB = bVec.at(0);
	minB = bVec.at(0);

	for (int i = 1; i < bVec.size(); i++) {
		if (bVec.at(i) > maxB) {
			maxB = bVec.at(i);
		}
		if (bVec.at(i) < minB) {
			minB = bVec.at(i);
		}
	}

//Couts the small and largest wagers.
	cout << "Your smallest wager was $" << minB << "." << endl;
	cout << "Your largest wager was $" << maxB << "." << endl;

	
//Max and min function.

	maxW = wVec.at(0);
	minW = wVec.at(0);

	for(int i = 1; i < wVec.size(); i++){
		if (wVec.at(i) > maxW){
			maxW = wVec.at(i);
		}
		if (wVec.at(i) <  minW && wVec.at(i) !=0) {
			minW = wVec.at(i);
		}

	}
	cout << "Your smallest winning was $" << minW << "." << endl;
	cout << "Your largest winning was $" << maxW << "." << endl;

	return 0;
}

