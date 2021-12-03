//Jacob Isber
//Lab4 mini lab

#include <iostream>

using namespace std;

int main() {

	bool quit;
	string action;
	double intVal, depVal, wDraw;

	//Initializes initial ammount also error checks to make sure a number was entered.

	cout << "Enter your initial account amount: ";
	if (!(cin >> intVal)) {
		cerr << "Invalid initial ammount." << endl;
		return 2;
	}
	
	//This while loop allows the question to be looped until the user manually quits.
	

	while(!quit) {

		cout << "What do you want to do? ";
		cin >> action;

	//These if statements allow the action to take place.
	
			if  (action == "deposit") {	
				cout << "How much? ";
				cin >> depVal;
				intVal = depVal + intVal;
			}
				

			else if (action == "withdrawal") {		
				cout << "How much? ";
				cin >> wDraw;
				intVal = intVal - wDraw;
			}		
		
			else if (action == "balance") {
				cout << "You have $" << intVal<< endl;
			}	

		
			else if (action == "quit") {
				quit = true;
			}

	//This is the error check. It didn't specify to do so in the instructions but felt necessary in this situation.
			else 
				cout << "Invalid action, please try again!" << endl;

	}
	return 0;
}

