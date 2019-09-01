#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int row=1;
	while(row<=n)
	{
		int spaces=1;
		while(spaces<=n-row)
		{
			cout<<" ";
			spaces=spaces+1;
		}

		int no=row;
		while(no<=2*row-1)
		{
			cout<<no;
			no=no+1;
		}

		no=no-2;
		while(no>=row)
		{
			cout<<no;
			no=no-1;
		}

		cout<<endl;
		row=row+1;

	}	
	return 0;
}








