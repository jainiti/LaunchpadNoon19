#include<iostream>
using namespace std;

int bottomUp(int bottles[],int n)
{
	int dp[100][100]={0};
	int day=n;

	for(int i=0;i<n;i++)
	{
		dp[i][i]=bottles[i]*day;
	}

	day--;

	for(int len=2;len<=n;len++)
	{
		int i=0;
		int maxi=n-len;
		while(i<=maxi)
		{
			int j=i+len-1;
			int op1=bottles[i]*day+dp[i+1][j];
			int op2=bottles[j]*day+dp[i][j-1];

			dp[i][j]=max(op1,op2);
			i++;
		}
		day--;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[0][n-1];

}

int maxProfit(int bottles[],int i,int j,int day)
{
	if(i>j)
	{
		return 0;
	}

	int op1=bottles[i]*day+maxProfit(bottles,i+1,j,day+1);
	int op2=bottles[j]*day+maxProfit(bottles,i,j-1,day+1);

	return max(op1,op2);
}

int main()
{
	int bottles[]={2,3,5,1,4};
	int n=sizeof(bottles)/sizeof(int);

	cout<<bottomUp(bottles,n)<<endl;
	cout<<maxProfit(bottles,0,n-1,1)<<endl;
	return 0;
}