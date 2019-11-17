#include<iostream>
using namespace std;

int topDown(int n,int dp[])
{
	if(n==1)
	{
		dp[n]=0;
		return dp[n];
	}

	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
	op1=1+topDown(n-1,dp);

	if(n%2==0)
	{
		op2=1+topDown(n/2,dp);
	}

	if(n%3==0)
	{
		op3=1+topDown(n/3,dp);
	}

	dp[n]=min(op1,min(op2,op3));
	return dp[n];

}

int bottomUp(int n)
{
	int dp[100];
	dp[1]=0;

	for(int i=2;i<=n;i++)
	{

		int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
		op1=1+dp[i-1];
		if(i%2==0)
		{
			op2=1+dp[i/2];
		}

		if(i%3==0)
		{
			op3=1+dp[i/3];
		}

		dp[i]=min(op1,min(op2,op3));
	}

	for(int i=1;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;

	return dp[n];
}

int minSteps(int n)
{
	if(n==1)
	{
		return 0;
	}

	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
	op1=1+minSteps(n-1);
	if(n%2==0)
	{
		op2=1+minSteps(n/2);
	}
	
	if(n%3==0)
	{
		op3=1+minSteps(n/3);
	}

	return min(op1,min(op2,op3));
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
	cout<<minSteps(n)<<endl;
	return 0;
}










