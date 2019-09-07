#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int setbits=0;
	while(n>0)
	{
		int rem=n%2;
		setbits+=rem;
		n/=2;
	}

	cout<<setbits<<endl;
	return 0;
}