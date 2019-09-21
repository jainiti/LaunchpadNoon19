#include<iostream>
using namespace std;

int factorial(int n)
{
	int ans=1;
	for(int i=n;i>=1;i--)
	{
		ans*=i;
	}
	return ans;
}

int ncr(int n,int r)
{
	int ans=factorial(n)/(factorial(n-r)*factorial(r));
	return ans;
}

int main()
{
	int n,r;
	cin>>n>>r;
	cout<<ncr(n,r)<<endl;
	return 0;
}






