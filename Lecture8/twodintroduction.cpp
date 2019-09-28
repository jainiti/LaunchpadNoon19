#include<iostream>
using namespace std;

int main()
{
	int a[10][10];
	int rows,cols;
	cin>>rows>>cols;

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>a[i][j];
		}
	}

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	

	return 0;
}








