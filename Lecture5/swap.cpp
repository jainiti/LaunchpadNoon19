#include<iostream>
using namespace std;

void swap(int &p1,int &q1)
{
	int temp=p1;
	p1=q1;
	q1=temp;

	cout<<"inside swap fn "<<p1<<" "<<q1<<endl;
}

int main()
{
	int p,q;
	cin>>p>>q;

	cout<<p<<" "<<q<<endl;
	swap(p,q);
	cout<<p<<" "<<q<<endl;
	return 0;
}