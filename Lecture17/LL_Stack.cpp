#include <iostream>
#include "node.h"
using namespace std;

template<typename U>
class stack{
	node<U>* head;
public:
	stack(){
		head=NULL;
	}

	// push()
	void push(U d){
		// Insertion at head/front
		node<U>* n = new node<U>(d);
		n->next = head;
		head =n;
	}
	// pop()
	void pop(){
		// Deletion at front
		if(head == NULL){
			return;
		}
		node<U>* temp = head;
		head=head->next;
		delete temp;
	}
	// top()
	U top(){
		return head->data;
	}
	// empty()
	bool empty(){
		return head == NULL;
	}
};


int main(){
	stack<char> s;

	s.push('A');
	s.push('B');
	s.push('C');
	// s.push(3.3);
	// s.push(3.1);
	// s.push(3.2);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}	




	return 0;
}