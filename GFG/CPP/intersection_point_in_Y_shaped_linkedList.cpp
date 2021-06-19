
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int count1 = 0;
    int count2 = 0;
    Node* tmp1 = head1;
    Node* tmp2 = head2;
    
    while (tmp1){
        tmp1 = tmp1->next;
        count1++;
    }
    while (tmp2){
        tmp2 = tmp2->next;
        count2++;
    }
    
    int newStart = 0;
    
    if (count1 > count2){
        newStart = count1 - count2;
        while (newStart--)
            head1 = head1->next;            
    }
    else{
        newStart = count2 - count1;
        while (newStart--)
            head2 = head2->next;
    }
    
    while (head1 && head2){
        if (head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}
