#include<iostream>
using namespace std;

bool isSafeToPut(int n,int sol[][10],int i,int j)
{
	for(int k=0;k<n;k++)
	{
		if(sol[k][j] || sol[i][k])
		{
			return false;
		}
	}

	int row=i;
	int col=j;

	while(row>=0 && col>=0)
	{
		if(sol[row][col])
		{
			return false;
		}
		row--;
		col--;
	}


	row=i;
	col=j;
	while(row>=0 && col<n)
	{
		if(sol[row][col])
		{
			return false;
		}
		row--;
		col++;
	}

	return true;
}

bool nqueen(int n,int sol[][10],int i)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	for(int j=0;j<n;j++)
	{
		if(isSafeToPut(n,sol,i,j))
		{
			sol[i][j]=1;
			bool kyaAageRakhnaSafeHai=nqueen(n,sol,i+1);
			if(kyaAageRakhnaSafeHai)
			{
				return true;
			}
			sol[i][j]=0;
		}
	}

	return false;
}

int main()
{
	int n;
	cin>>n;

	int sol[10][10]={0};
	nqueen(n,sol,0);
	return 0;
}