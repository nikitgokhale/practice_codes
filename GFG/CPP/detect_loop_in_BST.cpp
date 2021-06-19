/*
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node* p = head;  // Slow Pointer
        Node* q = head;  // Fast Pointer
        
        while (p != NULL && q != NULL && q->next != NULL){
            p = p->next;
            q = q->next->next;
            if (p == q)
                return true;
        }
        return false;
    }
};