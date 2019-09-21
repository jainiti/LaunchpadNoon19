#include<iostream>
using namespace std;

int sum(int *a1,int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=*(a1+i);
	}
	return ans;
}

int main()
{
	// int a=10;
	// int* intptr=&a;

	// cout<<intptr<<endl;
	// cout<<&a<<endl;
	// cout<<a<<endl;
	// cout<<*intptr<<endl; 


	// char ch='A';
	// char* chptr=&ch;

 //    cout<<(int*)chptr<<endl;
	// cout<<ch<<endl;

	int a[]={1,2,3,4,5};
	// cout<<a<<endl;
	// cout<<&a[0]<<endl;
	// cout<<&a<<endl;
     

	cout<<sum(a,5)<<endl;


	return 0;
}













