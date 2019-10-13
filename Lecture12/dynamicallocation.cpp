#include<iostream>
using namespace std;

int* createArray(int n)
{
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		a[i]=n;
	}
	return a;
}

int main()
{
	int* a=new int;
	*a=10;

	delete a;

	int* arr=new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i]=i;
	}

	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int *app=createArray(5);
	for(int i=0;i<5;i++)
	{
		cout<<app[i]<<" ";
	}
	cout<<endl;


	int r=4,c=4;
	int** twod=new int*[r];

	for(int i=0;i<r;i++)
	{
		twod[i]=NULL;
	}

	for(int i=0;i<r;i++)
	{
		twod[i]=new int[c];
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			twod[i][j]=i*j;
		}
	}


	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<twod[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i=0;i<r;i++)
	{
		delete []twod[i];
	}

	delete []twod;

	return 0;
}











