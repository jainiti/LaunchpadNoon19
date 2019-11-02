// ReverseStack
#include <iostream>
#include <stack>
using namespace std;

void pushBottom(stack<int> &s,int top){
	if(s.empty()){
		s.push(top);
		return;
	}

	int topElement = s.top();
	s.pop();
	pushBottom(s,top);
	s.push(topElement);
}

void reverseStack(stack<int> &s){
	if(s.empty()){
		return;
	}

	int top = s.top();
	s.pop();
	reverseStack(s);
	pushBottom(s,top);
}

void Print(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}		
}

int main(){
	stack<int> s;

	s.push(3);
	s.push(2);
	s.push(1);

	Print(s);
	reverseStack(s);
	Print(s);


	return 0;
}