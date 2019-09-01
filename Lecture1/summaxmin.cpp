#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0,max=INT_MIN,min=INT_MAX,a;
	int i=1;
	while(i<=n)
	{
		cin>>a;
		sum=sum+a;
		if(max<a)
		{
			max=a;
		}

		if(min>a)
		{
			min=a;
		}
		i=i+1;
	}

	cout<<sum/n<<" "<<max<<" "<<min<<endl;
	return 0;


}























