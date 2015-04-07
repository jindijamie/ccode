#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

void wash(int allcard[52]);
int give_out_card(int allcard[52],int card);
void print_card(int card);
void print_cards(int cards[22],int start, int end);
bool judge(float sum);
void final_judge(float computer_sum, float player_sum, int computer_number, int player_number);
bool input_and_check();


int main()
{
	int allcard[52] = {0};
	bool turn = 0;
	bool flag = 0;
	int player_card_number = 0,computer_card_number = 0;
	float player_sum = 0,computer_sum = 0;
	int card;
	
	for(int i=0;i<52;i++) allcard[i]=i+1;
	
	
	while (1)
	{
		cout << "want to play the game?(y/n)";                                  //initialization
		if (input_and_check()) break;
		wash(allcard);
		player_card_number = computer_card_number = player_sum = computer_sum = 0;
		flag=0;
		
		cout<<"player turn" << endl;                                     //deal 2 cards out and print it
		cout<<"player get the cards: " << endl;
		for(int i = 0;i < 2;i++)
		{
			card = allcard[i];
			print_card(card);
			if (card % 13 > 10 || card % 13 == 0) player_sum += 0.5;
			else player_sum += card % 13;
			player_card_number++;
		}
		cout<<endl<<"sum: "<<player_sum<<endl;

		while (1)
		{
			flag = 0;
			cout << "another card?(y/n)";                                //take an additional card or get a 'hit'
			if (input_and_check()) break;
			card = allcard[player_card_number];
			if (card % 13 > 10 || card % 13 == 0) player_sum += 0.5;
			else player_sum += card % 13;
			player_card_number++;
			print_cards(allcard, 0, player_card_number-1);
			cout<<"sum: "<<player_sum<<endl;
			if (judge(player_sum))                                         //check whether the player busts
			{
				cout << "you bust! you lose!" << endl;
				flag = 1;
				break;
			}
				
		}
		
		if (flag) continue;
		while (computer_sum < player_sum)                                 //dealer's turn
		{
			card=allcard[computer_card_number + player_card_number-1];                     //get an additional card if the number doesn't exceed the player's
			print_card(card);
			if (card % 13 > 10 || card % 13 == 0)computer_sum += 0.5;
			else computer_sum += card%13;
			computer_card_number++;
			if (judge(computer_sum)) 
			{
				print_cards(allcard,player_card_number, computer_card_number-1);
				cout << "computer busts!" << "you win" << endl << endl;                          //check whether the dealer busts
				flag = 1;
				break;				
			}
		}
		if (flag) continue;
		print_cards(allcard,player_card_number,computer_card_number-1);
		cout << "sum: " << computer_sum;
		final_judge(computer_sum, player_sum, computer_card_number, player_card_number);
	
	}
 } 
 
bool input_and_check()                                                 //get the input and check it, return'y' or'n'
 {
 	char a[20];
 	
 	while (cin.getline(a,20))
	 {
	 	try
	 	{
	 		if ((a[0]!='y' && a[0]!='n') || (a[1] != '\0' && a[1]!= '\n')) throw 1;
	 		cin.sync();
	 		return (a[0]=='n');
	 	}
	 	catch(int)
	 	{
	 		cout << "Error occured.\a" << endl;
		 }
		 cout << "please input again." << endl;
	 }
	 cout << endl;
 }
 
void wash(int allcard[52]) //get the cards back and shuffle the cards 
{
	int i;
	srand(time(NULL));
 	random_shuffle(allcard,allcard+52);
}
 
void print_card(int card)                                             //print a single card
{
 	switch(card/13)
	 {
	 	case 0:cout << "spade "; break;
	 	case 1:cout << "hearts "; break;
	 	case 2:cout << "diamond "; break;
	 	case 3:cout << "club "; break;
	 	case 4:cout << "club "; break;
	 	default:break;
	  }
	  switch(card % 13)
	 {
	 	case 1:cout << "A"; break;
	 	case 11:cout << "J"; break;
	 	case 12:cout << "Q"; break;
	 	case 0:cout << "K"; break;
	 	default:cout << card % 13; break;
	  }
	  cout << " ";
}
 
void print_cards(int cards[22],int start,int end)                                //print a set of cards
{
 	for(int i = start; i<=end;i++)
 	{
 		print_card(cards[i]);
	 }
	 cout << endl;
}
 
bool judge(float sum)                                            //judge whether anyone busts
{
 	if (sum > 21) return 1; 
	else return 0;	
}
 
void final_judge(float computer_sum, float player_sum, int computer_number, int player_number)
{
 	if (computer_sum>player_sum) cout << " you lose" << endl << endl;                    //judge the final results
 	else if (computer_sum<player_sum) cout << "you win" << endl << endl;
 	else if (computer_number>player_number) cout << "you lose" << endl << endl;
 	else if (computer_number<player_number) cout << "you win" << endl << endl;
 	else cout << "equal";
}
