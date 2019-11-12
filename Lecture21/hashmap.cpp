#include<iostream>
using namespace std;


class node
{
public:
	string key;
	int value;
	node* next;

	node(string key,int value)
	{
		this->key=key;
		this->value=value;
		next=NULL;
	}
};


class hashMap
{

	void rehash()
	{
		node** oldbucket=bucket;
		int oldsize=ms;

		ms=2*ms;
		bucket=new node*[ms];
		for(int i=0;i<ms;i++)
		{
			bucket[i]=NULL;
		}

		for(int i=0;i<oldsize;i++)
		{
			node* temp=oldbucket[i];
			while(temp)
			{
				insert(temp->key,temp->value);
				temp=temp->next;
			}

			delete oldbucket[i];
		}

		delete []oldbucket;


	}


public:
	node** bucket;
	int cs;
	int ms;

	hashMap(int ts)
	{
		bucket=new node*[ts];
		cs=0;
		ms=ts;

		for(int i=0;i<ms;i++)
		{
			bucket[i]=NULL;
		}
	}

	int hashfn(string key)
	{
		int ans=0;
		int mult=13;

		for(int i=0;i<key.length();i++)
		{
			int num=key[i]*mult;
			ans+=num;
			mult*=13;

			ans%=ms;
			mult%=ms;
		}

		return ans%ms;
	}

	void insert(string key,int value)
	{
		int index=hashfn(key);
		node* temp=bucket[index];

		int flag=0;
		while(temp)
		{
			if(temp->key==key)
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}

		if(flag!=1)
		{
			node* n=new node(key,value);
			n->next=bucket[index];
			bucket[index]=n;
			cs++;

			float loadfactor=cs/(1.0*ms);
			if(loadfactor>=0.7)
			{
				rehash();
			}
		}

	}

	void print()
	{
		for(int i=0;i<ms;i++)
		{
			node* temp=bucket[i];
			cout<<i<<"--> ";
			while(temp)
			{
				cout<<"( "<<temp->key<<" "<<temp->value<<" ) ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	node* search(string key)
	{
		int index=hashfn(key);
		node* temp=bucket[index];
		while(temp)
		{
			if(temp->key==key)
			{
				return temp;
			}
			temp=temp->next;
		}

		return NULL;
	}

	int& operator[](string key)
	{
		node* temp=search(key);
		if(temp==NULL)
		{
			int garbage;
			insert(key,garbage);
			temp=search(key);
			return temp->value;
		}

		return temp->value;
	}
};

int main()
{
	hashMap h(5);
	h.insert("apple",300);
	h.insert("orange",250);
	// h.insert("apple",350);

	h["apple"]=350;

	h["cherry"]=200;

	// h.insert("cherry",100);
	// h.insert("papaya",200);
	// h.insert("banana",320);

	h.print();
	return 0;
}


















