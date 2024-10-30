#include<iostream>
using namespace std;
int main()
{
	//5! 5*4*3*2*1=120
int n;
long factorial=1.0;

cout<<"enter the number"<<endl;
cin>>n;
	if(n<0)
	cout<<"ERROR! it is a negative number"<<endl;
	else{
	
	for(int i=1; i<=n; i++)
	{
		factorial*=i;
	}
	cout<<"factorial of"<<n<<"="<<factorial;
}
	
	
	
	
	
	
	return 0;
}