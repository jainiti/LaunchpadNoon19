#include<iostream>
using namespace std;

void mergeSortedArray(int a[],int n,int b[],int m)
{
	int i=n-1,j=m-1,k=n+m-1;
	while(i>=0 && j>=0)
	{
		if(a[i]>b[j])
		{
			a[k]=a[i];
			k--;
			i--;
		}
		else
		{
			a[k]=b[j];
			k--;
			j--;
		}
	}

	while(j>=0)
	{
		a[k]=b[j];
		k--;
		j--;
	}
}


int main()
{
	int a[7]={12,16,28,90};
	int b[3]={1,17,27};

	mergeSortedArray(a,4,b,3);

	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}