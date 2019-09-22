#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char str1[100],str2[100],str3[100];
	cin>>str1>>str2;

	cout<<strlen(str1)<<endl;


	strcpy(str3,str2);
	cout<<str3<<endl;

	strcat(str1,str2);
	cout<<str1<<endl;
	return 0;
}