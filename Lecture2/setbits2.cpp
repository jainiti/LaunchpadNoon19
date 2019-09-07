#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int setbits=0;

	//method1
	while(n>0)
	{
		int lastbit=n&1;
		setbits+=lastbit;
		n=n>>1;
	}	

	cout<<setbits<<endl;

	return 0;
}





























