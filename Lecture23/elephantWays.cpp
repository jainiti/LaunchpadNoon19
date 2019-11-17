#include<iostream>
using namespace std;

int bottomUp(int n,int m)
{
	int dp[100][100]={0};
	dp[0][0]=1;

	int mult=1;
	for(int k=1;k<=m;k++)
	{
		dp[0][k]=mult;
		mult*=2;
	}

	mult=1;
	for(int k=1;k<=n;k++)
	{
		dp[k][0]=mult;
		mult*=2;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int p=1;p<=i;p++)
			{
				dp[i][j]+=dp[i-p][j];
			}

			for(int p=1;p<=j;p++)
			{
				dp[i][j]+=dp[i][j-p];
			}
		}
	}


	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[n][m];

}

int elephantWays(int i,int j)
{
	if(i==0 && j==0)
	{
		return 1;
	}

	int ans=0;
	for(int k=1;k<=i;k++)
	{
		ans+=elephantWays(i-k,j);
	}

	for(int k=1;k<=j;k++)
	{
		ans+=elephantWays(i,j-k);
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;

	cout<<bottomUp(n,m)<<endl;
	cout<<elephantWays(n,m)<<endl;
	return 0;
}