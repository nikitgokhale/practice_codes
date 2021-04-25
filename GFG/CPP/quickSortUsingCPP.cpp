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

node* getLast(node* curr)
{
    while (curr != NULL && curr->next != NULL)
        curr = curr->next;
        
    return curr;
}

node* partition(node* head, node* tail,
                node** newHead,
                node** newTail)
{
    node* pivot = tail;
    node* prev = NULL, *curr = head, *end = pivot;
    
    while (curr != pivot){
        if (curr->data < pivot->data){
            if ((*newHead) == NULL)
                (*newHead) = curr;
                
            prev = curr;
            curr = curr->next;
        }
        else{
            if (prev)
                prev->next = curr->next;
            node* tmp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = curr;
            curr = tmp;
        }
    }
    
    if ((*newHead) == NULL)
        (*newHead) = pivot;
        
    (*newTail) = tail;
    
    return pivot;
}


node* quickSortUtil(node* head, node* tail)
{
    if (!head || head == tail)
        return head;
        
    node* newHead = NULL, *newTail = NULL;
    
    node* pivot = partition(head, tail, &newHead, &newTail);
    
    if (newHead != pivot){
        node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        
        newHead = quickSortUtil(newHead, tmp);
        
        tmp = getLast(newHead);
        tmp->next = pivot;
    }
    
    pivot->next = quickSortUtil(pivot->next, newTail);
    
    return newHead;
}

void quickSort(struct node **headRef) 
{
    (*headRef) = quickSortUtil(*headRef, getLast(*headRef));
    return;
}