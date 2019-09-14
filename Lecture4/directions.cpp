#include<iostream>
using namespace std;

int main()
{
	int x=0,y=0;
	char ch;
	ch=cin.get();
	while(ch!='$')
	{
		if(ch=='N')
		{
			y++;
		}
		else if(ch=='S')
		{
			y--;
		}
		else if(ch=='E')
		{
			x++;
		}
		else
		{
			x--;
		}
		ch=cin.get();
	}

	if(x>=0 && y>=0)
	{
		while(x--)
		{
			cout<<'E';
		}
		while(y--)
		{
			cout<<'N';
		}
	}
	else if(x<=0 && y>=0)
	{
		while(y--)
		{
			cout<<'N';
		}
		x*=-1;
		while(x--)
		{
			cout<<'W';
		}
	}
	else if(x<=0 && y<=0)
	{
		y*=-1;
		while(y--)
		{
			cout<<'S';
		}

		x*=-1;
		while(x--)
		{
			cout<<'W';
		}

	}
	else 
	{
		while(x--)
		{
			cout<<'E';
		}

		y*=-1;
		while(y--)
		{
			cout<<'S';
		}
	}
	return 0;
}









