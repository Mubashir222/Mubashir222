// A complete working C++ program to demonstrate
// all insertion methods on Linked List
#include <iostream>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void Begining(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		cout<<"The given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	Node* new_node = new Node();

	/* 3. put in the data */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}
void append(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	Node *last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be
	the last node, so make next of
	it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty,
	then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
	{
		last = last->next;
	}

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}
void deleteNode(Node** head_ref,int key){
    Node* temp = *head_ref;
    Node* prev = NULL;
	if(temp != NULL && temp->data != key){
		*head_ref = temp->next;
		delete temp;
		return;
	}
	if (temp == NULL){
		return;
		prev->next = temp->next;
		delete temp;
	}
}
void deletehead(Node** headref){
    Node* temp = *headref;
    *headref = temp->next;
    delete temp;
}
int getCount(Node* head){
	int count = 0;
	Node* current = head;
	while (current != NULL){
		count++;
		current = current->next;
	}
	return count;
}
void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}
int main(){
	Node* head = NULL;
	append(&head, 6);
	Begining(&head, 7);
	Begining(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	Begining(&head,9);
	cout<<"Count of code is: "<<getCount(head)<<endl;
	cout<<"Created Linked list is: ";
	printList(head);
    cout<<"\nAfter delete the head: ";
	deleteNode(&head,1);
    printList(head);
	cout<<endl;
	cout<<"Now Count of code is: "<<getCount(head);
	return 0;
}