#include<iostream>
using namespace std;

bool ratInAMaze(int sol[][10],char maze[][5],int n,int m,int i,int j)
{
	if(i==n-1 && j==m-1)
	{
		sol[i][j]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	sol[i][j]=1;
	if(j+1<m && maze[i][j+1]!='X')
	{
		bool kyaRightSeBaatBani=ratInAMaze(sol,maze,n,m,i,j+1);
		if(kyaRightSeBaatBani)
		{
			return true;
		}
	}

	if(i+1<n && maze[i+1][j]!='X')
	{
		bool kyaNeecheSeBaatBani=ratInAMaze(sol,maze,n,m,i+1,j);
		if(kyaNeecheSeBaatBani)
		{
			return true;
		}
	}

	sol[i][j]=0;
	return false;
}

int main()
{
	int n,m;
	// cin>>n>>m;
	char maze[][5]={"00XX","0000","00XX","0000"};
	int sol[10][10]={0};
	ratInAMaze(sol,maze,4,4,0,0);
	return 0;
}