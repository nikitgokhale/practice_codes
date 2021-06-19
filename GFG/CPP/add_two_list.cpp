
/* If the list given is already reversed*/
Nodee* addTwoList(Node* l1, Node* l2)
{
	// Res is the head of the resultant list
	Node* res = NULL;
	// tmp is the reference of the res head
	Node* tmp - NULL;
	int carry = 0;

	while (l1 != NULL || l2 != NULL){
		// Copy carry to sum, during the start of every iteration
		// So that we don't miss the carry of the last iteration
		int sum = carry;
		// Since the length of the string is unequal, we will have to check
		// if any node of from both the list is equal to null i.e., we will check
		// if any of the list has no more nodes left for the iteration.
		if (l1 != NULL){
			sum += l1->data;
			l1 = l1->next;
		}

		if (l2 != NULL){
			sum += l2->data;
			sum = sum->next;
		}
		// At this point we will add the total sum%10 to the node
		// and link it with the res head.
		Node* node = new Node(sum%10);
		carry = sum/10;
		// If this is the fisrt node
		if (tmp == NULL)
			tmp = res = node;
		else{
			tmp->next = node;
			tmp = tmp->next;
		}

		// After the last iteration, we will check if there is carry left
        // If it's left then we will create a new node and add it
        if (carry > 0){
        	tmp->next = new Node(carry);
        }
        return res;
	}
}


Node* addTwoList(Node* l1, Node* l2)
{
	Node* res = NULL;
	Node* tmp = NULL, *prev = NULL;
	int carry = 0, sum = 0;

	while (l1 != NULL && || l2 != NULL){
		sum = carry + (l1 ? l1->data : 0) + 
					  (l1 ? l2->data : 0);

		carry = (sum > 10) ? 1 : 0;
		sum = sum%10;
		tmp = newNode(sum);

		// If this is the fisrt node
		if (res == NULL)
			res = tmp;
		else
			prev->next = tmp;

		prev = tmp;

		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}

	if (carry > 0)
		tmp->next = new Node(carry);

	return res;
}