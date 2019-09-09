#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for(int rows=n;rows>=1;rows--)
	{
		char ch='A';
		for(int col=1;col<=rows;col++)
		{
			cout<<ch;
			ch++;
		}

		ch=ch-1;
		for(int col=1;col<=rows;col++)
		{
			cout<<ch;
			ch--;
		}

		cout<<endl;

	}
	return 0;
}












