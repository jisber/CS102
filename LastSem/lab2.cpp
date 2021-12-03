//Jacob Isber
//Lab2
//1/19/19
#include <iostream>

using namespace std; 

int main() {

	
	string firstName, middleName, streetName, streetType; 
	 int  age, streetNumber, i;

for (;;) {
	cout << "Isber" << endl;
}

	//Asking user for the inputs.	
	for (int i = 0; i<=1; i++); {
	cout << i+1;
	}
		
		cout << "Enter your first and middle names:  ";
	cin >> firstName >>  middleName;
	
	
	cout << "Enter your age:  ";
	cin >>  age;
	
	cout << "Enter your street number, name, and type: "; 
	cin >>  streetNumber >> streetName >> streetType; 
	cout << "\n";	


	//Alters and outputs new variables
	cout << "Your movie star name is " <<  streetName << " " <<  middleName << ". ""\n";
	cout << "You will play a " << (streetNumber%age)*3 << " year old. " << endl;
	cout << "Your address is " << (age*700)/streetNumber <<  " "  <<  firstName << " "  << streetType << ". ""\n";
	

	return 0;
}
