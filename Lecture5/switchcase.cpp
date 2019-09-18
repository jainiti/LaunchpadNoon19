#include<iostream>
using namespace std;

int main()
{
	char ch;
	cin>>ch;

	switch(ch)
	{
		case 'm':
		case 'M': cout<<"Monday"<<endl;
				  break;

		case 't':
		case 'T': cout<<"Tuesday"<<endl;
				  break;

		case 'w': 
		case 'W': cout<<"Wednesday"<<endl;
					break;

		default: cout<<"Any other day"<<endl;					  
	}
	return 0;
}