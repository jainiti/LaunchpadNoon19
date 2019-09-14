#include<iostream>
using namespace std;

int main()
{
	int a[]={90,67,45,900,56,23,1,34,66};
	int n=sizeof(a)/sizeof(int);

	int key;
	cin>>key;
	int i;
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		{
			cout<<"found"<<endl;
			break;
		}
	}

	if(i==n)
	{
		cout<<"not found"<<endl;
	}
	return 0;
}






