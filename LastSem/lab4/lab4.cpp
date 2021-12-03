#include <iostream>
#include <limits>
using namespace std;

int main(){
	//Jacob Isber Lab4.cpp Cosc102
	string type = "car";
	double miles, gallons, carTotal=0, truckTotal=0, truckTotalgal=0, carTotalgal=0;
	//Entire statement in a do - while to allow the program to keep asking to enter a command.
	do {	
		 do 
		{  if  (!(( type == "car") || (type == "truck") || (type == "done"))) {
			cout << "Unknown command: " << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
			cout << "Enter command: ";
			cin >> type;

		}	while  (! (( type == "car") || (type == "truck" ) || (type == "done" )));
				
		if (type == "done") 
			break;
	//This allows miles and gallons for car to be entered. The cin.clear and cin.ignore allow the statement to ignore infities. 
		do {
			cout << "Enter " << type << "'s miles: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> miles;
		} while (!(miles));
			
	//This allows miles and gallons for truck to be entered. The cin.clear and cin.ignore allow the statement to ignore infinities.		
		do { 
			cout << "Enter " << type << "'s gallons: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> gallons; 
		} while (!(gallons));
	//This if else allows the calculations to be done for average mpg. 
		if (type == "truck") { 
			truckTotal = truckTotal + miles;
			truckTotalgal = truckTotalgal + gallons;
		}
		else{
			carTotal = carTotal +  miles;
			carTotalgal = carTotalgal + gallons;
		}



	} while (!( type == "done" ));

  //This allows the "fleet has no car and or truck" or outputs the "Average car  mpg".
	if (carTotal == 0)
		cout << "fleet has no cars" << endl;
		else {
		carTotal = carTotal/carTotalgal;
		cout << "Average car MPG = " << carTotal << endl;
		}
		if (truckTotal == 0) 
		cout << "fleet has no trucks" << endl;
		else {
		truckTotal = truckTotal/truckTotalgal;
		cout << "Average truck MPG = " << truckTotal << endl;
		}

	return 0;
}

