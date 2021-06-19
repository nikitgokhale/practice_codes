/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // Your code here
    if (!head)
        return -1;
        
    int k = 0;
    Node* curr = head;
    // Calculating the number of nodes in the list
    while (curr != NULL){
        curr = curr->next;
        k++;
    }
    
    if (n > k)
        return -1;
        
    int l = k-n;  // Calculate the difference of number of nodes and given position
    // We can traverse till l to get the desired node
    curr = head;  // Reinitialize curr node to head
    while(l--)
        curr = curr->next;
        
    return curr->data;
}