#include <iostream>
#include <limits>

using namespace std;

int main()
{

int x;
cout << "Input an integar: ";
while (!(cin >> x)) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cout << "Invalid input, enter an integer: ";
}

cout << "You input " << x << '\n';

return 0;
}




