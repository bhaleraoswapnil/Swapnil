//Binary Tree Programs.
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	
	Node():left(nullptr),right(nullptr),data(0)
	{
	}
	Node(int val) :left(nullptr), right(nullptr), data(val)
	{
	}
};

class BST
{
private:
	Node* mRoot;
	
	void InOrder(Node* root);
	Node* SearchNode(int val,Node* root);
	bool CheckBST(Node*root, int min, int max);
	int LowestCommonAncestorBST(Node*root,int val_1, int val_2);
public:
	BST():mRoot(nullptr){}
	Node* GetRoot() { return mRoot; }
	Node* InsertNode(int val, Node* root);
	
	void InOrder();
	bool SearchData(int val);
	bool CheckBST();
	void CreateTree();
	int LowestCommonAncestorBST(int val_1,int val_2);

};
void BST::CreateTree()
{
	mRoot = new Node(50);														//50
	mRoot->left = new Node(25);											//25			  75
	mRoot->right = new Node(75);								   //25      28       54      80
	mRoot->left->left = new Node(25);
	mRoot->left->right = new Node(28);
	mRoot->right->left = new Node(54);
	mRoot->right->right = new Node(80);

}

int BST::LowestCommonAncestorBST(Node*root, int val_1, int val_2)
{
	if (root->data > val_1 && root->data > val_2)
	{
		return LowestCommonAncestorBST(root->left, val_1, val_2);
	}
	else if (root->data < val_1 && root->data < val_2)
	{
		return LowestCommonAncestorBST(root->right, val_1, val_2);
	}
	else
	{
		return root->data;
	}
}
int BST::LowestCommonAncestorBST(int val_1, int val_2)
{
	return LowestCommonAncestorBST(mRoot, val_1, val_2);
}
bool BST::CheckBST()
{
	return CheckBST(mRoot, INT_MIN, INT_MAX);
}

bool BST::CheckBST(Node* root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->data < min || root->data > max)
	{
		return false;
	}

	return CheckBST(root->left, min, root->data) && CheckBST(root->right, root->data, max);
}
void BST::InOrder()
{
	InOrder(mRoot);
}

void BST::InOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}

Node* BST::SearchNode(int val, Node* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->data > val)
	{
		return SearchNode(val, root->left);
	}
	else if (root->data < val)
	{
		return SearchNode(val, root->right);
	}
	else
	{
		return root;
	}
}
bool BST::SearchData(int val)
{
	if (SearchNode(val, mRoot) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node* BST::InsertNode(int val, Node* root)
{
	if (mRoot == nullptr)
	{
		mRoot = new Node(val);
		return mRoot;
	}
	if (root == nullptr)
	{
		return new Node(val);
	}

	if (root->data > val)
	{
		root->left = InsertNode(val, root->left);
	}
	else
	{
		root->right = InsertNode(val, root->right);
	}
	return root;
}
int main()
{
	cout << "BST..." << endl;
	BST obj1;
	obj1.InsertNode(15, obj1.GetRoot());
	obj1.InsertNode(10, obj1.GetRoot());
	obj1.InsertNode(20, obj1.GetRoot());
	obj1.InsertNode(22, obj1.GetRoot());
	obj1.InsertNode(18, obj1.GetRoot());
	obj1.InsertNode(25, obj1.GetRoot());
	obj1.InsertNode(3, obj1.GetRoot());
	obj1.InsertNode(2, obj1.GetRoot());
	obj1.InsertNode(0, obj1.GetRoot());
	obj1.InsertNode(320, obj1.GetRoot());
	obj1.InsertNode(22, obj1.GetRoot());
	obj1.InsertNode(29, obj1.GetRoot());
	obj1.InsertNode(-20, obj1.GetRoot());
	obj1.InsertNode(-20, obj1.GetRoot());


	obj1.InOrder();

	cout <<endl <<obj1.SearchData(29)<<endl;

	BST obj2;
	obj2.CreateTree();
	obj2.InOrder();
	cout << "\n check BST == " << obj2.CheckBST() << endl;
	cout << "\n LCA for BST == " << obj2.LowestCommonAncestorBST(25, 28);
	
	return 0;
}
