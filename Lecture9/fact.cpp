#include<iostream>
using namespace std;

int fact(int n)
{
	//base case
	if(n==1)
	{
		return 1;
	}

	
	int ans=n*fact(n-1);
	return ans;
	// return n*fact(n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<fact(n)<<endl;
	return 0;
}