#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

void wash(bool allcard[4][13], int playercard[22][2], int computercard[22][2]);
int give_out_card(bool allcard[4][13],int card[2]);
void print_card(int card[2]);
void print_cards(int cards[22][2]);
bool judge(int sum);
int final_judge(int computer_sum, int player_sum, int computer_number, int player_number);
char input_and_check();


int main()
{
	bool allcard[4][13] = {0};
	bool turn = 0;
	bool flag = 0;
	int playercard[22][2] = {0};
	int computercard[22][2];
	int player_card_number = 0,computer_card_number = 0;
	int player_sum = 0,computer_sum = 0;
	int card[2];
	char whether_card;
	while (1)
	{
		flag=0;                                                  //initialization
		cout<<"want to play the game?";
		turn = input_and_check();
		if (turn == 'n') break;
		wash(allcard, playercard, computercard);
		player_card_number = 0;
		computer_card_number = 0;
		player_sum = 0;
		computer_sum = 0;
		
		cout<<"player turn" << endl;                            //deal 2 cards out and print it
		cout<<"player get the cards: " << endl;
		for(int i=0;i<2;i++)
		{
			give_out_card(allcard, card);
			playercard[i][0] = card[0];
			playercard[i][1] = card[1];
			if (card[1]>10)player_sum+=0.5;
			else player_sum+=card[1];
			player_card_number++;
		}
		print_cards(playercard);
			
		if (judge(player_sum))                                   //check whether the player busts
		{
			cout << " you lose" << endl;
			continue;
		}
			

		while (1)
		{
			cout << " another card?(y/n)";                       //take an additional card or get a 'hit'
			whether_card = input_and_check();
			if (whether_card == 'n') break;
			give_out_card(allcard,card);
			print_card;
			playercard[player_card_number][0] = card[0];
			playercard[player_card_number][1] = card[1];
			if (card[1] > 10)player_sum += 0.5;
			else player_sum += card[1];
			player_card_number++;
			print_cards(playercard);                              //check whether the player busts
			if (judge(player_sum)) 
			{
				cout << endl << "you lose" << endl;
				flag = 1;
				break;
			}
				
		}
		
		if (flag) continue;
		while (computer_sum <= player_sum)                         //dealer's turn
		{
			give_out_card(allcard,card);                           //get an additional card if the number doesn't exceed the player's
			computercard[computer_card_number][0] = card[0];
			computercard[computer_card_number][1] = card[1];
			if (card[1]>10)computer_sum += 0.5;
			else computer_sum += card[1];
			computer_card_number++;
			if (judge(computer_sum)) 
			{
				print_cards(computercard);
				cout << endl << "you win" << endl;                 //check whether the dealer busts
				flag = 1;
				break;				
			}
		}
		if (flag) continue;
		print_cards(computercard);
		switch(final_judge(computer_sum, player_sum, computer_card_number, player_card_number))
		{
			case 0:cout << "equal" << endl;break;                   //check the final result
			case 1:cout << "you win" << endl;break;
			case 2:cout << "you lose" << endl;break;
		}
		
		
	}
 } 
 
char input_and_check()                                          //get the input and check it, return'y' or'n'
 {
 	char a[10];
 	
 	while (cin.getline(a,2))
	 {
	 
 		try
	 	{
	 		if ((a[0]!='y' && a[0]!='n')|| (a[1]!='\0'&&a[1]!='\n')) throw 1;
	 		cin.clear();
	 		return a[0];
	 	}
	 	catch(int)
	 	{
	 		cout<<"Error occured."<<endl;
		 }
		 cout<<"please input again."<<endl;
	 }
	 cout<<endl;
 }
 
 
void wash(bool allcard[4][13], int playercard[22][2], int computercard[22][2]) //recover the cards to the initial condition
{
	int i,j;
 	for (i = 0; i < 4; i++)
 	{
 		for (j = 0; j < 13; j++) allcard[i][j] = 0;
	}
	for (i = 0;i < 21 && playercard[i] != 0; i++) playercard[i][1]=playercard[i][0]=0;
	for (i = 0;i < 21 && computercard[i]!=0; i++) computercard[i][1]=computercard[i][0]=0;
}
 
int give_out_card(bool allcard[4][13],int card[2])                             //deal a card
{
	int type, number;
 	srand(time(NULL));
 	do
	 {
 		type=rand()%4;
 		number=rand()%13;
 	 }
 	 while (allcard[type][number]);
 	 allcard[type][number]=1;
 	 card[0]=type+1;
 	 card[1]=number+1;
}
 
void print_card(int card[2])                                                    //print a single card
{
 	switch(card[0])
	 {
	 	case 1:cout<<" spade ";break;
	 	case 2:cout<<" hearts ";break;
	 	case 3:cout<<" diamond ";break;
	 	case 4:cout<<" club ";break;
	 	default:break;
	  }
	  switch(card[1])
	 {
	 	case 1:cout<<"A";break;
	 	case 11:cout<<"J";break;
	 	case 12:cout<<"Q";break;
	 	case 13:cout<<"K";break;
	 	default:cout<<card[1];break;
	  }
}
 
void print_cards(int cards[22][2])                             //print a set of cards
{
 	for(int i=0;cards[i][1]!=0;i++)
 	{
 		print_card(cards[i]);
	 }
}
 
bool judge(int sum)                                            //judge whether anyone busts
{
 	if (sum>21) return 1; 
	else return 0;	
}
 
int final_judge(int computer_sum, int player_sum, int computer_number, int player_number) //judge the final results
{
 	if (computer_sum>player_sum) return 2;
 	else if (computer_sum<player_sum) return 1;
 	if (computer_number>player_number) return 2;
 	else if (computer_number<player_number) return 1;
 	return 0;
 	
}
