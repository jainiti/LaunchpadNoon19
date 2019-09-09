#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for(int rows=1;rows<=n;rows++)
	{
		for(int col=1;col<=rows;col++)
		{
			cout<<"*";
		}
		cout<<" ";

		for(int col=1;col<=n-rows+1;col++)
		{
			cout<<"*";
		}

		cout<<" ";

		for(int col=1;col<=n-rows+1;col++)
		{
			cout<<"*";
		}
		cout<<" ";

		for(int col=1;col<=rows;col++)
		{
			cout<<"*";
		}

		cout<<endl;
	}

	return 0;
}






















