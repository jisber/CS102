#include <iostream>

using namespace std;

int main() {

bool quit = false;
int play_count = 0;


do {
	char input = 'n';
	cout << "Play the game? (y)es/(n)o: ";
	cin >> input;


	if (input == 'n' || input == 'N') {
		cout << "Goodbye!" << endl;
		quit = true;
}

	else if (input == 'y' || input == 'Y') {
		play_count++;
		cout << "You've played " << play_count 
			<< " times!" << endl;
	}
	else { 
		cout << "Do what?" << endl;
	}
} while (!quit);



return 0;
}
