#include<iostream>
#include<map>
using namespace std;

class node
{
public:
	char ch;
	map<char,node*>mp;
	bool isterminal;

	node(char c)
	{
		ch=c;
		isterminal=false;
	}
};

class Trie
{
public:
	node* root;

	Trie()
	{
		root=new node('\0');
	}

	void addWord(char str[])
	{
		node* temp=root;
		for(int i=0;str[i]!='\0';i++)
		{
			char c=str[i];
			
			if(temp->mp.count(c)==0)
			{
				node* n=new node(c);
				temp->mp[c]=n;
			}
			temp=temp->mp[c];
		}
		temp->isterminal=true;
	}

	bool searchWord(char key[])
	{
		node* temp=root;
		for(int i=0;key[i]!='\0';i++)
		{
			char c=key[i];
			if(temp->mp.count(c)==0)
			{
				return false;
			}
			temp=temp->mp[c];
		}
		return temp->isterminal;
	}

};


int main()
{

	Trie t;
	t.addWord("apple");
	t.addWord("head");
	t.addWord("coding");

	char key[1000];
	cin>>key;
	if(t.searchWord(key))
	{
		cout<<"key exists"<<endl;
	}
	else
	{
		cout<<"it doesnot exists"<<endl;
	}
	return 0;
}









