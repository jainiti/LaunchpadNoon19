#include <iostream>
#include <stack>
using namespace std;


int main(){
	stack<float> s;

	s.push(3.3);
	s.push(3.1);
	s.push(3.2);
	

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}


	return 0;
}