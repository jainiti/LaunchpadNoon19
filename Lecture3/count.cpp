#include<iostream>
using namespace std;

int main()
{
	char ch;
	ch=cin.get();
	int characters=0,digit=0,whitespaces=0,spcharacters=0;
	while(ch!='$')
	{
		if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
		{
			characters++;
		}
		else if(ch>='0' && ch<='9')
		{
			digit++;
		}
		else if(ch==' ')
		{
			whitespaces++;
		}
		else
		{
			spcharacters++;
		}
		ch=cin.get();
	}
	cout<<"characters are"<<characters<<endl;
	cout<<"digit are "<<digit<<endl;
	cout<<"whitespace are "<<whitespaces<<endl;
	cout<<"spcharacters are "<<spcharacters<<endl;
	return 0;
}










