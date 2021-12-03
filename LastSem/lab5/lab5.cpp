#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Jacob Isber Cosc102 Lab5 
int main() {

int arr[21], j, tempTotal;
vector<string>playerName;
vector<int>totalScore;
string names;
//Starts the program by asking for the first player name also allows if player name == done to just quit the program.
 	cout << "Enter player's name (done for no more players): ";
	cin >> names;
	if (names == "done"){
		cout << "No players were entered. " <<  endl;
		return 2;
	}
//Starts the do while loop to allow the scorring to be stored in the array and allowing names to be pushed into the vectors.
do
{
	playerName.push_back(names);

	for(int k = 0; k < 21; k++){
	arr[k] = 0;
	}

	tempTotal = 0;
	j = 0;
	
	for (int i = 0; i < 9; i++) {
	cout << "Enter score for frame " << i+1 << ", roll 1: ";
	cin >> arr[j];
	if (arr[j] >= 10) 
		arr[j] += 20;
	j++;
	

	if ( arr[j - 1] < 10) {
		j++;
		cout << "Enter score for frame " << i+1 << ", roll 2: ";
		cin >> arr[j];
	}
	

	} 
	
	cout << "Enter score for frame 10, roll 1: ";
	cin >> arr[j];
	j++;

	cout << "Enter score for frame 10, roll 2: ";
	cin >> arr[j];
	j++;
	
	cout << "Enter score for frame 10, roll 3: ";
	cin >> arr[j];
	j++;
	
	for (int i = 0; i < 21 ; i++) {
	tempTotal += arr[i];
    }
//Allows scores to be pushed back into the totalScore vector.
	totalScore.push_back(tempTotal);
	
	cout << "Enter player's name (done for no more players): ";
	cin >> names;
	} while(names != "done");
//Allows scores to be calculated and output after the do-wile loop is compelete
	for (int l = 0; l < playerName.size(); l++)
	cout << playerName[l] << " scored " << totalScore[l] << endl;

	int max = totalScore[0], min = totalScore[0], hi = 0, low = 0;
	for(int l = 0; l < totalScore.size(); l++){
		if(totalScore[l] > max){
			max = totalScore[l];
			hi = l;
		}
		if(totalScore[l] < min){
			min = totalScore[l];
			low = l;
		}
	}
//Allows the best and worst player to have the worst/best statement next to their name
	cout << playerName[low] << " did the worst by scoring " << totalScore[low] << endl;
	cout << playerName[hi] << " did the best by scoring " << totalScore[hi] << endl;


return 0;
}
