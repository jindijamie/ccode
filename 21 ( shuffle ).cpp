#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

void wash(int allcard[52], int playercard[22], int computercard[22]);
int give_out_card(int allcard[52],int card);
void print_card(int card);
void print_cards(int cards[22]);
bool judge(int sum);
int final_judge(int computer_sum, int player_sum, int computer_number, int player_number);
char input_and_check();


int main()
{
	int allcard[52] = {0};
	bool turn = 0;
	bool flag = 0;
	int playercard[22] = {0};
	int computercard[22]={0};
	int player_card_number = 0,computer_card_number = 0;
	int player_sum = 0,computer_sum = 0;
	int card;
	char whether_card;
	
	for(int i=0;i<52;i++) allcard[i]=i;
	
	
	while (1)
	{
		cout<<"want to play the game?";                                  //initialization
		turn = input_and_check();
		if (turn == 'n') break;
		wash(allcard, playercard, computercard);
		player_card_number = 0;
		computer_card_number = 0;
		player_sum = 0;
		computer_sum = 0;
		
		cout<<"player turn" << endl;                                     //deal 2 cards out and print it
		cout<<"player get the cards: " << endl;
		for(int i = 0;i < 2;i++)
		{
			card = give_out_card(allcard,i);
			playercard[i] = card;
			if (card % 13 > 10 || card % 13 == 0) player_sum += 0.5;
			else player_sum += card % 13;
			player_card_number++;
		}
		print_cards(playercard);
			
		if (judge(player_sum))                                            //check whether the player busts
		{
			cout << " you lose" << endl;
			continue;
		}
			

		while (1)
		{
			flag = 0;
			cout << " another card?(y/n)";                                //take an additional card or get a 'hit'
			whether_card = input_and_check();
			if (whether_card == 'n') break;
			card = give_out_card(allcard, player_card_number);
			print_card;
			playercard[player_card_number] = card;
			if (card % 13 > 10 || card % 13 == 0) player_sum += 0.5;
			else player_sum += card % 13;
			player_card_number++;
			print_cards(playercard);
			if (judge(player_sum))                                         //check whether the player busts
			{
				cout << endl << "you lose" << endl;
				flag = 1;
				break;
			}
				
		}
		
		if (flag) continue;
		while (computer_sum <= player_sum)                                 //dealer's turn
		{
			card=give_out_card(allcard, computer_card_number + player_card_number);
			computercard[computer_card_number] = card;                     //get an additional card if the number doesn't exceed the player's
			if (card%13 > 10 || card % 13 == 0)computer_sum += 0.5;
			else computer_sum += card%13;
			computer_card_number++;
			if (judge(computer_sum)) 
			{
				print_cards(computercard);
				cout << endl << "you win" << endl;                          //check whether the dealer busts
				flag = 1;
				break;				
			}
		}
		if (flag) continue;
		print_cards(computercard);
		switch(final_judge(computer_sum, player_sum, computer_card_number, player_card_number))
		{
			case 0:cout << "equal" << endl;break;
			case 1:cout << "you win" << endl;break;
			case 2:cout << "you lose" << endl;break;                         //print the results
		}
		
		
	}
 } 
 
char input_and_check()                                                 //get the input and check it, return'y' or'n'
 {
 	char a[10];
 	
 	while (cin.getline(a,2))
	 {
	 
 		try
	 	{
	 		if ((a[0]!='y' && a[0]!='n') || (a[1] != '\0' && a[1]!= '\n')) throw 1;
	 		cin.clear();
	 		return a[0];
	 	}
	 	catch(int)
	 	{
	 		cout << "Error occured." << endl;
		 }
		 cout << "please input again." << endl;
	 }
	 cout << endl;
 }
 
 
void wash(int allcard[52], int playercard[22], int computercard[22]) //get the cards back and shuffle the cards 
{
	int i;
	srand(time(NULL));
 	random_shuffle(allcard,allcard+52);
	for (i = 0;i < 22 && playercard[i] != 0; i++) playercard[i] = 0;
	for (i = 0;i < 22 && computercard[i] != 0; i++) computercard[i] = 0;
}
 
int give_out_card(int allcard[52], int i)                            //deal a card
{
	return allcard[i] + 1;
}
 
void print_card(int card)                                             //print a single card
{
 	switch(card/13)
	 {
	 	case 0:cout << " spade "; break;
	 	case 1:cout << " hearts "; break;
	 	case 2:cout << " diamond "; break;
	 	case 3:cout << " club "; break;
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
}
 
void print_cards(int cards[22])                                //print a set of cards
{
 	for(int i = 0; cards[i] != 0;i++)
 	{
 		print_card(cards[i]);
	 }
	 cout << endl;
}
 
bool judge(int sum)                                            //judge whether anyone busts
{
 	if (sum > 21) return 1; 
	else return 0;	
}
 
int final_judge(int computer_sum, int player_sum, int computer_number, int player_number)
{
 	if (computer_sum>player_sum) return 2;                    //judge the final results
 	else if (computer_sum<player_sum) return 1;
 	if (computer_number>player_number) return 2;
 	else if (computer_number<player_number) return 1;
 	return 0;
 	
}
