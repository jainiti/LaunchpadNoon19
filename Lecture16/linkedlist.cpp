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


node* merge(node* headA,node* headB)
{
	if(!headA)
	{
		return headB;
	}

	if(!headB)
	{
		return headA;
	}

	node* newhead=NULL;
	if(headA->data<=headB->data)
	{
		newhead=headA;
		newhead->next=merge(headA->next,headB);
	}

	else
	{
		newhead=headB;
		newhead->next=merge(headA,headB->next);
	}
	return newhead;
}

node* mergeSort(node* head)
{
	if(head->next==NULL || head== NULL)
	{
		return head;
	}

	node* middle=mid(head);
	node* A=head;
	node* B=middle->next;
	middle->next=NULL;

	A=mergeSort(A);
	B=mergeSort(B);
	node* newHead=merge(A,B);
	return newHead;

}


node* bubbleSort(node* head)
{
	int len=length(head);
	for(int i=0;i<len-1;i++)
	{
		node* curr=head;
		node* prev=NULL;

		while(curr->next && curr)
		{
			node* n=curr->next;

			if(curr->data>n->data)
			{
				if(prev==NULL)
				{
					curr->next=n->next;
					n->next=curr;
					prev=n;
					head=n;
				}
				else
				{
					curr->next=n->next;
					n->next=curr;
					prev->next=n;
					prev=n;
				}
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}

	}
	return head;
}


void createCycle(node* head)
{
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=head->next->next;
}


bool isCyclic(node* head)
{
	node* slow=head;
	node* fast=head;

	while(fast)
	{
		fast=fast->next;
		if(fast)
		{
			fast=fast->next;
			slow=slow->next;

			if(fast==slow)
			{
				return true;
			}
		}
	}

	return false;
}


void breakCycle(node* head)
{
	node* fast=head;
	node* slow=head;

	while(fast)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
		{
			break;
		}
	}

	node* prev=head;
	while(prev->next!=fast)
	{
		prev=prev->next;
	}

	slow=head;

	while(fast)
	{
		fast=fast->next;
		slow=slow->next;
		prev=prev->next;
		if(slow==fast)
		{
			prev->next=NULL;
			break;
		}
		// if(slow!=fast)
		// {
		// 	fast=fast->next;
		// 	slow=slow->next;
		// 	prev=prev->next;
		// }
		// else
		// {

		// }
	}
}



int main()
{
	node* headA=NULL;
	node* tailA=NULL;

	// node* headB=NULL;
	// node* tailB=NULL;

	insertionAtEnd(headA,tailA,1);
	insertionAtEnd(headA,tailA,2);
	insertionAtEnd(headA,tailA,3);
	insertionAtEnd(headA,tailA,4);
	insertionAtEnd(headA,tailA,5);
	insertionAtEnd(headA,tailA,6);
	insertionAtEnd(headA,tailA,7);

	// tailA->next=headA->next->next;

	// insertionAtEnd(headB,tailB,2);
	// insertionAtEnd(headB,tailB,25);
	// insertionAtEnd(headB,tailB,120);
	// insertionAtEnd(headB,tailB,200);


	// cout<<"LL A"<<endl;
	// print(headA);

	createCycle(headA);
	if(isCyclic(headA))
	{
		cout<<"yes"<<endl;
		breakCycle(headA);
		print(headA);
	}
	else
	{
		cout<<"no"<<endl;
	}

	// node* newHead=mergeSort(headA);
	// print(newHead);

	// node* newhead=bubbleSort(headA);
	// print(newhead);

	// cout<<"LL B"<<endl;
	// print(headB);

	// cout<<"after merger"<<endl;
	// node* newhead=merge(headA,headB);
	// print(newhead);

	// node* head=NULL;
	// node* tail=NULL;


	// insertionAtFront(head,tail,5);
	// insertionAtFront(head,tail,4);
	// insertionAtFront(head,tail,3);
	// insertionAtFront(head,tail,2);
	// insertionAtFront(head,tail,1);

	// insertionAtEnd(head,tail,6);
	// insertionAtEnd(head,tail,7);
	// insertionAtEnd(head,tail,8);

	// insertionAtPos(head,tail,4,11);

	// cout<<"LL is"<<endl;
	// print(head);

	// cout<<"LL after reversal is"<<endl;
	// node* newhead=reverseLL(head);
	// print(newhead);

	
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














