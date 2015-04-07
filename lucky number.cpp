#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,f,i,na[10]={0},nb[10]={0};
	bool flag=1;
	cin>>a;
	b=a*2;
	f=b;
	while (a>0 &&b>0)
	{
		c=a%10;
		c=c/10;
		na[c]++;
		b=b%10;
		b=b/10;
		nb[d]++;
	}
	if (a*b>0) cout<<"No";
	else
	{
		for (i=0;i<=9;i++)
		{
			if (na[i]==nb[i]) 
			{
				flag=0;
				break;
			}
		}
	}
	if (flag)cout<<"Yes";
	else cout<<"No";
	cout<<endl<<f;
}
