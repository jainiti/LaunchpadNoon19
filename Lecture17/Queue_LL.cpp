// ReverseStack
#include <iostream>
// #include <queue>
#include "queue.h"
using namespace std;


int main(){
	queue q;


	q.push(1);
	q.push(2);
	q.push(3);

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}

	return 0;
}