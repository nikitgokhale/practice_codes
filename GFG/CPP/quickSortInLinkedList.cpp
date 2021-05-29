/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
node* getTail(node* curr)
{
    while (curr != NULL && curr->next != NULL)
        curr = curr->next;
    return curr;
}

node* Partition(node* head, node* tail, node** newHead, node** newTail)
{
    node* pivot = tail;
    node* curr = head, *prev = NULL, *end = tail;
    
    // Traversing through the list, until we reach the pivot node
    while (curr != pivot){
        // if curr's data is smaller than pivot's data
        // If no newHead, make curr as newHead and traverse forward
        if (curr->data < pivot->data){
            if ((*newHead) == NULL)
                (*newHead) = curr;
            prev = curr;
            curr = curr->next;
        }
        else{ // If the curr's data is greater than the pivot's data
              // move the curr node to the end of the list
              // and moving curr to it's next node
            if (prev)
                prev->next = curr->next;
            
            node* tmp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = curr;
            curr = tmp;
        }
    }
    // If pivot's data is the smallest element in the list
    // Then pivot becomes the newHead
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    // Update end as the newTail
    (*newTail) = end;
    
    return pivot;
}

node* quickSortUtil(node* head, node* tail)
{
    // Base Case
    if (!head || head == tail)
        return head;
    
    node* newHead = NULL, *newTail = NULL;
    // Perform a partition on the list
    // newHead and newTail will be updated
    node* pivot = Partition(head, tail, &newHead, &newTail);
    
    if (newHead != pivot) {
        node* tmp = newHead;
        // Travers to the prev node of the pivot node and seperate it from 
        // the other list to sort the left part recursively
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        // Recur through the left part of the pivot and sort it
        newHead = quickSortUtil(newHead, tmp);
        // Update the last of the list to the left half of the pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    // Recur the list after the pivot element to sort the right half of the list
    pivot->next = quickSortUtil(pivot->next, newTail);
    
    return newHead;
}

void quickSort(struct node **headRef) {
    (*headRef) = quickSortUtil(*headRef, getTail(*headRef));
    return;
}