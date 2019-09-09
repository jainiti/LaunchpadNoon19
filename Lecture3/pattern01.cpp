#include<iostream>
using namespace std;

int main()
{
	int n,val;
	cin>>n;

	for(int rows=1;rows<=n;rows++)
	{
		if(rows%2)
		{
			val=1;
		}
		else
		{
			val=0;
		}

		for(int col=1;col<=rows;col++)
		{
			cout<<val<<" ";
			val=1-val;
		}
		cout<<endl;
	}
	return 0;
}











