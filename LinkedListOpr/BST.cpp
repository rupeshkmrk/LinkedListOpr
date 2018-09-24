#include <iostream>
#include <cstdlib>
#include<queue>
#include<time.h>
#include<stack>
using namespace std;

class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		int data;
	};
	tree_node* root;
public:
	~BinarySearchTree()
	{
		//free(root);
	}
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(int);
	void remove(int);
	int CountNodes(tree_node*);
	void print_size();
	int maxDepth(tree_node*);
	void print_maxDepth();
	int maxValue(tree_node*);
	void print_maxValue();
	void print_minValue();
	int minValue(tree_node*);
	void print_LevelOrder();
	void printLevelOrder(tree_node*);
};

void BinarySearchTree::insert(int d)
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	if (isEmpty()) root = t;
	else
	{
		tree_node* curr;
		curr = root;
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else if (t->data > parent->data)
			parent->right = t;
		else {

			cout << "duplicate value not allowed " << t->data << endl;
			delete t;
		}
	}
}
void BinarySearchTree::print_size()
{
	int n;
	n = CountNodes(root);
	cout << n << endl;
}

int BinarySearchTree::CountNodes(tree_node* n)
{
	int c = 1;
	if (n == NULL)
		return 0;
	else
	{
		c += CountNodes(n->left);
		c += CountNodes(n->right);
		return c;
	}
}
void BinarySearchTree::print_maxDepth()
{
	int n;
	n = maxDepth(root);
	cout << n << endl;
}
int BinarySearchTree::maxDepth(tree_node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}
void BinarySearchTree::print_maxValue()
{
	int n;
	n = maxValue(root);
	cout << n << endl;
}
int BinarySearchTree::maxValue(tree_node* node)
{
	if (node == nullptr)
		throw "BT is empty";

	int max = node->data;
	for (tree_node* left = node; left != NULL; left = left->left)
	{
		if (left->data > max)
			max = left->data;
	}

	for (tree_node* right = node; right != NULL; right = right->right)
	{
		if (right->data > max)
			max = right->data;
	}

	return max;
}
void BinarySearchTree::print_minValue()
{
	int n;
	n = minValue(root);
	cout << n << endl;
}

int BinarySearchTree::minValue(tree_node* node)
{
	tree_node* current = node;

	while (current->left != NULL) {
		current = current->left;
	}
	return(current->data);
}
void BinarySearchTree::print_LevelOrder()
{

	printLevelOrder(root);

}
void BinarySearchTree::printLevelOrder(tree_node *node)
{
	if (node == NULL)  return;

	queue<tree_node *> q;

	q.push(root);

	while (1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
			break;

		while (nodeCount > 0)
		{
			tree_node *node = q.front();
			cout << node->data << " ";
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			nodeCount--;
		}
		cout << endl;
	}
}

void BinarySearchTree::remove(int d)
{
	bool found = false;
	if (isEmpty())
	{
		cout << " This Tree is empty! " << endl;
		return;
	}
	tree_node* curr;
	tree_node* parent = NULL;
	curr = root;
	while (curr != NULL)
	{
		if (curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << " Data not found! " << endl;
		return;
	}



	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
		&& curr->right == NULL))
	{
		if (curr->left == NULL && curr->right != NULL)
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}

	if (curr->left == NULL && curr->right == NULL)
	{
		if (parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;
		return;
	}

	if (curr->left != NULL && curr->right != NULL)
	{
		tree_node* chkr;
		chkr = curr->right;
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else
		{


			if ((curr->right)->left != NULL)
			{
				tree_node* lcurr;
				tree_node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				tree_node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}

		}
		return;
	}

}

void BinarySearchTree::print_inorder()
{
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->data << " ";
		if (p->right) inorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_preorder()
{
	preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
	if (p != NULL)
	{
		cout << " " << p->data << " ";
		if (p->left) preorder(p->left);
		if (p->right) preorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_postorder()
{
	postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		cout << " " << p->data << " ";
	}
	else return;
}

int main()
{
	//vector<int> vect;
	//vector<int> ::iterator itr;
	BinarySearchTree b;
	int ch, tmp, tmp1, n;
	srand(time(NULL));
	int lower = 1;
	int upper = 50;
	for (int i = 0; i < 50; i++)
	{
		int num = (rand() %
			(upper - lower + 1)) + lower;
		//cout << "NUM " << num;
		//itr = find(vect.begin(), vect.end(), num);
		//if (itr == vect.end())
		//{
		b.insert(num);
		//}
		//else
		//{
		///i--;
		//}
		//vect.push_back(num);
		//b.insert(num);
	}
	while (1)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		//cout << " 1. Insertion" << endl;
		cout << " 2. Size" << endl;
		cout << " 3. MaxDepth " << endl;
		cout << " 4. maxValue " << endl;
		//cout<<" 5. hasPathSum "<<endl;
		cout << " 5. Level order traversal " << endl;
		// cout<<" 7. Boundary Order traversal "<<endl;
		cout << " 6. Pre Order traversal  (Root, Left, Right) " << endl;
		cout << " 7. In Order traversal (Left, Root, Right) " << endl;
		cout << " 8. Post Order traversal (Left, Right, Root) " << endl;
		cout << " 9. Delete " << endl;
		//cout<<" 12. Print Height and depth "<<endl;

		cout << " 10. minValue " << endl;
		cout << " 0. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> ch;
		switch (ch)
		{

			/*case 1: cout << " Enter Number to be inserted : ";
				cin >> tmp;
				b.insert(tmp);
				break;*/
		case 7: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_inorder();
			break;
		case 6: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_preorder();
			break;
		case 8: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " --------------------" << endl;
			b.print_postorder();
			break;
		case 9: cout << " Enter data to be deleted : ";
			cin >> tmp1;
			b.remove(tmp1);
			break;
		case 0: exit(0);
			//return 0;
			break;
		case 2: cout << " Numbers of nodes: ";
			b.print_size();
			break;
		case 3: cout << endl;
			cout << " Maximum depth is: ";
			b.print_maxDepth();;
			break;
		case 4: cout << endl;
			cout << " Maximum value: ";
			b.print_maxValue();
			break;
		case 10: cout << endl;
			cout << " Minimum value: ";
			b.print_minValue();
			break;
		case 5: cout << " Level order traversal " << endl;

			b.print_LevelOrder();
			break;
		default:
			cout << "Wrong Choice " << endl;
			break;
		}
	}
}
