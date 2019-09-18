#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	//insertion sort
	for(int i=1;i<n;i++)
	{
		int card=a[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			// if(a[j]>card)
			// {
			// 	a[j+1]=a[j];
			// }
			// else
			// {
			// 	break;
			// }
			if(card>a[j])
			{
				break;
			}
			a[j+1]=a[j];
		}
		a[j+1]=card;
	}



	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}