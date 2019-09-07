#include<iostream>
using namespace std;

int main()
{
	char ch;
	cin>>ch;

	if(ch>='A' && ch<='Z')
	{
		cout<<"uppercase"<<endl;
	}
	else if(ch>='a' && ch<='z')
	{
		cout<<"lowercase"<<endl;
	}
	else
	{
		cout<<"Neither uppercase not lower case"<<endl;
	}
	return 0;
}