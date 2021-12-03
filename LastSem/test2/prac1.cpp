#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {

	double v = 5/3;

	cout << fixed << setprecision(2) <<  v << endl;
return 0;
}








/*void doStuff(const vector<int> &a) {
	for (unsigned int i = 1; i < a.size(); ++i) {
		a.at(i) - a.at(i-1);
	}
}












void func(int & , int );
int main() {
	int x = 3;
	int y = 5;
	func(x, y);
	cout << x << " " << y << endl;
	return 0;
}
void func(int &a, int b) {
	a = b - a;
	b = b + a;
	cout << "This is inside void func: " << a << ' ' << b << endl;
}
*/
