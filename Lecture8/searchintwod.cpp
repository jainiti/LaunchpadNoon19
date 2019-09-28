#include<iostream>
using namespace std;


bool search(int a[10][10],int rows,int cols,int key)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(a[i][j]==key)
			{
				return true;
			}
		}
	}

	return false;
}

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

	int key;
	cin>>key;

	if(search(a,rows,cols,key))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}

	return 0;
}








