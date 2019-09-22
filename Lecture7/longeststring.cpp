#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	char ch[100],ans[100];
	int maxlen=0;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(maxlen<strlen(ch))
		{
			maxlen=strlen(ch);
			strcpy(ans,ch);
		}
	}

	cout<<ans<<" "<<maxlen<<endl;
	return 0;
}












