#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int i=1;
	while(i<=n)
	{
		if(i%2==0)
		{
			cout<<i<<" ";
		}
		
		i=i+1;
	}
	/*cin>>n>>p;
	cout<<n<<" "<<p<<endl; 
	*/
	// cout<<"hello world"<<endl;
	return 0;
}