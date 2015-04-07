#include<iostream>
using namespace std;
int main()
{
	int number,move,a[100],n;
	cin>>number>>move;
	for (int i=0;i<number;i++)
	{
		cin>>a[i];
	}
	n=(0-move+number)%number;
	cout<<a[n];
	for (int j=1;j<number;j++)
	{
		n=(j-move+number)%number;
		cout<<' '<<a[n];
	}
}
