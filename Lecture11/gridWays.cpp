#include<iostream>
using namespace std;

int gridWays(int i,int j)
{
	if(i==0 && j==0)
	{
		return 1;
	}

	if(i<0 || j<0)
	{
		return 0;
	}

	int ans=gridWays(i-1,j)+gridWays(i,j-1);
	return ans;
}

int main()
{
	int i,j;
	cin>>i>>j;
	cout<<gridWays(i,j)<<endl;
	return 0;
}