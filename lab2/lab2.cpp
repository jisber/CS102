//Jacob Isber
//Mini lab 2
//1/9/18
#include <iostream>
using namespace std;

int main() {

//Initializes String and Int names
string Fname, Lname, Sadd, Stype;
int age, Snum;


//Asks user questions and stores variables.
cout << "Enter your first and last names: ";

cin >> Fname >> Lname;

cout << "Enter your age: ";

cin >> age;

cout << "Enter your street address: ";

cin >> Snum >> Sadd >> Stype;


//Outputs stored variables
cout << "You are " << Fname << " "  << Lname << ", who is " << age << " years old ""\n";

cout << "and lives at house number " << Snum << "\n";
	
cout <<	"of the street " << Sadd << " which is a/an " << Stype << "\n";

	


return 0;
}
