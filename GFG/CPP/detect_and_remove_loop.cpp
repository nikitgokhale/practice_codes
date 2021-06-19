
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

*/

class Solution
{
    public:
    // Function to remove loop
   void removeLoopNode(Node* slow, Node* head)
    {
        Node* p1 = slow;
        Node* p2 = slow;
        // Counting the number of nodes in the loop
        int count = 1;
        p2 = p2->next;
        while (p1 != p2){
            p2 = p2->next;
            count++;
        }
        // Fix one of the pointer to the head
        p1 = head;
        // Fix the other pointer to the kth node
        p2 = head;
        while (count--){
            p2 = p2->next;
        }
        // Moving both the pointers at same pace so
        // that they meet at the loop point
        while (p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        // Get to the previous pointer of p2
        while (p2->next != p1){
            p2 = p2->next;
        }
        p2->next = NULL;
    }
    
    // Function to detect the loop
    bool detectLoopAndRemove(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while (slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                removeLoopNode(slow, head);
                return true;
            }
        }
        return false;
    }
    
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        detectLoopAndRemove(head);
    }
}; 