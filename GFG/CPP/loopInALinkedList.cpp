#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

/* Function Declaration */
void loopHere(Node* head, Node* tail, int position);
bool isLoop(Node* head);
int length(Node* head);
void removeLoop(Node* head);
void display(struct Node *head);
struct Node* create(struct Node* head);

/* Fucntion Definition */
void loopHere(Node* head, Node* tail, int position)
{
	if (position == 0)
		return;

	Node* walk = head;
	for (int i = 0; i < position; i++) {
		walk = walk->next;
	}
	tail->next = walk;
}


bool isLoop(Node* head)
{
	if (!head)
		return false;

	Node *fast = head->next;
	Node* slow = head;

	while (fast != slow)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return true;
}

int length(Node* head)
{
	int ret = 0;
	while (head != NULL) {
		ret++;
		head = head->next;
	}
	return ret;
}

void removeLoop(Node* head)
{
	// code here
	// just remove the loop without losing any nodes
	Node* fast = head;
	Node* slow = head;
	if (head == NULL || head->next == NULL)
		return;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow == head) {
		while (slow->next != head) {
			slow = slow->next;
		}
		slow->next = NULL;
	}
	if (slow == fast) {
		slow = head;
		while (slow->next != fast->next) {
			if (slow == fast->next)
				fast->next = NULL;
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}
}

void display(struct Node* head)
{
	Node* p;
	if (head == NULL)
	{
		cout << "The List is empty!" << endl;
		return;
	}
	p = head;
	cout << "The List is: ";
	while (p != NULL)
	{
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << "NULL" << endl;
}

struct Node* create(struct Node* head)
{

	struct Node *p, *q;
	int nodes, item;
	cout << "Enter the number of nodes to be added: ";
	cin >> nodes;
	if (nodes == 0)
	{
		cout << "Enter a valid input!" << endl;
		return head;
	}
	cout << "Enter the elements to be added in the list: ";
	cin >> item;
	p = new Node(item);
	p->next = NULL;
	head = p;
	for (int i = 1; i < nodes; i++)
	{
		cout << "Enter the elements to be added in the list: ";
		cin >> item;
		q = new Node(item);
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	return head;
}

int main()
{
	Node *head, *tail, *ptr;
	head = create(head);
	display(head);
	ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	tail = ptr;
	int pos;
	cout << "Enter the postion where you want to loop the list: ";
	cin >> pos;
	loopHere(head, tail, pos);

	removeLoop(head);

	if (isLoop(head)) {
		cout << "0";
	}
	else
		cout << "1";

	cout << "Hello World" << endl;
	return 0;
}