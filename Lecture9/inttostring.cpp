#include<iostream>
using namespace std;

string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void inttostring(int a)
{
	if(a==0)
	{
		return;
	}

	int lastDigit=a%10;
	inttostring(a/10);
	cout<<s[lastDigit]<<" ";
	return;
}

int main()
{
	int a;
	cin>>a;
	inttostring(a);
	return 0;
}