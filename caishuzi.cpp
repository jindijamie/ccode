# ccode
//the game to guess a number
#include <iostream>
#include <ctime>
#include <cstdlib>

//input the numbers and check it
int input_guess_number()
{
	using namespace std;
	char number;
	cin >> number;
	while (number < '0' || number > '9')
	{
		cout << "ÇëÊäÈëµ¥¸öÊý×Ö" << endl;
		cin >> number; 
    }
    return number-'0';
}

int main()
{
	using namespace std;
	srand (time (NULL));
	bool flag = 1;
	char whether_play;
	int A, B;
	int a, b, c;
	int guess_a, guess_b, guess_c;
	int times_counter = 0, win_counter = 0, lose_counter = 0;
	while (flag)
	{
		cout << "ÐèÒªÍæÓÎÏ·Âð£¨Y/N£©"; 
		cin >> whether_play;
		while (whether_play != 'Y' && whether_play != 'N') 
		{
			cout << "ÇëÊäY»òÕßN"; 
		    cin >> whether_play;
	    }
		if (whether_play == 'Y') flag = 1;
		else flag = 0;
		if (win_counter > 0 || lose_counter > 0)
		{
			cout << "ÄãÒ»¹²ÍæÁË" << (win_counter+lose_counter) << "¾Ö£¬Ó®ÁË" << win_counter << "¾Ö£¬ÊäÁË" << lose_counter << "¾Ö"<<endl;
		}
		if (!flag) break;
		a = rand() % 10;
		b = rand() % 10;
		while (a == b) b = rand() % 10;
		c = rand() % 10;
		while (a == c || b == c ) c = rand() % 10;
		cout << a << b << c;
		times_counter = 0;
		while(flag)
		{
			cout << "ÇëÊäÈëÄã²Â²âµÄÊý×Ö:";
			guess_a = input_guess_number();
			guess_b = input_guess_number();
			guess_c = input_guess_number();
			while (a > 9 || a < 0 || b > 9 || b < 0 || c > 9 || c < 0 ) cin >> guess_a >> guess_b >> guess_c;
			times_counter++;
			A = (a == guess_a) + (b == guess_b) + ( c==guess_c );
			B = ((b == guess_a) || (b == guess_c)) + ((a==guess_b) || (a == guess_c)) + ((c == guess_a) || (c == guess_b));
			if (A == 3) 
			{
				cout << "¹§Ï²£¬Äã²Â¶ÔÁË" << endl;
				win_counter++;
				break;
			}
			else cout << 'A' << A << 'B' << B;
			if (times_counter >= 7)
			{
				cout << "ºÜÒÅº¶£¬ÄãÃ»ÓÐÔÚ¹æ¶¨´ÎÊýÄÚ²Â¶Ô¡£´ð°¸ÊÇ" << a << b << c;
				lose_counter++;
				break;
			}
		}
		
	}

	
}
