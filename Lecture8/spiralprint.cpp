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


	int sr=0,sc=0,er=rows-1,ec=cols-1;

	while(sr<=er&&sc<=ec)
	{
		for(int j=sc;j<=ec;j++)
		{
			cout<<a[sr][j]<<" ";
		}
		sr++;

		for(int i=sr;i<=er;i++)
		{
			cout<<a[i][ec]<<" ";
		}
		ec--;

		if(sr<=er)
		{
			for(int j=ec;j>=sc;j--)
			{
				cout<<a[er][j]<<" ";
			}
			er--;
		}
			
		if(sc<=ec)
		{
			for(int i=er;i>=sr;i--)
			{
				cout<<a[i][sc]<<" ";
			}
			sc++;
		}
	}



	return 0;
}



















