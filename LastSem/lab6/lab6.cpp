#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Jacob Isber, Cosc102, lab11.cpp

//Initializing global variables because these variables are constant.

const string Month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const double mult[4] = {5.2252, 9.4412, 17.1525, 12.152};


/*I had no clue how to do this lab and or had any clue on what was going on. This was the first lab that I didn't have clue how to do and was simply stuck. Very sorry the persongrading this terrible attempt at a lab. I just had no clue what was going on and the help I tried to get was simply not clicking for me. I basically just took the skeleton of 
my lab 6 and just tried to add on to it.
*/

/*
 * These are the data classes and function attempts I tried to make but I had no clue how to use the variables in the code. 
struct Date {
	int Dmonth;
	int Dday;
	int Dyear;
};

struct Ticket {
	string CitNum;
	int ClockSpeed;
	int SpeedLimit;
	char ToR;
	

};

class Database {
	private: 
		std::vector<double>Tticket();

	public:
		void add_ticket(Ticket&);
		
};

bool Read(Database &d, istream &in) {
}

bool Write(const vector<Ticket> &tickets, ostream &out){

}

int Encode(const Date &d){

}
		

*/



int main() {

//These are the declared variable names.	
int sDay, sMonth, sYear, eDay, eMonth, eYear, cMonth, cDay, cYear, cSpeed, cLimit;
char Type;
bool m = false, d = false;
string fileIn, fileOut, citNum;
ifstream fin;
ofstream fout;

double Fine;

//Asking for the input file.
cout << "Enter a ticket file: ";
	cin >> fileIn;


fin.open(fileIn);

if(!fin){
	cout << "unable to to open " << fileIn << "." << endl;
	return -1;
}

cout << "Enter a report file: ";
	cin >> fileOut;
cout << "Enter report start date (mm dd yyyy): ";
	cin >> sMonth >> sDay >> sYear;
cout << "Enter report end date (mm dd yyyy): ";
	cin >> eMonth >> eDay >> eYear;

//Initializing the 21st century	
	if ((sYear >= 1) && (sYear <= 99))
		sYear = 2000 + sYear;
	if ((eYear >= 1) && (sYear <= 99))
		eYear = 2000 + eYear;

	fout.open(fileOut);
//Starts the while loop with inputing these values. 
while (fin >> citNum >> cMonth >> cDay >> cYear >> cSpeed >> cLimit >> Type) {

//Allows the bool variables to be reinitated back to false at every loop.	
	m = false;
	d = false;

//Allows the pointer to check the .txt file for correct and incorrect range.	
	if ((cYear >=1) && (cYear <= 99)) {
		cYear = 2000 + cYear;
	}
	if ((cYear >= sYear) && (cYear <= eYear)) {
		if (cYear == sYear) {
			m = true;
			if (!(cMonth >= sMonth)) {
				m = false;
			}
		}
		if (cYear == eYear){
			m = true;
			if (!(cMonth <= eMonth)){
				m = false;
			}
		}
		if (cYear == sYear){
			d = true;
			if (cMonth == eMonth){
				if (!(cDay >= sDay)){

					d = false;
				}
			}
		}
		if (cYear == eYear){
			d = true;
			if (cMonth == eMonth) {
				if (!(cDay <= eDay)){
					d = false;
				}
			}
		}
	}
//Does the math for the multiplyer for the road type
	if ((m == true) && (d == true)) {
		switch (Type) {
			case 'i':
			case 'I':
				Fine = mult[0]*(cSpeed - cLimit);
				break;
			case 'h':
			case 'H':
				Fine = mult[1]*(cSpeed - cLimit);
				break;
			case 'r':
			case 'R':
				Fine = mult[2]*(cSpeed - cLimit);
				break;
			case 'p':
			case 'P':
				Fine = mult[3]*(cSpeed - cLimit);
				break;
			}

		if (Fine <= 0) {
			Fine = 0.00;
		}

			
	//Just outputs the values to the output file.
		 if((cDay >= 1) && (cDay <= 9)) {
			 fout <<setw(2) << setfill('0') << cDay << "-" << setfill(' ');
		 }
		 else
			 fout << cDay << "-";
		 fout<< Month[cMonth -1] << "-" << cYear << " ";
		fout << setw(10) << left << citNum;
	 	fout << "$";
	 	fout << setw(9) << right << fixed << setprecision(2) << Fine << endl;
	}
	}
//	fout.close();
return 0;
}








