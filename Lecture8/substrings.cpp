#include<iostream>
using namespace std;

int main()
{
	char ch[100];
	cin>>ch;

	for(int i=0;ch[i]!='\0';i++)
	{
		for(int j=i;ch[j]!='\0';j++)
		{
			for(int k=i;k<=j;k++)
			{
				cout<<ch[k];
			}
			cout<<endl;
		}
	}
	return 0;
}