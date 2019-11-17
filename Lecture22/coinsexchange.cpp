#include<iostream>
using namespace std;

int bottomUp(int coins[],int n,int amount)
{
	int dp[100];
	dp[0]=0;

	for(int i=1;i<=amount;i++)
	{
		int ans=INT_MAX,smallans=INT_MAX;
		for(int j=0;j<n;j++)
		{
			if(i>=coins[j])
			{
				smallans=1+dp[i-coins[j]];
			}
			ans=min(ans,smallans);
		}
		dp[i]=ans;
	}

	for(int i=0;i<=amount;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;

	return dp[amount];
}


int topDown(int coins[],int n,int amount,int dp[])
{
	if(amount==0)
	{
		dp[amount]=0;
		return dp[amount];
	}

	if(dp[amount]!=-1)
	{
		return dp[amount];
	}

	int ans=INT_MAX,smallans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(amount>=coins[i])
		{
			smallans=topDown(coins,n,amount-coins[i],dp);
		}
		if(smallans!=INT_MAX)
		{
			ans=min(ans,smallans+1);
		}
	}

	dp[amount]=ans;
	return ans;
}

int coinRec(int coins[],int n,int amount)
{
	if(amount==0)
	{
		return 0;
	}

	int ans=INT_MAX,smallans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(amount>=coins[i])
		{
			smallans=coinRec(coins,n,amount-coins[i]);
		}
		if(smallans!=INT_MAX)
		{
			ans=min(ans,smallans+1);
		}
	}

	return ans;
}

int main()
{
	int coins[]={1,7,10};
	int n=sizeof(coins)/sizeof(int);

	int amount;
	cin>>amount;

	int dp[100];
	for(int i=0;i<100;i++)
	{
		dp[i]=-1;
	}

	cout<<bottomUp(coins,n,amount)<<endl;
	cout<<topDown(coins,n,amount,dp)<<endl;
	cout<<coinRec(coins,n,amount)<<endl;
	return 0;
}