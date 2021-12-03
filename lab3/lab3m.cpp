//Jacob Isber
//lab3m 
//1/21/19

#include <iostream>
using namespace std;

int main() {

	double lOp, rOp, result;
	char Op, userOP;
//Asks user for the actions.
	cout << "Enter left operand: ";
	if (!(cin >> lOp)) {
		cerr << "Invalid left operand. " << "\n";
		return 1;
	}


//Asks user for the operation. 
	cout << "Enter operation: ";
	cin >> Op;
	

//Switch statement to assign the operation to a specifc assignment. 
	switch (Op) {
		case 'a' :
		case 'A' :
		case '+' :
		userOP = '+';
			break;

		case 'm':
		case 'M':
		case '*':
		case 'x':
		case 'X':
			userOP = '*';
			break;

		case 'D':
		case 'd':
		case '/':
			userOP = '/';
			break;

		case 'S':
		case 's':
		case '-':
			userOP = '-';
			break;

		default: cout << "Unknown Operation." << "\n";
		 return 1;
	}
	//Stores the right operand.
	
	cout << "Enter right operand: ";
	if (!(cin >> rOp)) {
	cerr << "Invalid right operand. " << "\n";
	return 3;
	}

	//Reads in user operation and outputs results.
	if (userOP == '+') {
		result = lOp + rOp;
	}
	else if (userOP == '*') {
		result = lOp * rOp;
	}
	else if (userOP == '-') {
		result = lOp - rOp;
	}
	else if (userOP == '/') {
		result = lOp / rOp;
	}
	
	cout << "Result = " << result << '\n';



return 0;
}
