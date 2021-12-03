//Jacob Isber
//Lab4 
#include <iostream>
#include <limits>
using namespace std;

int main() {
	
	string action;
	double Cmile=0, Cgal=0, Tmile=0, Tgal=0, CMtotal, TMtotal, CGtotal, TGtotal;
	bool done;

//This starts my while loop to allow the "Enter command" question and input to be repeated.
	while (!done) {
		
		cout << "Enter command: ";
		cin >> action;

//If statesments determin the user input.
		if (action == "car") {	
			cout << "Enter car's miles:  ";

//The cin.clear and cin.ignore function ignores letters and allow my program to only accept numbers.
//Stores and adds car miles and gallons.

		while(!(cin >> Cmile) ) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter car's miles: "; 
			}
			CMtotal += Cmile;


			cout << "Enter car's gallons: ";

		while(!(cin >> Cgal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter car's gallons: ";
			}
			CGtotal += Cgal;
			}
//Determins if the user inputes truck and also inputes trucks miles and gallons.
		else if (action == "truck") {
			cout << "Enter truck's miles: ";

		while(!(cin >> Tmile)) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter truck's miles: ";
		}
			TMtotal += Tmile;
			cout << "Enter truck's gallons: ";

			while(!(cin >> Tgal)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter trucks gallons ";
		}	
			TGtotal += Tgal;
	
		
		}

//If user inputs done quit the program.
		else if (action == "done") {
		done = true;
		}

//Basically my default statment. 
		else {
			cout << "Unknown command. " << endl;
		}
		
	 		

	}

//This does the math and also detrmins if the fleet has vehicles.
	if (Cmile > 0) {
		cout << "Average car MPG = " << CMtotal / CGtotal << endl;
	}

	else {
		cout << "Fleet has no cars. " << endl;
	}

	if (Tmile > 0) {
		cout << "Average truck MPG = " << TMtotal / TGtotal << endl;
	}

	else {
		cout << "Fleet has no trucks. " << endl;
	}


	return 0;
}
