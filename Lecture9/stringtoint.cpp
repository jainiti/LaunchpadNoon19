#include<iostream>
using namespace std;

int stringToInt(char ch[],int l)
{
	if(l==0)
	{
		return 0;
	}

	int lastTerm=ch[l-1]-'0';
	return stringToInt(ch,l-1)*10+lastTerm;
}

int main()
{
	char ch[100];
	cin>>ch;

	int len=strlen(ch);
	cout<<stringToInt(ch,len)<<endl;
	cout<<stringToInt(ch,len)/10<<endl;
	return 0;
}