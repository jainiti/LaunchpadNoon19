#include<iostream>
using namespace std;

bool pallindrome(char ch[])
{
	int i=0,j=strlen(ch)-1;

	while(i<=j)
	{
		if(ch[i]!=ch[j])
		{
			return false;
		}
		i++;
		j--;
	}

	return true;

}

int main()
{
	char ch[1000];
	cin>>ch;

	if(pallindrome(ch))
	{
		cout<<"pallindrome"<<endl;
	}
	else
	{
		cout<<"not a pallindrome"<<endl;
	}
	return 0;
}