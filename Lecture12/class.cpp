#include<iostream>
using namespace std;

class car
{
	int price;
public:
	char *name;
	// int price;
	int seats;
	int tyres;
	char color[20];

	car()
	{
		cout<<"In Default Constructor"<<endl;
		name=NULL;
	}

	car(char *n,int p,int s,int t,char *c)
	{
		cout<<"Inside paramaterised Constructor"<<endl;
		name=new char[strlen(n)+1];
		strcpy(name,n);
		price=p;
		seats=s;
		tyres=t;
		strcpy(color,c);
	}

	void print()
	{
		cout<<"name is : "<<name<<endl;
		cout<<"price is : "<<price<<endl;
		cout<<"seats are: "<<seats<<endl;
		cout<<"tyres are : "<<tyres<<endl;
		cout<<"color is : "<<color<<endl;
		cout<<endl;
	}

	void setName(char *n)
	{
		if(name!=NULL)
		{
			delete name;
			name=NULL;
		}
		name=new char[strlen(n)+1];
		strcpy(name,n);
	}

	void setPrice(int p)
	{
		if(p>=500)
		{
			price=p;
		}
		
	}

	car(car &X)
	{
		cout<<"Inside Copy Constructor"<<endl;
		name=new char[strlen(X.name)+1];
		strcpy(name,X.name);
		seats=X.seats;
		price=X.price;
		tyres=X.tyres;
		strcpy(color,X.color);	
	}

	void operator=(car X)
	{
		cout<<"Inside = operator "<<endl;
		name=new char[strlen(X.name)+1];
		strcpy(name,X.name);
		seats=X.seats;
		price=X.price;
		tyres=X.tyres;
		strcpy(color,X.color);
	}

	void operator+=(car X)
	{
		char *oldname=name;
		name=new char[strlen(name)+strlen(X.name)+1];
		strcpy(name,oldname);
		strcat(name,X.name);
		seats+=X.seats;
		price+=X.price;
		tyres+=X.tyres;
		strcat(color,X.color);
	}


};

int main()
{
	car A;
	// A.price=200;
	A.setPrice(2000);
	// strcpy(A.name,"AUDI");
	A.setName("AUDI");
	A.seats=4;
	A.tyres=4;
	strcpy(A.color,"red");

	car B("BMW",2000,4,4,"black");
	B.setName("Maruti");

	// cout<<"name is : "<<A.name<<endl;
	// cout<<"price is : "<<A.price<<endl;
	// cout<<"seats are: "<<A.seats<<endl;
	// cout<<"tyres are : "<<A.tyres<<endl;
	// cout<<"color is : "<<A.color<<endl;

	car C(A);
	car D=A;

	car E;
	E=C;

	E+=B;

	C.name[0]='Z';

	A.print();
	B.print();
	C.print();
	D.print();
	E.print();
	return 0;
}

















