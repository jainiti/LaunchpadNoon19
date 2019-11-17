#include<iostream>
using namespace std;

int topDown(int n,int dp[])
{
	if(n==0||n==1)
	{
		dp[n]=n;
		return dp[n];
	}

	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int ans=topDown(n-1,dp)+topDown(n-2,dp);
	dp[n]=ans;
	return dp[n];
}

int bottomUp(int n)
{
	int dp[100];
	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}

	for(int i=0;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;

	return dp[n];
}

int fibo(int n)
{
	if(n==0||n==1)
	{
		return n;
	}

	return fibo(n-1)+fibo(n-2);
}



int main()
{
	int n;
	cin>>n;

	int dp[100];
	for(int i=0;i<100;i++)
	{
		dp[i]=-1;
	}

	cout<<bottomUp(n)<<endl;
	cout<<topDown(n,dp)<<endl;
	cout<<fibo(n)<<endl;
	return 0;
}























