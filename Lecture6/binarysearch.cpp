#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key)
{
	int s=0,e=n-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<=key)
		{
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return -1;
}

int main()
{
	int arr[]={12,15,28,32,97,101};
	int n=sizeof(arr)/sizeof(int);

	int key;
	cin>>key;
	if(binarySearch(arr,n,key)==-1)
	{
		cout<<"key not found"<<endl;
	}
	else
	{
		cout<<"key found at "<<binarySearch(arr,n,key)<<"th index"<<endl;
	}
	return 0;
}












