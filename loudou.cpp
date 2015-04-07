#include<iostream>
using namespace std;
int main()
{
	int N,line,i,sum,j,k,l;
	cin>>N;
	for (i=3,sum=1;N>=1;i+=2)
	{
		N-=2*i;
		cout<<N<<' '<<i<<endl;
	}
	i-=4;
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
