#include<iostream>
#include<time.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class LinkedList
{

	Node* head = NULL;
public:
	~LinkedList()
	{
		cleanUp();
		//printNodes();
	}
	void cleanUp();
	void printNodes();
	void insert(int data);
	void insertEnd(int data);
	void insertAt(int data, int pos);
	void pop();
	void popEnd();
	void deleteAt(int pos);
	void deleteValue(int val);
};
/*clean Up code*/
void LinkedList::cleanUp()
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
	temp = NULL;
}
/* insert at begining of linked list*/
void LinkedList::insert(int data)
{
	Node* n = new Node;
	n->data = data;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
		return;
	}
	n->next = head;
	head = n;
}
/*print Nodes*/
void LinkedList::printNodes()
{
	Node* current = head;
	if (current == NULL)
	{
		cout << "List is already Empty" << endl;
		return;
	}
	/*	if(current->next == NULL)
			cout<<"NULL"<<endl;
	*/	while (current != NULL)
	{
		cout << current->data << "-->";
		current = current->next;
	}
	cout << "NULL" << endl;
}

/*insert at End of list*/
void LinkedList::insertEnd(int data)
{
	Node* current = head;
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	if (current == NULL)
	{
		new_node = head;
		return;
	}
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;
}

/* insert node at particular position */
void LinkedList::insertAt(int data, int pos)
{
	Node* current = head;
	int count = 0;
	Node* pre = current;
	while (current != NULL && count != pos)
	{
		count++;
		pre = current;
		current = current->next;
	}
	if (count != pos)
	{
		cout << "Index out of bounds" << endl;
		return;
	}
	Node* new_node = new Node;
	new_node->data = data;
	pre->next = new_node;
	new_node->next = current;
}
/* delete node from the head*/
void LinkedList::pop()
{
	if (head == NULL)
	{
		cout << "List is already empty...!!!";
		return;
	}
	Node* temp = head;
	head = temp->next;
	delete temp;
}

/* delete node from last of list*/
void LinkedList::popEnd()
{
	Node* current = head;
	Node* pre = head;
	while (current->next != NULL)
	{
		pre = current;
		current = current->next;
	}
	pre->next = NULL;
	delete current;
}

/* delete node by index*/
void LinkedList::deleteAt(int pos)
{
	Node* current = head;
	Node* pre = head;
	int count = 0;
	if (pos == 0)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	while (current != NULL && count != pos)
	{
		count++;
		pre = current;
		current = current->next;
	}

	if (count != pos)
	{
		cout << "Index out of Bounds" << endl;
		return;
	}
	Node* temp = current;
	current = current->next;
	pre->next = current;
	delete temp;
}

/* delete node by its value*/
void LinkedList::deleteValue(int val)
{
	Node* current = head;
	Node* pre = head;
	if (current->data == val)
	{
		Node* temp = current;
		current = current->next;
		head = current;
		delete temp;
		return;
	}
	while (current->data != val)
	{
		pre = current;
		current = current->next;
	}
	Node* temp = current;
	current = current->next;
	delete temp;
	pre->next = current;
}
int main()
{

	cout << "Welcome to Linked List Operation..." << endl;
	cout << "Lets have some adventures...!!!" << endl;

	LinkedList list;
	srand(time(NULL));
	int lower = 10;
	int upper = 100;
	int temp;
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % (lower + upper - 1);
		list.insert(num);

	}
	//	list.insert(10);
	//	list.insert(20);
	list.printNodes();
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % (lower + upper - 1);
		list.insertEnd(num);
		temp = num;
	}
	list.insertAt(20, 50);
	//	list.insertEnd(40);
	list.printNodes();
	//list.pop();
	list.printNodes();
	list.popEnd();
	list.printNodes();
	list.deleteAt(20);
	list.printNodes();
	cout << "Temp " << temp << endl;
	cout << "enter node to be deleted " << endl;
	cin >> temp;
	list.deleteValue(temp);
	list.printNodes();
	return 0;
}