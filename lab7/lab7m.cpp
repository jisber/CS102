//Jacob Isber
//Mini lab 7
//2/26/19

#include<iostream>

using namespace std;

int main() {

//Declared array with 52 cards. 
string cardArray[13] = {"2","3","4","5","6","7","8","9","10","J(Jack)","Q(Queen)","K(King)","A(Ace)"};
int index;

//Starts while loop and gets user index input.
while (index <= 51) {
	cout << "Enter a card index: ";
	cin >> index;

//These if's and else if's make sure to print out the correct array index.
	if((index >= 0) && (index <= 12)) {
		cout << "That's the " <<  cardArray[index] << " of Hearts" << endl;
	}

	else if((index > 12) && (index <= 25)) {
		cout << "That's the " <<  cardArray[index - 13] << " of Diamonds" << endl;
	}


	else if((index >= 26) && (index <= 38)) {
		cout << "That's the " <<  cardArray[index - 26] << " of Spades" << endl;
	}


	else if((index >= 39) && (index <= 51)) {
	cout << "That's the " <<  cardArray[index - 39] << " of Clubs" << endl;
	}
}

//The while loop will break when the index < 51 and then cout this error statement. 
cout << "Inputed index is not in the range!" << endl;

return 0;
}
