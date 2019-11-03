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


void mirror(node* root)
{
	if(root==NULL)
	{
		return;
	}

	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

int pre[]={1,2,4,5,3,6,7};
int i=0;

node* buildBinaryTree(int in[],int s,int e)
{
	if(s>e)
	{
		return NULL;
	}

	node* root=new node(pre[i]);
	int key=pre[i];
	i++;

	int j=-1;
	for(int k=s;k<=e;k++)
	{
		if(key==in[k])
		{
			j=k;
			break;
		}
	}

	root->left=buildBinaryTree(in,s,j-1);
	root->right=buildBinaryTree(in,j+1,e);

	return root;

}


bool isBST(node* root,int min=INT_MIN,int max=INT_MAX)
{
	if(!root)
	{
		return true;
	}

	if((min<=root->data && root->data<max)&&isBST(root->left,min,root->data)&& isBST(root->right,root->data+1,max))
	{
		return true;
	}
	return false;
}

node* insertInBST(node* root,int d)
{
	if(root==NULL)
	{
		node* r=new node(d);
		return r;
	}


	if(root->data<d)
	{
		root->right=insertInBST(root->right,d);
	}
	else
	{
		root->left=insertInBST(root->left,d);
	}

	return root;
}


node* buildBST()
{
	int data;
	cin>>data;

	node* root=NULL;

	while(data!=-1)
	{
		root=insertInBST(root,data);
		cin>>data;
	}

	return root;
}

node* arrToBST(int arr[],int s,int e)
{
	if(s>e)
	{
		return NULL;
	}

	int mid=(s+e)/2;
	node* root=new node(arr[mid]);
	root->left=arrToBST(arr,s,mid-1);
	root->right=arrToBST(arr,mid+1,e);

	return root;
}

bool isBalanced(node* root)
{
	if(!root)
	{
		return true;
	}

	int heightdiff=abs(height(root->left)-height(root->right));

	bool isLeftBalanced=isBalanced(root->left);
	bool isRightBalanced=isBalanced(root->right);

	if(heightdiff<=1 && isLeftBalanced && isRightBalanced)
	{
		return true;
	}
	return false;
}

class Pair1
{
public:
	int Height;
	bool Balanced;
};


Pair1 optimisedBalancing(node* root)
{
	if(!root)
	{
		Pair1 p;
		p.Height=0;
		p.Balanced=true;
		return p;
	}

	Pair1 left=optimisedBalancing(root->left);
	Pair1 right=optimisedBalancing(root->right);

	Pair1 p;

	p.Height=max(left.Height,right.Height)+1;

	if(abs(left.Height-right.Height)<=1 && left.Balanced && right.Balanced)
	{
		p.Balanced=true;
	}
	else
	{
		p.Balanced=false;
	}

	return p;

}


node* levelOrderInput()
{
	int d;
	cout<<"Enter data of root"<<endl;
	cin>>d;

	node* root=NULL;
	if(d==-1)
	{
		return root;
	}

	root=new node(d);
	queue<node*>q;
	q.push(root);

	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();

		int c1,c2;
		cout<<"enter left and right children of "<<temp->data<<endl;
		cin>>c1>>c2;

		if(c1!=-1)
		{
			temp->left=new node(c1);
			q.push(temp->left);
		}

		if(c2!=-1)
		{
			temp->right=new node(c2);
			q.push(temp->right);
		}
	}

	return root;

}


class linkedList
{
public:
	node* head;
	node* tail;
};



linkedList BSTtoLL(node* root)
{
	if(root==NULL)
	{
		linkedList l;
		l.head=NULL;
		l.tail=NULL;
		return l;
	}

	else if(!root->left && !root->right)
	{
		linkedList l;
		l.head=root;
		l.tail=root;
		return l;
	}

	else if(root->left && !root->right)
	{
		linkedList left=BSTtoLL(root->left);
		left.tail->right=root;
		linkedList l;
		l.head=left.head;
		l.tail=root;
		return l;
	}

	else if(!root->left && root->right)
	{
		linkedList right=BSTtoLL(root->right);
		root->right=right.head;
		linkedList l;
		l.head=root;
		l.tail=right.tail;
		return l;
	}
	else
	{
		linkedList left=BSTtoLL(root->left);
		linkedList right=BSTtoLL(root->right);

		left.tail->right=root;
		root->right=right.head;
		linkedList l;

		l.head=left.head;
		l.tail=right.tail;
		return l;

	}
}


void print(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
}



int main()
{
	// node* root=createTree();

	// int in[]={4,2,5,1,6,3,7};
	// int n=sizeof(in)/sizeof(int);

	// node* root=buildBinaryTree(in,0,n-1);

	// node* root=buildBST();

	// cout<<"preOrder traversal is"<<endl;
	// preOrder(root);
	// cout<<endl;


	// cout<<"inOrder traversal is"<<endl;
	// inOrder(root);
	// cout<<endl;


	// cout<<"postOrder traversal is"<<endl;
	// postOrder(root);
	// cout<<endl;


	// cout<<"Height of tree is"<<height(root)<<endl;
	// cout<<"Count of nodes are "<<count(root)<<endl; 


	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(arr)/sizeof(int);

	node* root=arrToBST(arr,0,n-1);

	// cout<<"levelOrder traversal is"<<endl;
	// levelOrder(root);
	// cout<<endl;


	// node* root=levelOrderInput();
	// cout<<"levelOrder traversal is"<<endl;
	// levelOrder(root);
	// cout<<endl;


	linkedList l=BSTtoLL(root);
s



	// if(isBST(root))
	// {
	// 	cout<<"It is BST"<<endl;
	// }
	// else
	// {
	// 	cout<<"No it is not BST"<<endl;
	// }

	// mirror(root);

	// cout<<"levelOrder traversal is"<<endl;
	// levelOrder(root);
	// cout<<endl;



	return 0;
}


























