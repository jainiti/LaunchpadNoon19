#include<iostream>
using namespace std;

bool checkprime(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	return true;
}

// bool checkprime(int);

void printPrime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(checkprime(i))
		{
			cout<<i<<" ";
		}
	}
	return;
}


// bool checkprime(int num)
// {
// 	for(int i=2;i<num;i++)
// 	{
// 		if(num%i==0)
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

int main()
{
	int n;
	cin>>n;

	printPrime(n);

	// // bool ans=checkprime(n);
	// if(checkprime(n))
	// {
	// 	cout<<"prime"<<endl;
	// }
	// else
	// {
	// 	cout<<"not prime"<<endl;
	// }
	return 0;
}





