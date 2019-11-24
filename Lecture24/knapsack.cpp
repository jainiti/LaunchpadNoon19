#include<iostream>
using namespace std;

int bottomUp(int wts[],int profits[],int capacity,int n)
{
	int dp[100][100];

	for(int item=0;item<=n;item++)
	{
		for(int weight=0;weight<=capacity;weight++)
		{
			if(item==0 || weight==0)
			{
				dp[item][weight]=0;
			}
			int inc=0,exc=0;
			if(weight>=wts[item-1])
			{
				inc=profits[item-1]+dp[item-1][weight-wts[item-1]];
			}
			exc=dp[item-1][weight];

			dp[item][weight]=max(inc,exc);
		}
	}


	for(int item=0;item<=n;item++)
	{
		for(int weight=0;weight<=capacity;weight++)
		{
			cout<<dp[item][weight]<<" ";
		}
		cout<<endl;
	}

	return dp[n][capacity];

}

int knapsack(int wts[],int profits[],int n,int capacity)
{
	if(n==0 || capacity==0)
	{
		return 0;
	}

	int inc=0,exc=0;
	if(capacity>=wts[n-1])
	{
		inc=profits[n-1]+knapsack(wts,profits,n-1,capacity-wts[n-1]);
	}
	exc=knapsack(wts,profits,n-1,capacity);

	return max(inc,exc);
}

int main()
{
	int wts[]={7,4,3};
	int profits[]={15,8,9};

	int n=sizeof(wts)/sizeof(int);

	int capacity;
	cin>>capacity;

	cout<<bottomUp(wts,profits,capacity,n)<<endl;
	cout<<knapsack(wts,profits,n,capacity)<<endl;
	return 0;
}