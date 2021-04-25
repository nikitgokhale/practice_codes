#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int info;
    struct node *next;
};

/* Local Function Declaration */
void display(struct node* start);
struct node* addatBeg(struct node* start, int data);
struct node* addatEnd(struct node* start, int data);
struct node* addBefore(struct node* start, int data, int item);
struct node* addAfter(struct node* start, int data, int item);
struct node* del(struct node* start, int item);
struct node* createList(struct node* start);
struct node* reverse(struct node* start);

/* Local Function Defination */
void display(struct node* start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("The list is empty");
        return;
    }
    ptr = start;
    printf("The List is: ");
    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\n\n");
}

struct node* addatBeg(struct node* start, int data)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL)  /* When the Linked List is empty */
    {
        tmp->next = NULL;
        tmp->prev = NULL;
        start = tmp;
        return start;
    }
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct node* addatEnd(struct node* start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    if (start == NULL)
    {
        start = addatBeg(start, data);
        return start;
    }
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->prev = p;
    tmp->next = NULL;
    return start;
}

struct node* addBefore(struct node* start, int data, int item)
{
    struct node *tmp, *p;
    if(item == start->info)
    {
        start = addatBeg(start, data);
        return start;
    }
    p = start;
    while(p != NULL)
    {
        if (p->info == item)
        {
            tmp = (struct  node*)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p;
            p->prev->next = tmp;
            tmp->prev = p->prev;
            p->prev = tmp;
            return start;
        }
        p = p->next;
    }
    printf("Element not found in the list!!\n");
    return start;
}

struct node* addAfter(struct node* start, int data, int item)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty!!\n");
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            p->next->prev = tmp;
            p->next = tmp;
            tmp->prev = p;
            return start;
        }
        p = p->next;
    }
    printf("Element not found in the linked list!!\n");
    return start;
}

struct node* del(struct node* start, int item)
{
    struct node *tmp;
    if (start == NULL)
    {
        printf("List if empty!\n");
        return start;
    }
    if (start->next == NULL)    /* Deletion of the only node */
    {
        if (start->info == item)
        {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
        else{
            printf("Element %d not found in the linked list.\n", item);
            return start;
        }
    }
    if(start->info == item) /* Deletion of the first node */
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return start;
    }
    tmp = start->next;  /* Deletion in between */
    while(tmp->next != NULL)
    {
        if(tmp->info == item)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }
//    if (tmp->info == item)  /* Deletion of the last node */
//    {
//        tmp->prev->next == NULL;
//        free(tmp);
//        return start;
//    }
    printf("Element %d not found in the list.\n", item);
    return start;
}

struct node* createList(struct node* start)
{
    // Take the number of nodes the user wants in his list
    int nodes, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    if (nodes == 0) /*Check if the input nodes are valid */
    {
        printf("Invalid number of nodes.\n");
        return start;
    }
    /* Take the data the user wants to put in the list */
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    start = addatBeg(start, data);
    for (int i=1; i<nodes; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        start = addatEnd(start, data);
    }
    return start;
}

struct node* reverse(struct node* start)
{
    struct node *current, *tmp;
    current = start;
    while (current->next != NULL)
    {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp; /* The previous node */
        current = current->prev;  /* As the previous is now the next, to move the current ptr along the list */
    }
    start = current;
    return start;
}

int main()
{
    struct node *start = NULL;
//    start = addatBeg(start, 13);
//    start = addatEnd(start, 26);
//    start = addatEnd(start, 52);
//    start = addatEnd(start, 78);
//    start = addBefore(start, 39, 52);
//    start = addBefore(start, 7, 13);
//    start = addAfter(start, 65, 52);
//    display(start);
//    start = del(start, 7);
//    display(start);
//    start = del(start, 39);
//    display(start);
//    start = del(start, 78);
    start = createList(start);
    display(start);
    start = reverse(start);
    display(start);
    return 0;
}
