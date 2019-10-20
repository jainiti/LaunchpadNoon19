#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};

void insertionAtFront(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}

	node* n=new node(d);
	n->next=head;
	head=n;
}

void insertionAtEnd(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}

	node* n=new node(d);
	tail->next=n;
	tail=n;

}

void print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int length(node* head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}

void insertionAtPos(node* &head,node* &tail,int pos,int d)
{
	if(pos==0)
	{
		insertionAtFront(head,tail,d);
		return;
	}

	else if(pos>=length(head))
	{
		insertionAtEnd(head,tail,d);
		return;
	}
	else
	{
		int p=1;
		node* temp=head;
		while(p<pos)
		{
			temp=temp->next;
			p++;
		}

		node* n=new node(d);
		n->next=temp->next;
		temp->next=n;
	}
}

void deleteAtFront(node* &head,node* &tail)
{
	if(head==NULL)
	{
		return;
	}

	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}
	else 
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
}

void deleteAtEnd(node* &head,node* &tail)
{
	if(head==NULL)
	{
		return;
	}
	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}

	else 
	{
		node* temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		temp->next=NULL;
		delete tail;
		tail=temp;
	}
}

void deleteAtPos(node* &head,node* &tail,int pos)
{
	if(pos==0)
	{
		deleteAtFront(head,tail);
		return;
	}

	else if(pos==length(head)-1)
	{
		deleteAtEnd(head,tail);
		return;
	}

	else if(pos>=length(head))
	{
		return;
	}

	else
	{
		int p=1;
		node* temp=head;
		while(p<pos)
		{
			temp=temp->next;
		}

		node* n=temp->next;
		temp->next=n->next;
		delete n;
	}
}

node* mid(node* head)
{
	if(head==NULL)
	{
		return NULL;
	}

	node* slow=head;
	node* fast=head->next;

	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	return slow;

}

node* search(node* head,int d)
{
	while(head!=NULL)
	{
		if(head->data==d)
		{
			return head;
		}
		head=head->next;
	}

	return NULL;

}

node* searchRec(node* head,int d)
{
	if(head==NULL)
	{
		return head;
	}

	if(head->data==d)
	{
		return head;
	}

	return searchRec(head->next,d);
}

node* reverseLL(node* head)
{
	node* prev=NULL;
	node* curr=head;

	while(curr)
	{
		node* n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}

	return prev;
}



int main()
{
	node* head=NULL;
	node* tail=NULL;


	insertionAtFront(head,tail,5);
	insertionAtFront(head,tail,4);
	insertionAtFront(head,tail,3);
	insertionAtFront(head,tail,2);
	insertionAtFront(head,tail,1);

	insertionAtEnd(head,tail,6);
	insertionAtEnd(head,tail,7);
	insertionAtEnd(head,tail,8);

	insertionAtPos(head,tail,4,11);

	cout<<"LL is"<<endl;
	print(head);

	cout<<"LL after reversal is"<<endl;
	node* newhead=reverseLL(head);
	print(newhead);

	
	// cout<<"mid of LL is "<<mid(head)->data<<endl;

	// int data;
	// cin>>data;

	// node* s=search(head,data);

	// if(s==NULL)
	// {
	// 	cout<<"element absent"<<endl;
	// }
	// else
	// {
	// 	cout<<s->data<<endl;
	// }

	// s=searchRec(head,data);
	// if(s==NULL)
	// {
	// 	cout<<"element absent"<<endl;
	// }
	// else
	// {
	// 	cout<<s->data<<endl;
	// }


	// print(head);

	// deleteAtFront(head,tail);

	// print(head);

	// deleteAtEnd(head,tail);

	// print(head);


	// cout<<"length of linkedlist "<<length(head)<<endl;

	return 0;
}














