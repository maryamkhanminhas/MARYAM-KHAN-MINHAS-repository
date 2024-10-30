#include<iostream>
using namespace std;
int main()
{
	//5! 5*4*3*2*1=120
int n;
long factorial=1.0;
int i=1;
cout<<"enter the number"<<endl;
cin>>n;
	
	do{


		factorial*=i;
	i++;
	
}
	while(i<=n);
{
cout<<"factorial of"<<n<<"="<<factorial;}
	
	
	
	
	return 0;
}