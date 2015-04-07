//文件名：作业一__游戏
//猜数字游戏
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
int main()
{ 	int num1,num2,num3,input1,input2,input3,numA,numB,i,j,k;
	char answer;
	
	srand(time(NULL));
	j=0;
	while (true){
		cout<<"需要玩游戏吗（Y/N）？";
		cin>>answer ;
		if (answer=='N') break;
		
		if (answer=='Y'){
			num1=rand()*10/(RAND_MAX+1);
			num2=rand()*10/(RAND_MAX+1);
			num3=rand()*10/(RAND_MAX+1);
			cout<<num1; 
			
			cout<<"请输入你猜测的数字:"; 
			cin>>input1;
			cin>>input2;
			cin>>input3;
			
			numA=0;
			numB=0;
			cout<<input1;
			
			for (i=1;i<=7;++i){
				if ((num1==input1)&&(num2==input2)&&(num1==input1))
					{
						cout<<"恭喜，你猜对了";
						++k;
						break;
				    }
				numA=0;
				numB=0;
				if(num1==input1) ++numA;
				if(num2==input2) ++numA;
				if(num3==input3) ++numA;
				if(num1==input2) ++numB;
				if(num1==input3) ++numB;
				if(num2==input1) ++numB;
				if(num2==input3) ++numB;
				if(num3==input1) ++numB;
				if(num3==input2) ++numB;
					
				cout<<numA<<'A'<<numB<<'B'<<endl;
							
				cout<<"请输入你猜测的数字:"; 
				cin>>input1;
				cin>>input2;
				cin>>input3;
				if(i==7)
					cout<<"很遗憾，你没有在规定次数内猜对。答案是"<<num1<<num2<<num3<<endl;
			
			}
		}
		
	 	++j;
	}
	cout<<"你一共玩了"<<j<<"局，赢了"<<k<<"局，输了"<<j-k<<"局";
	return 0;
}
				
				
			
			 
			
		
			
	
	

