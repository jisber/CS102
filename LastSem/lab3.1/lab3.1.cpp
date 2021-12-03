#include <iostream>
using namespace std;

int main() {
 //Jacob Isber Lab3 for Cosc102
	char Op, userOp;
	double leftOperand, rightOperand, store,  results ;


	cout << "Enter left operand: ";
	//cin >> leftOperand;
	if (!(cin >> leftOperand)) {
	cerr << "Invalid left operand. " << endl;
	return 1;
	}

	cout << "Enter operation: ";
	// cin >> Op;
	if (!(cin >> Op)) {
	cerr << "Unknown operation: " << endl;
	return 3;
	}
	
		
	
	//This switch statements allows the char (Op) to be assigned and operation like addition and or subtraction.

	switch (Op) {
		case 'A':
		case 'a':
		case '+':
			userOp = '+';
			break;

		case 'S':
		case 's':
		case '-':
			userOp = '-';
			break;

		case 'M':
		case 'm':
		case 'x':
		case '*':
			userOp = '*';
			break;

		case 'D':
		case 'd':
		case '/':
			userOp = '/';
			break;
	
		/*This is the absolute value operation.
		 If the value inputed is less than 0 the function will multiply the value by -1 to make it positive */

		case 'B':
		case 'b':
		case '|':
			if (leftOperand < 0) {
				results = leftOperand * -1;
			}
			cout << "Results " << results << endl;

			return 0;

		default: 
			cout << "Unknown operation. " << endl;
		return 4;
	}


	/*This is the rightOperand function allowing the math be done
	 after assigning the operation values in the switch statement */

		cout << "Enter right operand: ";
	if (!(cin >> rightOperand)) {
	cerr << "Invalid right operand. " <<  endl;
	return 2;
	}

	/* This is the way the program knows which operation to do after the
	after rightOperand has been inputted. */

	if ( userOp == '+') {
	results = leftOperand + rightOperand;
	}   else if (userOp == '-') {
	results = leftOperand - rightOperand;
	}	else if (userOp == '*'){
		results = leftOperand * rightOperand;
	}	else if (userOp == '/') {
		results = leftOperand / rightOperand;
	}


	cout << "Result = " << results << endl;		
	
	return 0;
	
}
