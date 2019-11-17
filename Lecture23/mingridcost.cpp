#include<iostream>
using namespace std;

int topDown(int cost[4][4],int i,int j ,int dp[100][100])
{
	if(i==0 && j==0)
	{
		dp[i][j]=cost[i][j];
		return dp[i][j];
	}

	else if(i==0 && j>0)
	{
		dp[i][j]=cost[i][j]+topDown(cost,i,j-1,dp);
		return dp[i][j];
	}

	else if(j==0 && i>0)
	{
		dp[i][j]=cost[i][j]+topDown(cost,i-1,j,dp);
		return dp[i][j];
	}

	else if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}

	int ans=cost[i][j]+min(topDown(cost,i-1,j,dp),topDown(cost,i,j-1,dp));
	dp[i][j]=ans;
	return dp[i][j];

}

int bottomUp(int cost[4][4],int n,int m)
{
	int dp[100][100];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j]=cost[i][j];
			}

			else if(i==0 && j>0)
			{
				dp[i][j]=cost[i][j]+dp[i][j-1];
			}

			else if(j==0 && i>0)
			{
				dp[i][j]=cost[i][j]+dp[i-1][j];
			}

			else
			{
				dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1]);
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

int minGridCost(int cost[4][4],int i,int j)
{
	if(i==0 && j==0)
	{
		return cost[i][j];
	}

	else if(i==0 && j>0)
	{
		return cost[i][j]+minGridCost(cost,i,j-1);
	}

	else if(j==0 && i>0)
	{
		return cost[i][j]+minGridCost(cost,i-1,j);
	}

	int ans=cost[i][j]+min(minGridCost(cost,i-1,j),minGridCost(cost,i,j-1));
	return ans;
}

int main()
{
	int cost[4][4]={{3,7,3,5},{3,2,8,3},{5,7,10,20},{15,2,2,7}};

	int dp[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			dp[i][j]=-1;
		}
	}

	cout<<bottomUp(cost,3,3)<<endl;
	cout<<topDown(cost,3,3,dp)<<endl;
	cout<<minGridCost(cost,3,3)<<endl;
	return 0;
}