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

Node* divide(Node* p)
{
	// Concept of slow and fast pointer is used
	// p is moved once and q is moved twice until q == NULL
	Node* q, *start_second;
	q = p->next->next;
	while (q != NULL){
		p = p->next;
		q = q->next;
		if (q != NULL)
			q = q->next;
	}
	// start_second holds the pointer reference to the 2nd list
	start_second = p->next;
	p->next = NULL;  // made the first list's end == NULL

	return start_second;
}

Node* merge(Node* p1, Node* p2)
{
	Node* q, *start_merged;
	// Giving the head reference of one of the list to the "start_merged"
	if (p1->data <= p2->data){
		start_merged = p1; // start_merged's head pointer will start from p1
		p1 = p1->next;
	}
	else{
		start_merged = p2; // start_merged's head pointer will start from p1
		p2 = p2->next;
	}
	q = start_merged;
	// Now the rest of the list can be traversed and merged with the same merger algorithm
	while((p1 != NULL) && (p2 != NULL)){
		if (p1->data <= p2->data){
			q->next = p1;
			q = q->next;
			p1 = p1->next;
		}
		else{
			q->next = p2;
			q = q->next;
			p2 = p2->next;
		}
	}
	// If there are still remaining nodes in the list, combine it with q
	if (p1 != NULL)
		q->next = p1;
	else
		q->next = p2;

	return start_merged;
}

Node* mergeSort(Node* start)
{
	Node* start_first, *start_second, *start_merged;
	// Base Case
	if (start !=  NULL && start->next != NULL){
		start_first = start;
		start_second = divide(start);
		start_first = mergeSort(start_first);
		start_second = mergeSort(start_second);
		start_merged = mergeSort(start_first, start_second);

		return start_merged;
	}
	else
		return start;
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