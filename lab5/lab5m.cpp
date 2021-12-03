//Jacob Isber
//For Lab 5

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() 
{
//(max - min) + 1
	int seed, sum;
	int array[24];

	cout << "Enter a seed: ";

//This is my error check to make sure a int value is inputed by the user.
	
	while (!(cin >> seed)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a seed: ";
	}

	if (seed < 0) {
		cout << "Error, input postive seed value!" << endl;
		return 1;
	}

//This is the random seed of the current time. I got this from the notes.

	else 
		srand(seed);
		
//Allows the array to be filled with 25 random numbers.

	for(int i=0; i <= 25; i++){
			array[i] = ((rand()%21)-10);
		}

//Allows me to add up the numbers in the array.

	for (int k = 0; k <= 25; k++) {
			sum += array[k];
		}
//Outputs the total sum of the array.
	
	cout << "Sum of array = " << sum << "." <<  '\n';




return 0;
}
