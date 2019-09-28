#include<iostream>
using namespace std;

bool matched(char ch[],char key[])
{
	if(strlen(ch)!=strlen(key))
	{
		return false;
	}
	else
	{
		int j;
		for(j=0;ch[j]!='\0';j++)
		{
			if(ch[j]!=key[j])
			{
				return false;
			}
		}
		return true;
	}
}


int main()
{
	char s[10][100]={"delhi","noida","agra","coding","blocks","hey","gurgaon","there","c++","java"};

	char key[100];
	cin>>key;
	int i;
	for(i=0;i<10;i++)
	{
		if(matched(s[i],key))
		{
			cout<<"found"<<endl;
			break;
		}
	}

	if(i==10)
	{
		cout<<"Not found"<<endl;
	}
	return 0;
}