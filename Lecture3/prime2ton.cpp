#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for(int num=2;num<=n;num++)
	{
		int i;
		for(i=2;i<num;i++)
		{
			if(num%i==0)
			{
				break;
			}
		}

		if(i==num)
		{
			cout<<num<<" ";
		}
	}
	return 0;
}





