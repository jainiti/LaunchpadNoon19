#include<iostream>
using namespace std;

int optimised(int n,int k)
{
	int dp[100];
	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n;i++)
	{
		if(i-k-1>=0)
		{
			dp[i]=2*dp[i-1]-dp[i-k-1];
		}
		else
		{
			dp[i]=2*dp[i-1];
		}
	}

	return dp[n];
}

int bottomUp(int n,int k)
{
	int dp[100]={0};
	dp[0]=1;

	for(int i=1;i<=n;i++)
	{
		for(int m=1;m<=k;m++)
		{
			if(i-m>=0)
			{
				dp[i]+=dp[i-m];
			}
		}
	}

	return dp[n];
}

int topDown(int n,int k,int dp[])
{
	if(n==0)
	{
		dp[n]=1;
		return dp[n]; 
	}

	if(n<0)
	{
		return 0;
	}

	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int ans=0;
	for(int m=1;m<=k;m++)
	{
		ans+=topDown(n-m,k,dp);
	}

	dp[n]=ans;
	return dp[n];

}

int nStairs(int n,int k)
{
	if(n==0)
	{
		return 1;
	}

	if(n<0)
	{
		return 0;
	}

	int ans=0;
	for(int m=1;m<=k;m++)
	{
		ans+=nStairs(n-m,k);
	}
	return ans;
}

int main()
{
	int n,k;
	cin>>n>>k;

	int dp[100];
	for(int i=0;i<100;i++)
	{
		dp[i]=-1;
	}

	cout<<optimised(n,k)<<endl;
	cout<<bottomUp(n,k)<<endl;
	cout<<topDown(n,k,dp)<<endl;
	cout<<nStairs(n,k)<<endl;
	return 0;
}