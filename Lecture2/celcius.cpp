#include<iostream>
using namespace std;

int main()
{
	int initial,step,final;
	cin>>initial>>step>>final;

	int f=initial;
	while(f<=final)
	{
		int c=(5/9.0)*(f-32);
		cout<<f<<" "<<c<<endl;
		f=f+step;
	}
	return 0;
}