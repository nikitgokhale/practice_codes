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
struct node *rotateAroundNode(struct node *head, int nodeData);

/* Local Function Defination */
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

struct node *rotateAroundNode(struct node *head, int nodeData)
{
    struct node *p, *q, *newHead;
    p = head;
    while (p != NULL){
        if (p->data == nodeData)
            break;
        p = p->next;
    }
    q = p->next;
    newHead = q;
    p->next = NULL;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = head;
    return newHead;
}

int main()
{
    struct node *head = NULL;

    head = create(head);
    display(head);
    head = rotateAroundNode(head, 5);
    display(head);
    printf("hello World");
    return 0;
}
