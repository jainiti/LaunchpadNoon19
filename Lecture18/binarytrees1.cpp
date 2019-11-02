#include<iostream>
#include<queue>

using namespace std;

class node
{
 public:
 	int data;
 	node* left;
 	node* right;

 	node(int d)
 	{
 		data=d;
 		left=NULL;
 		right=NULL;
 	}
};

node* createTree()
{
	int data;
	cin>>data;

	if(data==-1)
	{
		return NULL;
	}

	node* root=new node(data);
	cout<<"enter left child of "<<data<<endl;
	root->left=createTree();
	cout<<"enter right child of "<<data<<endl;
	root->right=createTree();

	return root;
}

void preOrder(node* root)
{
	if(!root)
	{
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root)
{
	if(!root)
	{
		return;
	}

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(node* root)
{
	if(!root)
	{
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int count(node* root)
{
	if(!root)
	{
		return 0;
	}

	int leftCount=count(root->left);
	int rightCount=count(root->right);

	return 1+leftCount+rightCount;
}


int height(node* root)
{
	if(!root)
	{
		return 0;
	}

	int leftHeight=height(root->left);
	int rightHeight=height(root->right);

	return max(leftHeight,rightHeight)+1;
}


void levelOrder(node* root)
{
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		if(!temp)
		{
			if(!q.empty())
			{
				cout<<endl;
				q.push(NULL);
			}
		}
		else
		{
			cout<<temp->data<<" ";
			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}


int diameter(node* root)
{
	if(!root)
	{
		return 0;
	}

	int op1=height(root->left)+height(root->right);
	int op2=diameter(root->left);
	int op3=diameter(root->right);

	return max(op1,max(op2,op3));

}

class Pair
{
public:
	int Diameter;
	int Height;
};


Pair fastDiameter(node* root)
{
	Pair p;
	if(!root)
	{
		p.Diameter=0;
		p.Height=0;
		return p;
	}

	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);

	int op1=left.Height+right.Height;
	int op2=left.Diameter;
	int op3=right.Diameter;

	p.Diameter=max(op1,max(op2,op3));
	p.Height=max(left.Height,right.Height)+1;
	return p;
}




int main()
{
	node* root=createTree();


	cout<<"preOrder traversal is"<<endl;
	preOrder(root);
	cout<<endl;


	cout<<"inOrder traversal is"<<endl;
	inOrder(root);
	cout<<endl;


	cout<<"postOrder traversal is"<<endl;
	postOrder(root);
	cout<<endl;


	cout<<"Height of tree is"<<height(root)<<endl;
	cout<<"Count of nodes are "<<count(root)<<endl; 

	cout<<"levelOrder traversal is"<<endl;
	levelOrder(root);
	cout<<endl;


	return 0;
}


























