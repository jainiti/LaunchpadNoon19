#include<iostream>
using namespace std;

void readLine(char str[],char delimeter='\n')
{
	char ch;
	ch=cin.get();
	int i=0;
	while(ch!=delimeter)
	{
		str[i++]=ch;
		ch=cin.get();
		// i++;
	}
	str[i]='\0';
	return;
}

int main()
{
	char str[1000];
	// cin>>str;
	// cin.getline(str,1000);
	// cin.getline(str,1000,'$');

	// readLine(str);
	readLine(str,'$');
	cout<<str<<endl;
	return 0;
}















