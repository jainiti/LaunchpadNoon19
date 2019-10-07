#include<iostream>
using namespace std;

bool isSafeToPut(int number,int mat[][9],int n,int i,int j)
{
	for(int k=0;k<n;k++)
	{
		if(mat[i][k]==number || mat[k][j]==number)
		{
			return false;
		}
	}

	int starti=(i/3)*3;
	int startj=(j/3)*3;

	for(int k=starti;k<starti+3;k++)
	{
		for(int l=startj;l<startj+3;l++)
		{
			if(mat[k][l]==number)
			{
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolver(int mat[][9],int n,int i,int j)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	if(j==n)
	{
		return sudokuSolver(mat,n,i+1,0);
	}
	if(mat[i][j]!=0)
	{
		return sudokuSolver(mat,n,i,j+1);
	}

	for(int number=1;number<=9;number++)
	{
		if(isSafeToPut(number,mat,n,i,j))
		{
			mat[i][j]=number;
			bool kyaAageRakhPaye=sudokuSolver(mat,n,i,j+1);
			if(kyaAageRakhPaye)
			{
				return true;
			}
			mat[i][j]=0;
		}
	}
	return false;
}

int main()
{
	int mat[9][9] =
		{{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};

	sudokuSolver(mat,9,0,0);
	return 0;
}