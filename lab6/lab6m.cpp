//Jacob Isber
//Lab 6m 


#include <iostream>
#include <limits>


using namespace std;

int main() {

	int sDate, eDate, uDate, sY, sM, sD, eY, eM, eD, uY,uM,uD;

//User enters dates.

		cout << "Enter start date: ";
		cin >> sY >> sM >> sD;
		sDate = (sY*10000) + ((sM*100)+(sD));

		cout << "Enter end date  : ";
		cin >> eY >> eM >> eD;
		eDate = (eY*10000) + ((eM *100) + (eD));

		cout << "Enter date      : ";
		cin >> uY >> uM >> uD; 
		uDate = (uY*10000) +((uM * 100) + (uD));

//Checks to see if user date is in range.

		if ((uDate >= sDate) && (uDate <= eDate)){
			cout << "IN RANGE" << endl;
		}
		
		else 
			cout << "OUT OF RANGE" << endl;
	return 0;
}
