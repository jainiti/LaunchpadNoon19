#include<iostream>
using namespace std;

int main()
{
	char ch;
	ch=cin.get();
	int count=0;
	while(ch!='$')
	{
		count++;
		ch=cin.get();
	}
	cout<<count<<endl;
	return 0;
}