#include<iostream>
using namespace std;


int bottomUp(char ch1[],char ch2[])
{
	int dp[100][100];

	int l1=strlen(ch1);
	int l2=strlen(ch2);

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}

			else if(ch1[i-1]==ch2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}

			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}


	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[l1][l2];

}

int LCS(char ch1[],char ch2[],int i,int j)
{
	if(ch1[i]=='\0'||ch2[j]=='\0')
	{
		return 0;
	}

	if(ch1[i]==ch2[j])
	{
		return 1+LCS(ch1,ch2,i+1,j+1);
	}
	else
	{
		return max(LCS(ch1,ch2,i+1,j),LCS(ch1,ch2,i,j+1));
	}
}

int main()
{
	char ch1[100],ch2[100];
	cin>>ch1>>ch2;

	cout<<bottomUp(ch1,ch2)<<endl;
	cout<<LCS(ch1,ch2,0,0)<<endl;
	return 0;
}