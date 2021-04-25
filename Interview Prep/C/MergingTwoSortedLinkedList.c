#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *link;
};

/* Local Function Declaration */
void display(struct node *start);
void merge(struct node *p1, struct node *p2);
struct node *create(struct node *start);
struct node *insert(struct node *start, int data);
struct node *insert_s(struct node *start, int data);
void concat(struct node *start1, struct node *start2);
struct node* sortedMerge(Node *p1, Node *p2);

/* Local Function Definition */
void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is Empty.\n");
    }
    p = start;
    while(p!=NULL)
    {
        printf("%d -> ", p->info);
        p = p->link;
    }
    printf("NULL");
    printf("\n");
}

struct node *create(struct node *start)
{
    int nodes, data;
    printf("Enter the number of nodes you want to add in the list: ");
    scanf("%d", &nodes);
    if (nodes == 0)
    {
        printf("Invalid Input.\n");
        return start;
    }
    start = NULL;
    for (int i = 0; i < nodes; i++)
    {
        printf("Enter the elements in the list: ");
        scanf("%d", &data);
        start = insert_s(start, data);
    }
    return start;
}

struct node *insert(struct node *start, int data)
{
    struct node *p, *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL)  /* When the list is empty */
    {
        tmp->link = start;
        start = tmp;
        return start;
    }
    else{
        p = start;
        while(p->link != NULL)
            p = p->link;
        tmp->link = p->link;
        p->link = tmp;
    }
    return start;
}

struct node *insert_s(struct node *start, int data)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    /* List is empty or the data to be added in at the beginning */
    if(start == NULL || data < start->info)
    {
        tmp->link = start;
        start = tmp;
        return start;
    }
    else{
        p = start;
        while (p->link != NULL && p->link->info < data)
            p = p->link;
        tmp->link = p->link;
        p->link = tmp;
    }
    return start;
}

void merge(struct node *p1, struct node *p2)
{
    struct node *start3;
    start3 = NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->info < p2->info)
        {
            start3 = insert(start3, p1->info);
            p1 = p1->link;
        }
        else if (p2->info < p1->info)
        {
            start3 = insert(start3, p2->info);
            p2 = p2->link;
        }
        else if (p1->info == p2->info)
        {
            start3 = insert(start3, p1->info);
//            start3 = insert(start3, p2->info);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    /* For covering up the unfinished list */
    while (p1 != NULL)
    {
        start3 = insert(start3, p1->info);
        p1 = p1->link;
    }
    while (p2 != NULL)
    {
        start3 = insert(start3, p2->info);
        p2 = p2->link;
    }
    printf("Merged List is: ");
    display(start3);
}

struct node* sortedMerge(Node *p1, Node *p2)
{
    // code here
    Node *start3 = NULL;
    Node **ref = &start3;
    while (p1 && p2){
        if (p1->data < p2->data){
            *ref = p1;
            p1 = p1->next;
        }
        else{
            *ref = p2;
            p2 = p2->next;
        }
        ref = &((*ref)->next);
    }
    *ref = (p1)?p1:p2;
    return start3;
}

void concat(struct node *start1, struct node *start2)
{
    struct node *ptr;
    if (start1 == NULL)
    {
        start1 = start2;
        return;
    }
    if (start2 == NULL)
        return;
    ptr = start1;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = start2;
    printf("Concatenated List is : ");
    display(start1);
}

int main()
{
    struct node *start1 = NULL, *start2 = NULL;
    start1 = create(start1);
    start2 = create(start2);
    printf("List1 : ");
    display(start1);
    printf("List2 : ");
    display(start2);
    concat(start1, start2);
    //merge(start1, start2);
//    printf("Hello World");
    return 0;
}
