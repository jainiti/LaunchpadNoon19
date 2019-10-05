#include<iostream>
using namespace std;

void towerOfHanoi(int n,char source,char helper,char destination)
{
	if(n==0)
	{
		return;
	}

	towerOfHanoi(n-1,source,destination,helper);
	cout<<"moving "<<n<<" th disc from"<<source<<" to "<<destination<<endl;
	towerOfHanoi(n-1,helper,source,destination);
}

int main()
{
	int n;
	cin>>n;
	char source='A',helper='B',destination='C';
	towerOfHanoi(n,source,helper,destination);
	return 0;
}