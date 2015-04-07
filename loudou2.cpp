#include<iostream>
using namespace std;
int main()
{
	int N,i,j,k,l;
	cin>>N;
	N++;
	i=1;
	do{
		N-=2*i;
		i+=2;
	}
	while (N>=0);
	

	cout<<i<<endl;
	for (j=i;j>=1;j-=2)
	{
		for(k=1;k<=i-j;k+=2)
		{
			cout<<' ';
			
		}
		for (l=1;l<=j;l++)
		{
			cout<<'*';
		}
		cout<<endl;
	}
	for (j=3;j<=i;j+=2)
	{
		for(k=1;k<=i-j;k+=2)
		{
			cout<<' ';
			
		}
		for (l=1;l<=j;l++)
		{
			cout<<'*';
		}
		cout<<endl;
	}
	cout<<N+2*i;

}
