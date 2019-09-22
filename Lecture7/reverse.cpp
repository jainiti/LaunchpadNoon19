#include<iostream>
using namespace std;

void reverse(char ch[])
{
	int i=0,j=strlen(ch)-1;
	while(i<=j)
	{
		swap(ch[i],ch[j]);
		i++;
		j--;
	}
}

int main()
{
	char ch[100];
	cin>>ch;

	reverse(ch);
	cout<<ch<<endl;
	return 0;
}