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


	for(int j=0;j<cols;j++)
	{
		if(j%2==0)
		{
			for(int i=0;i<rows;i++)
			{
				cout<<a[i][j]<<" ";
			}
		}
		else
		{
			for(int i=rows-1;i>=0;i--)
			{
				cout<<a[i][j]<<" ";
			}
		}
	}

	cout<<endl;

	

	return 0;
}








