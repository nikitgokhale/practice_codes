/*
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

struct node*update(struct node* head, int p)
{
    //Add your code here
    if (p <= 0)
        return head;
        
    node* end = head;
    node* tmp = head, *tmpHead = NULL;
    
    // 1st Traversal
    while (end->next != NULL)
        end = end->next;
        
    // 2nd Traversal
    while (p--){
        tmpHead = tmp->next;
        tmp->next = NULL;
        tmpHead->prev = NULL;
        end->next = tmp;
        tmp->prev = end;
        end = end->next;
        tmp = tmpHead;
    }
    return tmpHead;
}