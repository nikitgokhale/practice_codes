//User function Template for C++

//Function which adds two linked lists of same size.
Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
	// Your code here
	Node* tmp;
	int car = 0;
	
	if (head1 == NULL || head2 == NULL)
	    return NULL;
	
	tmp = addSameSize(head1->next, head2->next, carry);
	car = (head1->data) + (head2->data) + (*carry);
	head2->data = (car)%10;
	(*carry) = (car)/10;
	return head2;
} 

//Function to add remaining carry.
void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
	// Your code here
	if (head1 == curr)
	    return;
	int car;
	addCarryToRemaining(head1->next, curr, carry, result);
	if (head1->next == curr)
	    head1->next = *result;
	    
	car = (head1->data + *carry);
	head1->data = car%10;
	*(carry) = (car)/10;
	*result = head1;
}