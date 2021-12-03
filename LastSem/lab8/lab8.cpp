#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int cards[52]={0};

int GetRandom(int min, int max) {
	return min+rand()%(max-min+1);
}

int DealCard(int cards[],  int player) {
	int card = GetRandom(0,51);
	cards[card] = player;
	return card;
}

int scoreHand(int cards[], int player []) {
	return ((getCardValue(player[0]), getCardValue(player[1]));
			}
			int getCardValue(int n)
			{
			int = n%13;
			int value = num < 11 ? num : 10;
			if (num == 0) value = 10;
			return value;
			}
			int getCard(int n)
			{
			int num=n%13;
			 int suit=n/13;
			 string value;
			 value = num;
			 if(num==11) value="J";
		     if(num==12) value="Q";
			 if(num==0) value="k";

			 char s;
			 if(suit == 0)
			 {
					s='H';
			 }
			 if(suit == 1)
			 {
				 s = 'C';
			 }
			 if(suit == 3)
			 {
				 s = 'S';
			 }
			 string card=value.srt()+s.str();
			}

int main() {
	


	int num;
	 cout<<"How many players? ";
	 cint>>num;
	 for(int i=1; i<=num; i++)
	 {
	 int player[2]={0};
	 player[0]=dealCard(cards, i);
	 player[1]=dealCard(cards, i);
	 cout<<"Player "<<i<<" has cards"<<getCard(player[0])<<" and "<<getCard(player[1]);
	 cout<<"\t"<<"("<<scoreHand(cards, player);
														      }
}
	return 1;
	}
//string card[]{H,D,S,C}






return 0;
}
