// Remove Duplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node * head;
public:

	LinkedList() {}
	~LinkedList() {}

	void push(int value);
	void traverseList();
	void remove(int value);
	void fun();
};

void LinkedList::push(int value)
{
	Node* new_node = new Node;
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;
}

void LinkedList::remove(int value)
{
	int c = 0;
	Node* current = head;
	Node* previous = NULL;
	int count = 0;
	while (current != NULL)
	{
		//	c++;
			//current = current->next;
		if (current != NULL && current->data == value)
		{
			count++;
		}
		if (count > 1 && current->data == value)
		{
			c++;
			current = current->next;
			//previous->next = current->next->next;
			previous->next = current;

			//current = current->next;
			continue;
		}

		previous = current;
		current = current->next;
		//cout << "count " << count << endl;
	}
	//cout << "Loop " << c << endl;
}
void LinkedList::fun()
{
	Node *current = head;
	while (current != NULL)
	{
		remove(current->data);
		current = current->next;
	}


	//	Node* node = new Node;
		//node = head;
}
void LinkedList::traverseList()
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->data << "-->";
		current = current->next;
	}
	cout << "NULL";
	return;
}
int main()
{
	LinkedList list;
	list.push(10);
	list.push(5);
	list.push(10);
	list.push(30);
	list.push(5);
	list.push(30);
	list.push(20);
	list.push(20);
	list.push(20);
	list.push(30);
	list.push(30);
	list.traverseList();
	cout << endl;
	/*list.push(1);
	list.push(1);
	list.push(2);
	list.push(2);
	list.push(3);
	list.push(3);
	list.push(4);

	list.push(4);*/
	list.fun();
	//list.traverseList();
	//cout << "-----" << endl;

	list.traverseList();

	return 0;
}

