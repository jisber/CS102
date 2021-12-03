#include <iostream>

using namespace std;

int main() {

int i = 2;
do { 
	if ((i %2 ) == 0)
		continue;
	cout << 'A';
} while (++i < 10);


return 0;
}
