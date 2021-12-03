//Jacob Isber
//Lab 11
//I did have to go to office hours on monday/tuesday for the resize function.
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

class doublevector {
     static constexpr double DOUBLE_DEFAULT_VALUE = -5.55;
     double *mValues;
     int mNumValues;
public:
     doublevector();
     ~doublevector();
     void resize(int new_size, double initial_value=DOUBLE_DEFAULT_VALUE);
     void push_back(double value);
     double &at(int index);
     const double &at(int index) const;
     unsigned long size() const;
};
void print_all(const doublevector &v)
{
     if (v.size() == 0) {
           cout << "Vector is empty.\n";
     }
     else {
          unsigned long i;
          for (i = 0;i < v.size();i++) {
                cout << "[" << setfill('0') << right << setw(3) << i
                     << "] = " << fixed << setprecision(4) << v.at(i)
                     << '\n';
          }
     }
}
int main()
{
      doublevector v;
      do {
           string command;
           cout << "Enter a command ('quit' to quit): ";
           if (!(cin >> command) || command == "quit") {
                break;
           }
           else if (command == "push_back") {
                double value;
                cin >> value;
                v.push_back(value);
		cout << "Pushed back "
		     << fixed << setprecision(4)
		     << value << '\n';
           }
           else if (command == "resize") {
                string line;
                int new_size;
                double initial;
                cin >> new_size;
                getline(cin, line);
                istringstream sin(line);

                if (sin >> initial)
                     v.resize(new_size, initial);
                else
                     v.resize(new_size);
           }
           else if (command == "size") {
                cout << v.size() << '\n';
           }
           else if (command == "print") {
                print_all(v);
           }
           else if (command == "get") {
                int index;
                cin >> index;
                try {
                     cout << "Value at " << index << " = "
		          << setprecision(4) << fixed
                          << v.at(index) << '\n';;
                }
                catch(out_of_range &err) {
                     cout << err.what() << '\n';
                }
           }
           else if (command == "set") {
		   double d;
		   int index;
                   cin >> index >> d;
                   try {
			v.at(index) = d;
                        cout << "SET: " << index << " = "
			     << setprecision(4) << fixed
                             << v.at(index) << '\n';;
                   }
                   catch(out_of_range &err) {
                        cout << err.what() << '\n';
                   }
           }
           else if (command == "clear") {
                v.resize(0);
           }
           else {
                cout << "Invalid command '" << command << "'\n";
           }
      } while(true);
      cout << endl;
      return 0;
}
	
doublevector::doublevector() {
	mNumValues = 0;
	mValues = new double;
	mValues = nullptr;
}

//This is a constructer sets default values to 0, and nullptr.

doublevector::~doublevector() {
	delete mValues;
}
//This is the deconstructer for the doublvector.

double & doublevector:: at(int index) {

	if(index >= mNumValues) {
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}

return mValues[index];

}
//This is the at function that returnes the pointer at a certian index.

const double & doublevector:: at(int index) const {
	
	if(index >= mNumValues) {
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	
return mValues[index];
}
//This is the at function that returnes the pointer at a certain index.

unsigned long doublevector::size() const {
	
	return (unsigned long) mNumValues;
}

//This is the size function that returns mNumValues as an unsigned long.

void doublevector::resize(int new_size, double initial_value) {

	if(new_size < 0) {
		cout << "Can not resize to a negative size, try agian." << endl;
		return;
	}
//Checks if resize is a negative value.

	else if((unsigned) new_size > size()) {
		double *temp = new double[new_size];
		for(unsigned long i = 0; i < size(); i++) {
			temp[i] = mValues[i];
		}
		delete [] mValues;

		for(int i = size(); i < new_size; i++) {
			temp[i] = initial_value;
		}
		mNumValues = new_size;
		mValues = temp;
	}
//this is the resize function if the new_size is greater than the actual size.
	else if((unsigned)  new_size < size()) {
		double *temp = new double[new_size];
		for(int i = 0; i < new_size; i++) {
			temp[i] = mValues[i];
		}
		delete[] mValues;

		mNumValues = new_size;
		mValues = temp;
	}
//This is the resize function if the new_size is less that the actaul size.

	else if(new_size == 0 ) {
		delete[] mValues;
		mValues = nullptr;
	}
//If the new size is set to 0 reset everything.


}
	
//This is the resize function. I did have to go to TA office hours to get help with this. I was there on monday/tuesday. 

	void doublevector::push_back(double value) {
	resize(size() + 1, value);
}

//This is my push back function. 






/*This is my original attempt at the resize function before I went to office hours.. It almost works properlly I just wanted to keep it in my code because I am going to work on it later and try to fix it.*/

	/*	if((new_size <  0)||(new_size == mNumValues)) {
		return;
	}
	else if(new_size == 0 ) {
		delete[] mValues;
		mValues = nullptr;
	}
	else if(new_size < mNumValues){
		double *temp = new double;
		for(int i = 0; i < new_size; i++) {
			temp[i] = at(i); 
		}
		delete mValues;
		mValues = temp;
		mNumValues = new_size;
	}
	else if(new_size > mNumValues){
		double *temp = new double;
		for(int i = 0; i < new_size; i++) {
			if(i < mNumValues) {
				temp[i] = at(i);
			}
			else {
				temp[i] = initial_value;
			}
		}
		delete mValues;
		mValues = new double;
		mValues = temp;
		mNumValues = new_size;
	}
	else 
		return;
}
*/
