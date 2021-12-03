#include <iostream>
using namespace std;

int main() {

char input = 'Y';
int value = 1;
do{

	int value = 1;

	for(int i = 1; i  <= 10; ++i ++value ){
		cout << value << " ";
	
	}
	
		cout << "\nSee the next 10 numbers? (y)es/(n)o ";
		cin >> input;

} while (input == 'y' || input == 'Y');


return 0;

}
