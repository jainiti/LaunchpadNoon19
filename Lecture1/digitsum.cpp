#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0;

	while(n>0)
	{
		int lastterm=n%10;
		sum=sum+lastterm;
		n=n/10;
	}
	cout<<sum<<endl;
	return 0;
}