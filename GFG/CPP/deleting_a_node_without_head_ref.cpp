/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


class Solution
{
public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        // Your code here
        Node* tmp = del->next;
        // Copying the data of del's next node (tmp) into del
        del->data = tmp->data;
        // Now removing the pointer of del's with the tmp
        // Making it point to the tmp's next node
        del->next = tmp->next;
        // Clearing the tmp node
        free(tmp);
    }
