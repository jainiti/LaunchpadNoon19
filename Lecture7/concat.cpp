#include<iostream>
using namespace std;

int length(char ch[])
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{

	}
	return i;
}

void concat(char a[],char b[])
{
	int i,l=length(a);
	for(i=0;b[i]!='\0';i++)
	{
		a[l+i]=b[i];
	}
	a[l+i]='\0';
}

int main()
{
	char A[1000],B[1000];
	cin>>A>>B;

	concat(A,B);
	cout<<A<<endl;
	cout<<B<<endl;
	return 0;
}