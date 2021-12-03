//Jacob Isber
//Lab9
//3/28/19
//Revision 2.1

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cstdlib>

using namespace std;

const double mult[4] = {5.2252, 9.4412, 17.1525, 12.152};
const string Month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//Const global arrays

struct Date {
	int month, day, year;
};
//Date struct


struct Ticket {
	string CitNum;
	Date citDate;
	int CSpeed, SLimit;
	char RT;
};
//Ticket struct

int Encode(const Date &d);
//Encode function prototype

class Database {

	private:
		vector<Ticket>TicketVec;

	public:
		void add_ticket(const Ticket &ticket) {
			TicketVec.push_back(ticket);
		

		vector<Ticket>gen_report(Date start, Date end) {
			vector<Ticket>tmptick =  vector<Ticket>();
				for(unsigned int i = 0; i < TicketVec.size(); i++) {
					Ticket currentTicket = TicketVec.at(i);
					if(Encode(start) <= Encode(currentTicket.citDate) && Encode(end) >= Encode (currentTicket.citDate)) { 
						tmptick.push_back(currentTicket);
					}
				}

		return tmptick;
		}
		
};
//Data base class, also did my date checking within the gen_report.

//void Database::add_ticket(const Ticket &ticket);

bool Read(Database &d, istream &in);
//Read fucntion prototype

bool Write(const vector<Ticket> &tickets, ostream &out);
//Write function prototype


int main(int argc, char *argv[]) {
	
	Database d;

	Date Start;
	Date End; 
	char hyp;

	ifstream fin;
	ofstream fout;
	
	istringstream input;
//Declared variables for use in main function/
	
	
	if(argc != 5) {
		cout << "Usage: ./lab9 <input file> <start: year-month-day> <end: year-month-day> <output or '-'>" << endl;
		return 1;
	}
//Error checks the amount of arguments.
	
	fin.open(argv[1]);
//Opens the file

	if(!(fin.is_open())) {
		  cout << "The file '" << argv[1] << "' cannot be read." << endl;
	  }
//Error checks to see if a file was open. got the is_open function from c++ website.

	


	fout.open(argv[4]);
//Opens output file
	
	Read(d, fin);
//Calls read function

	input.str(argv[2]);
	input >> Start.year >> hyp >> Start.month >> hyp >> Start.day;
	input.clear();
//Takes the hyphen outside of the start date.
//Also got help with this section from a TA on tuesday.


	input.str(argv[3]);
	input >> End.year >> hyp >> End.month >> End.day;
	input.clear();
//Take the hyphen outside of the end date.


	Write(d.gen_report(Start, End), fout);
//Open and executes the Write function.
	


return 0;
}
bool Read(Database &d, istream &in) {
		
	Ticket newTicket;
	
	while(in >> newTicket.CitNum >> newTicket.citDate.month >> newTicket.citDate.day >> newTicket.citDate.year >> newTicket.CSpeed >> newTicket.SLimit >> newTicket.RT) {
	
		if(newTicket.citDate.year <= 99) {
			newTicket.citDate.year += 2000;
		}
		//adds 2000 to any date lese than or equal to 99 to make it a year.

		d.add_ticket(newTicket);

	} 
//Read function that reads in the ticket info

return true;
}


  bool Write(const vector<Ticket> &tickets, ostream &out) {

	

	double fine = 0;
	for(unsigned int i; i < tickets.size(); i++) {
		switch(tickets[i].RT) {
			case 'i':
			case 'I':
				fine = mult[0] * (tickets[i].CSpeed - tickets[i].SLimit);
				break;
			case 'h':
			case 'H':
				fine = mult[1] * (tickets[i].CSpeed - tickets[i].SLimit);
				break;
			case 'r':
			case 'R':
				fine = mult[2] * (tickets[i].CSpeed - tickets[i].SLimit);
				break;
			default:
				fine = mult[3] * (tickets[i].CSpeed - tickets[i].SLimit);
				break;
				//Does the math and adds the fine due to the road type.

			}
		if(fine <= 0) {
			fine = 0.00;
		}


		out << setw(2) << setfill('0') << tickets[i].citDate.day << setfill(' ') << "-" << Month[(tickets[i].citDate.month) - 1] << "-" << tickets[i].citDate.year << " " << left<< setw(10) << tickets[i].CitNum << " $" << right << fixed << setprecision(2) << fine << endl;

	cout << setw(2) << setfill('0') << tickets[i].citDate.day << setfill(' ') << "-" << Month[(tickets[i].citDate.month) - 1] << "-" << tickets[i].citDate.year << " " << left<< setw(10) << tickets[i].CitNum << " $" << right << fixed << setprecision(2) << fine << endl;


	}
//This is the write function checks code inside the ticket and outputs in correct format to the output file.
	
return true;
}



int Encode(const Date &d) {

 return  d.year * 10000 + d.month * 100 + d.day;
}
//Converts date to one big number.


/*void Database::add_ticket(const Ticket &ticket) {
	TicketVec.push_back(ticket);
		}

		vector<Ticket>gen_report(Date start, Date end) {
			vector<Ticket>tmptick =  vector<Ticket>();
				for(unsigned int i = 0; i < TicketVec.size(); i++) {
					Ticket currentTicket = TicketVec.at(i);
					if(Encode(start) <= Encode(currentTicket.citDate) && Encode(end) >= Encode (currentTicket.citDate)) { 
						tmptick.push_back(currentTicket);
					}
				}

		return tmptick;
		}


*/


