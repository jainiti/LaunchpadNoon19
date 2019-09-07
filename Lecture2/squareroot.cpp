#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	float i=0,inc=1;
	int precision;
	cin>>precision;
	int p=0;
	while(p<=precision)
	{
		while(i*i<=n)
		{
			i=i+inc;
		}
		i=i-inc;
		inc=inc/10;
		p++;	
	}
	
	cout<<i<<endl;
	return 0;
}