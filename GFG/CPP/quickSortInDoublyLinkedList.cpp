#include <bits/stdc++.h>

using namespace std;

/* a node of doubly linked list */
class Node {

public:
    int data;
    Node *next_node;
    Node *prev_node;

};

/* Function to swap two elements */
void swap ( int* a, int* b ) 
{ 
    int t = *a; *a = *b; *b = t; 
}

// Function to find last node of the linked list
Node *lastNode(Node *root)
{
    while (root && root->next_node)
        root = root->next_node;

    return root;
}

/* Arrange all the elements of the linked list as per the pivot element */
Node* partition(Node *head, Node *tail)
{
    // Here we are not exchanging the nodes,
    // rather we are exchanging the data
    // to avoid the overhead to move nodes
    int tmpData  = tail->data;
    Node* tmpNode = head->prev;
    
    for (Node* j = head; j != tail; j = j->next){
        if (j->data <= tmpData){
            tmpNode = (tmpNode == NULL)? head : tmpNode->next;
            swap(&(tmpNode->data), &(j->data));
        }
    }
    tmpNode = (tmpNode == NULL)? head : tmpNode->next;
    swap(&(tmpNode->data), &(tail->data));
    
    return tmpNode;
}

void swap1(Node* a, Node* b)
{
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
    return;
}

// This is an alternate solution to the partition method.
// This method also deals with the swapping of the data, rather than the complete node.
// This can be done in doubly linked list easily because, we have both the previous and the next
// node, we don't need an extra pointer to map the previous node.
Node* Partition(Node* head, Node* tail)
{
    Node* pivot = head;
    Node* curr = head;
    Node* end = tail;

    // Moving the current node till the end
    while (curr != end){
        // If the current node's data is smaller than the end node
        // Swap the data of the pivot node and the current node
        // This is to bring the data smaller than the pivot to
        // the left side and for the data larger than the pivot to the
        // right side of the pivot node
        if (curr->data <= end->data){
            swap1(pivot, curr);
            pivot = pivot->next;
        }
        curr = curr->next;
    }
    swap1(pivot, end);
    return pivot;
}

/* Recursive implementation of quicksort for linked list */
void _quickSort(Node* l, Node *h)
{
    if (h != NULL && l != h && l != h->next_node)
    {
        Node *p = partition(l, h);
        _quickSort(l, p->prev_node);
        _quickSort(p->next_node, h);
    }
}

// Main function: It calls the _quickSort() method

void quickSort(Node *head)
{
    // Find the last node
    Node *h = lastNode(head);
    // Call recursive QuickSort
    _quickSort(head, h);
}

// Function to print the elements of array
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next_node;
    }
    cout << endl;
}

/* Function of insertion in the beginning*/
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node;  /* allocate node */
    new_node->data = new_data;
    /* Here, prev is always NULL */
    new_node->prev_node = NULL;
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* change prev(head) to new node*/
    if ((*head_ref) != NULL) (*head_ref)->prev_node = new_node;
    /* Now, move the head pointing to the new node */
    (*head_ref) = new_node;
}

/* Driver code */
int main()
{
    Node *a = NULL;

    push(&a, 7);

    push(&a, 25);

    push(&a, 6);

    push(&a, 4);

    push(&a, 25);

    cout << "Linked List before sorting \n";

    printList(a);

    quickSort(a);

    cout << "Linked List after sorting \n";

    printList(a);

    return 0;
}