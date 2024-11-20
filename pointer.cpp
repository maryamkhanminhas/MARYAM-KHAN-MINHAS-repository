#include<iostream>
using namespace std;
int main()
{
	int a=10;
	cout<<&a<<endl;
	
	int *ptr;
	
	ptr=&a;
	
	cout<<ptr<<endl;
	cout<<*ptr<<endl;
	*ptr=100;
	cout<<ptr<<endl;
	cout<<*ptr<<endl;
	
	
	return 0;
}