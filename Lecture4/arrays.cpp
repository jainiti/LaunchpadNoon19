#include<iostream>
using namespace std;

int main()
{	
	int a[]={1,2,3,4,5,6,3,4,6,7,8};
	int n=sizeof(a)/sizeof(int);
	cout<<"size is "<<n<<endl;
	// cin>>n;

	// for(int i=0;i<n;i++)
	// {
	// 	cin>>a[i];
	// }

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}



