#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(char *a){
	stack<char> s;

	for(int i=0;a[i]!='\0';i++){
		char ch = a[i];

		switch(ch){
			case '{':
			case '(':
			case '[': s.push(ch);
						break;
			case '}':
						if(!s.empty() && s.top() == '{'){
							s.pop();
						}
						else{
							return false;
						}
						break;
			case ')':
						if(!s.empty() && s.top() == '('){
							s.pop();
						}
						else{
							return false;
						}
						break;
			case ']':
						if(!s.empty() && s.top() == '['){
							s.pop();
						}
						else{
							return false;
						}

		}

	}

	if(s.empty() == true){
		return true;
	}
	else{
		return false;
	}


}

int main(){

	char a[100] = "{a+b+[c+d)*e+f}";

	if(isBalanced(a)){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}



	return 0;
}