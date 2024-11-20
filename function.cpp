#include<iostream>
using namespace std;
int passByvalue(int num)
{num=num+10;

return num;
}
void mul(int num)
{int mul=num*10;
cout<<"multiply number"<<mul<<endl;
}

void sub( int num)
{num=num-10;

cout<<sub<<num<<endl;

}


int main()
{int number=10;

cout<<"before calling a number"<<number<<endl;
int k=passByvalue(number);

cout<<"inside function"<<k<<endl;
cout<<"after call function"<<number<<endl;
mul(number);

sub(number);

return 0;
}