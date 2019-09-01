#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int row=1;
	int val;
	while(row<=n)
	{
		if(row%2==0)
		{
			val=0;
		}
		else
		{
			val=1;
		}
		int col=1;
		while(col<=row)
		{
			cout<<val<<" ";
			val=1-val;
			col=col+1;
		}

		row=row+1;
		cout<<endl;
	}
	return 0;
}






