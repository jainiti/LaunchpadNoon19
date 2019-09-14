#include<iostream>
using namespace std;

int main()
{
	int a[]={67,90,32,56,800};
	int n=sizeof(a)/sizeof(int);


	//selection sort
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[min_index]>a[j])
			{
				min_index=j;
			}
		}
		swap(a[i],a[min_index]);
	}



	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

































