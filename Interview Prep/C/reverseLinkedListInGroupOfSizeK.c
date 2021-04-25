#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

/* Local Function Declaration */
void display(struct node *head);
struct node *create(struct node *head);
struct node *reverse(struct node *head);
struct node *swapInGroup(struct node *head, int group);
struct node *swapRecursive(struct node *head, int k);


/* Local Function Definition */
void display(struct node *head)
{
    struct node *p;
    if (head == NULL)
    {
        printf("The List is empty.\n");
        return;
    }
    p = head;
    printf("The List is: ");
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n\n");
}

struct node *create(struct node *head)
{
    struct node *p, *q;
    int nodes, item;
    printf("Enter the number of nodes to be added: ");
    scanf("%d", &nodes);
    if (nodes == 0)
    {
        printf("Enter a valid input!\n");
        return head;
    }
    printf("Enter the elements to be added in the list: ");
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &item);
    p->data = item;
    p->next = NULL;
    head = p;
    for(int i=1; i<nodes; i++)
    {
        printf("Enter the elements to be added in the list: ");
        q = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &item);
        q->data = item;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev, *curr, *nextptr;
    curr = head;
    prev = NULL;
    while(curr != NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    head = prev;
    return head;
}

struct node *swapInGroup(struct node *head, int group)
{
    struct node *p, *q, *new_head, *tmp;
    int count = 0;
    p = head;
    while (count != group-1){
        if(p->next == NULL){
            return head;
        }
        p = p->next;
        count++;
    }
    new_head = p;   // This will be the new head node
    q = new_head;

    while (1){
        p = head;
        tmp = q->next;
        if (tmp == NULL){
            reverse(p);
            return new_head;
        }
        q->next = NULL;
        q = tmp;
        head = tmp;
        count = 0;
        while (count != group-1){
                if (tmp->next == NULL){
                    reverse(p);
                    p->next = q;
                    return new_head;
                }
            tmp = tmp->next;
            count++;
        }
        reverse(p);
        p->next = tmp;
        q = tmp;
    }
    return new_head;
}


struct node *swapRecursive(struct node *head, int k)
{
    // Complete this method
    struct node *prev, *curr, *nextptr;
    prev = NULL;
    curr = head;
    int count = k;
    while(count-- && curr != NULL){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    if (head != NULL){
        head->next = swapRecursive(nextptr, k);
    }
    return prev;
}

int main()
{
    struct node *head = NULL;
    head = create(head);
    display(head);
//    head = swapInGroup(head, 4);
//    display(head);
    head = swapRecursive(head, 4);
    display(head);

    //printf("Hello World!\n");
    return 0;
}
