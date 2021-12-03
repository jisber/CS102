#include <iostream>

using namespace std;

int main() {
   
	char Op;


	double leftOprand, rightOprand;

	cout << "Enter left operand: " << endl;
	cin >> leftOprand;
	if (!(leftOprand > -100000000) && (leftOprand < 100000000)) {
		cout << "Invalid left operand.";
		return 1;
	}
	cout << "What operation? " << endl;
	cin >> Op;
	






return 0;
}	
