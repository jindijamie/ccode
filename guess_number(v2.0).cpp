//the game to guess a number
#include <iostream>
#include <ctime>
#include <cstdlib>

//input the numbers and check it
int check_number(char number)
{
	if (number <= '9' && number >= '0') return true;
	else return false;
}

int main()
{
	using namespace std;
	srand (time (NULL));
	bool flag = 1;
	char whether_play;
	char char_guess_a,char_guess_b,char_guess_c;
	int A, B;
	int a, b, c;
	int guess_a, guess_b, guess_c;
	int times_counter = 0, win_counter = 0, lose_counter = 0;
	
	while (flag)
	{
		cout << "Would you like to play the game?(Y/N)©";         //ask the user whether to play the game
		cin >> whether_play;
		while (whether_play != 'Y' && whether_play != 'N') 
		{
			cout << "Please input Y or N."; 
		    cin >> whether_play;
	    }
		if (whether_play == 'Y') flag = 1;
		else flag = 0;
		if (win_counter > 0 || lose_counter > 0)
		{
			cout << "You have played" ;
			if (win_counter+lose_counter > 1) cout << (win_counter+lose_counter) << " rounds";
			else cout<< (win_counter+lose_counter) << " round";
			if (win_counter >  1) cout << " where you have won " << win_counter << " rounds";
			else cout << " where you have won " << win_counter << " round";
			if (lose_counter > 1) cout << " and lose " << lose_counter << " rounds" << endl;
			else cout<<"where you have won" << win_counter << "round" << endl;
		}
		if (!flag) break;
		                              
		a = rand() % 10;                                         //get different random numbers
		b = rand() % 10;
		while (a == b) b = rand() % 10;
		c = rand() % 10;
		while (a == c || b == c ) c = rand() % 10;
		cout << a << b << c;
		
		times_counter = 0;
		while(flag)
		{
			cout << "Please input the number you guess:";
			cin>>char_guess_a>>char_guess_b>>char_guess_c;                       //get the numbers people guess and check
			while (!check_number(char_guess_a) || !check_number(char_guess_b) || !check_number(char_guess_a))
			{				
				cout << "Please input the number you guess:";
			    cin>>char_guess_a>>char_guess_b>>char_guess_c; 
			};
			guess_a = char_guess_a-'0';
			guess_b = char_guess_b-'0';
			guess_c = char_guess_c-'0';
			
			times_counter++;
			A=(a == guess_a) + (b == guess_b) + (c == guess_c);         //compare and get A and B
			B = ((b == guess_a) || (b == guess_c)) + ((a==guess_b) || (a == guess_c)) + ((c == guess_a) || (c == guess_b));
			if (A == 3)                                            //get the result of the game
			{
				cout << "Congratulations,you are right!" << endl;
				win_counter++;
				break;
			}
			else cout << 'A' << A << 'B' << B<<endl;
			
			if (times_counter >= 7)
			{
				cout << "I'm sorry, you haven't figure out the number in time. The answer is" << a << b << c;
				lose_counter++;
				break;
			}
		}
		
	}

	
}
