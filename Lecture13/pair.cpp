#include<iostream>
using namespace std;

class Pair
{
public:
	int x,y;

	car(int x1,int y1)  //:x(x1),y(y1)
	{
		x=x1;
		y=y1;
	}

	bool operator>(Pair P)
	{
		if(x>=P.x && y>=P.y)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Pair P1(4,5);
	Pair P2(2,3);

	if(P1>P2)
	{
		cout<<"P1 is greater"<<endl;
	}
	else
	{
		cout<<"P2 is greater"<<endl;
	}
	return 0;
}
















