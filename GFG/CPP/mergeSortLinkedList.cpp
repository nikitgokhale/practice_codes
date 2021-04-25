#include<stdc++.h>
#include<iostream>

using namespace std;

/* TYPEDEFS and STRUCTS*/
struct Node {
	int data;
	Node* next;
};

/* FUNCTION DECLARATIONS */
Node* merge(Node*& head1, Node*& head2);
Node* createLinkedList(Node* head);
Node* addAtBeg(Node* head, int data);
Node* addAtEnd(Node* head, int data);
void  mergeSort(Node*& head);
void  printList(Node* head);
int   getLen(Node* head);

/* FUNCTION DEFINTIONS */
int getLen(Node* head)
{
	Node* curr = head;
	int count = 0;

	for (; curr != NULL; curr = curr->next) {
		count++;
	}
	return count;
}

void printList(Node* head)
{
	Node* curr = head;

	for (; curr != NULL; curr = curr->next) {
		cout << curr->data << " -> ";
	}
	cout << "NULL" << endl;
}

Node* addAtBeg(Node* head, int data)
{
	Node* start = new Node;
	start->data = data;
	if (head == NULL) {
		start->next = head;
		head = start;
		return head;
	}
	start->next = head;
	head = start;
	return start;
}

Node* addAtEnd(Node* head, int data)
{
	if (head == NULL) {
		head = addAtBeg(head, data);
		return head;
	}

	Node* tmp = new Node;
	tmp->data = data;
	Node* ptr = head;

	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->next = NULL;
	return head;
}

Node* createLinkedList(Node* head)
{
	int nodes, data;
	cout << "Enter the number of nodes: ";
	cin >> nodes;
	if (nodes == 0)
		return head;
	cout << "Enter the numbers to be inserted: ";
	cin >> data;
	head = addAtBeg(head, data);
	for (int i = 1; i < nodes; i++) {
		cout << "Enter the numbers to be inserted: ";
		cin >> data;
		head = addAtEnd(head, data);
	}
	return head;
}

Node* merge(Node*& head1, Node*& head2)
{
	Node* newHead;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	if (head1->data < head2->data) {
		newHead = head1;
		newHead->next = merge(head1->next, head2);
	}
	else {
		newHead = head2;
		newHead->next = merge(head1, head2->next);
	}
	return newHead;
}


void mergeSort(Node*& head)
{
	if (head->next != NULL) {
		Node* head1 = new Node;
		Node* head2 = head;
		int len = getLen(head);
		for (int i = 0; i < len / 2; i++) {
			head1 = head2;
			head2 = head2->next;
		}
		head1->next = NULL;
		head1 = head;
		mergeSort(head1);
		mergeSort(head2);
		head = merge(head1, head2);
	}
}


int main()
{
	Node* headNode = NULL;

	headNode = createLinkedList(headNode);
	printList(headNode);
	mergeSort(headNode);
	cout << "Sorted Linked List: ";
	printList(headNode);
	cout << endl;

	return 0;
}