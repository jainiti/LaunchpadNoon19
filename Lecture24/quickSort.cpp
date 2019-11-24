#include<iostream>
using namespace std;


int quickSortHelper(int arr[],int s,int e)
{
	int pivot=arr[e];
	int i=s-1;

	for(int j=s;j<e;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}

	i++;
	swap(arr[i],arr[e]);
	return i;
}

void quickSort(int *arr,int s,int e)
{
	if(s>e)
	{
		return;
	}

	int pi=quickSortHelper(arr,s,e);
	quickSort(arr,s,pi-1);
	quickSort(arr,pi+1,e);
}

int main()
{
	int arr[]={10,80,30,90,40,50,70};
	int n=sizeof(arr)/sizeof(int);

	quickSort(arr,0,n-1);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}