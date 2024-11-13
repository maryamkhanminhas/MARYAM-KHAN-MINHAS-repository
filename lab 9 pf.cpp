#include<iostream>
using namespace std;
int main()
{int sum;
int rows;
int average;
int col;//col=coulmn	
cout<<"enter the rows"<<endl;
cin>>rows;
cout<<"enter the column"<<endl;
cin>>col;

	
	int arr[rows][col];
	cout<<"enter the elements of array"<<endl;
	for(int i=0;i<rows;i++)
	{for(int j=0;j<col;j++)
	{
		cout<<"elements of ["<<i<<"]["<<j<<"]"<<endl;
		cin>>arr[i][j];
		sum+=arr[i][j];
		average=sum/arr[i][j];
	}
	
	}
	cout<<"the 2D array is"<<endl;
	for(int i=0;i<rows;i++)
	{for(int j=0;j<col;j++)
	{cout<<arr[i][j]<<" ";
	}
	cout<<endl;
	cout<<"sum is= "<<sum<<endl;
	cout<<"average is ="<<average<<endl;
	}
	
	
	return 0;
}