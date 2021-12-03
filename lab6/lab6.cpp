//Jacob Isber
//2/13/2019
//Lab 6
//Cosc102
//Revision 1.2
#include <iostream> 
#include <limits> 
#include <vector> 
#include <cstdlib>
#include <fstream> 
#include <iomanip> 
using namespace std; 

//These are global constants, to store my mulitplyiers and month names
const double mult[4] = {5.2252, 9.4412, 17.1525, 12.152}; 
const string Month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {

//All declared variables within int main
int sY, sM, sD, eY, eM, eD, sDate, eDate, cDate, cM, cD, cY, cSpeed, cLimit;
char cRoad;
string fileIn, fileOut, cNum; 
ifstream fin;
ofstream fout;
double fine;

//Enter and opens ticket file
	cout << "Enter a ticket file: ";
	cin >> fileIn;
	
	fin.open(fileIn);

//Error checks to make sure file exsists
	if(!(fin)) {
		cout << "Unable to open " << fileIn << "." << endl;
		return 2;
	}

//These next lines take in the output file and start and end dates
	cout << "Enter report file: ";
	cin >> fileOut;

	cout << "Enter report Start date (mm dd yyyy): ";
	cin >> sM >> sD >> sY;
	sDate = sY * 10000 + sM * 100 + sD;
	
	cout << "Enter report end date   (mm dd yyyy): "; 
	cin >> eM >> eD >> eY;
	eDate = eM * 100 + eD + (eY * 10000);

	if ((sY >= 1) && (sY <= 99)){
		sY += 2000;
	}
	if ((eY >= 1) && (eY <= 99)) {
		eY += 2000;
	}

//Opens up the output file.
	fout.open(fileOut);

//Reads in the information from the input file.
	while(fin >> cNum >> cM >> cD >> cY >> cSpeed >> cLimit >> cRoad) {

		if (cY <= 99) {
			cY += 2000;
		}

//Changes cDate to a long number.

		cDate = cY * 10000 + cM * 100 + cD;

//This is to check the range of date and determines the multiplyer.
		if ((cDate >= sDate) && (cDate <= eDate)) {
			switch (cRoad) {
				case 'i':
				case 'I':
				 fine = mult[0] * (cSpeed - cLimit);
				 break;
				case 'h':
				case 'H':
				 fine = mult[1] * (cSpeed - cLimit);
				 break;
				case 'R':
				case 'r':
				 fine = mult[2] * (cSpeed - cLimit);
				 break;
				default:
				 fine = mult[3] * (cSpeed - cLimit);
				 break;
			}
	
			if(fine <= 0) {
				fine = 0.00;
			}

//Inputs all the information correctly into the output file.
			if((cD >= 1) && (cD <= 9)) {
				fout << setw(2) << setfill('0') << cD << "-" << setfill(' ');
				fout << Month[cM - 1] << "-" << cY << " ";
				fout << setw(10) << left << cNum;
				fout << "$";
				fout << setw(9) << right << fixed << setprecision(2) << fine << endl;
			}
				else { 
					fout << cD << "-";
					fout << Month[cM - 1] << "-" << cY << " ";
					fout << setw(10) << left << cNum;
					fout << "$";
					fout << setw(9) << right << fixed << setprecision(2) << fine << endl;
				}
		}
	}	
	
//closes the input file.
fin.close();

	return 0;
}


