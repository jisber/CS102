 1 //Jacob Isber
  2 //Lab7
  3 //3/05/2019
  4 #include<iostream>
  5 #include<string>
  6 #include<cstdlib>
  7 #include<iomanip>
  8 
  9 using namespace std;
 10 
 11 //Function Prototypes;
 12 int GetRandom(int, int);
 13 string DealCard(int [], int);
 14 int ScoreHand(int [], int);
 15 
 16 //Declared arrays.
 17 const string cardArray[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
 18 const string suitArray[] = { "H", "D", "S", "C"};
 19 int deckArray[52] = {0};
 20 
 21 int main() {
 22 
 23 //Declared variables within the int main function. 
 24     string cardOne, cardTwo;
 25     int Totalscore;
 26     int numOfplayers;
 27 
 28 //Inputs and error checks the number of players.
 29     cout << "How many players? ";
 30     cin >> numOfplayers;
 31 
 32     if(numOfplayers > 26) {
 33         cout << "Too many players." << endl;
 34         return 1;
 35     }
 36 
 37 //Random Number Seed
 38     srand(time(NULL));
 39 
 40 //Calls all three functions and loops through and assigns values.
 41     for(int i = 1; i <= numOfplayers; i++){
 42         cardOne = DealCard(deckArray, i);
 43         cardTwo = DealCard(deckArray, i);
 44         Totalscore = ScoreHand(deckArray, i);
 45 
 46 //Outputs cards and score.
 47         cout << "Player " << setw(2) << left << i  << " has cards: " << setw(1) << cardOne;
 48         cout << " " << cardTwo;
 49         cout << setw(15) << right << setw(15) << " (" << right << Totalscore << right  <<  ")" << endl;
 50     }
 51 
 52     return 0;
 53 }
 54 
 55 //GetRandom fucntion to randomize numebes.
 56 int GetRandom(int min, int max) {
 57 
 58     return (rand() % max - min);
 59 }
 60 
 61 //DealCard function to deal cards to players.
 62 string DealCard(int deckArray[], int Player) {
 63     bool randomCard = true;
 64     int RN;
 65     string cardType;
 66 
 67     while (randomCard) {
 68         RN = GetRandom(0,52);
 69         if(deckArray[RN] == 0) {
 70             cardType = (cardArray[RN % 13] + suitArray[RN / 13]);
 71             deckArray[RN] = Player;
 72             randomCard = false;
 73         }
 74     }
 75     return cardType;
 76 }
 77 
 78 //ScoreHand function allows scoring to occure.
 79 int ScoreHand(int deckArray[], int Player) {
 80     int tempValue;
 81     int Totalscore = 0;
 82     for(int i = 0; i < 52; i++) {
 83         if(deckArray[i] == Player) {
 84             tempValue = (i%13) + 1;
 85             if (tempValue >= 10) {
 86                 tempValue = 10;
 87             }
 88             Totalscore += tempValue;
 89         }
 90         }
 91         return Totalscore;
 92     }
 93 
~                      
