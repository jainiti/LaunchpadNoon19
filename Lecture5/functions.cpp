#include<iostream>
using namespace std;

void welcome()
{
	cout<<"welcome to coding blocks"<<endl;
	return;
}


int Sum(int a=0,int b=0)
{
	int sum=a+b;
	return sum;
}


int main()
{
	welcome();
	welcome();

	int s=Sum(4,5);
	cout<<Sum(4,5)<<endl;
	cout<<Sum(4)<<endl;
	cout<<Sum()<<endl;
	// cout<<s<<endl;  
	return 0;
}












