#include<iostream>
using namespace std;

int fib(int index)
{
	//base case
	if(index==0 || index==1)
	{
		return index;
	}

	int ans=fib(index-1)+fib(index-2);
	return ans;

}

int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}