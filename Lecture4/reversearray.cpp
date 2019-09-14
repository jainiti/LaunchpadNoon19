#include<iostream>
using namespace std;

int main()
{
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);

	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	cout<<sum<<endl;
	for(int index=n-1;index>=0;index--)
	{
		cout<<a[index]<<" ";
	}
	cout<<endl;

	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}

	cout<<max<<endl;
	return 0;
}










