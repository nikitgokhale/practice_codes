#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

/* Function Declaration */
void display(struct node *last);
struct node *addatBeg(struct node *last, int data);
struct node *addatEnd(struct node *last, int data);
struct node *addAfter(struct node *last, int data, int item);
struct node *addBefore(struct node *last, int data, int item);
struct node *createList(struct node *last);
struct node *del(struct node *last, int item);

/* Function Defination */
void display(struct node *last)
{
    struct node *p;
    if (last == NULL)
    {
        printf("List is Empty.\n");
        return;
    }
    p = last->link;
    do
    {
        printf("%d -> ", p->info);
        p = p->link;
    }while(p!=last->link);
    printf("\n\n");
}

struct node *addatBeg(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    if (last == NULL)  /* Insertion in an Empty Linked List */
    {
        last = tmp;
        last->link = last;
        return last;
    }
    tmp->link = last->link;
    last->link = tmp;
    return last;
}

struct node *addatEnd(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}

struct node *addAfter(struct node *last, int data, int item)
{
    struct node *tmp, *p;
    p = last->link;
    do
    {
        if(p->info == item)
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            if (p == last)
                last = tmp;
            return last;
        }
        p = p->link;
    }while (p != last->link);

    printf("Element %d not found in the linked list.\n", item);
    return last;
}

struct node *addBefore(struct node *last, int data, int item)
{
    struct node *tmp, *p;
    p = last->link;
    do
    {
        if (p->link->info == item)
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            if (p == last)
                last = tmp;
            return last;
        }
        p = p->link;
    }while (p != last->link);
    printf("Element %d not found in the list.", item);
    printf("\n\n");
    return last;
}

struct node *createList(struct node *last)
{
    int nodes, data;
    printf("Enter the number of nodes wanted in the list: ");
    scanf("%d", &nodes);
    if(nodes == 0)
    {
        printf("Invalid input.\n");
        return last;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addatBeg(last, data);
    for(int i=1; i<nodes; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addatEnd(last, data);
    }
    return last;
}

struct node *del(struct node *last, int item)
{
    struct node *tmp, *p;
    if (last == NULL)
    {
        printf("List is empty.\n");
        return last;
    }
    if (last->link == last && last->info == item)  /* Deletion of only node */
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if (last->link->info == item)  /* Deletion of the first node */
    {
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }
    p = last->link;
    while (p->link != last)  /* Deletion of the nodes in between */
    {
        if (p->link->info == item)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }
    if(last->info == item)  /* Deletion of the last node */
    {
        tmp = last;
        p->link = last->link;
        last = p;
        free(tmp);
        return last;
    }
    printf("Element %d not found in the list.\n\n", item);
    return last;
}

int main()
{
    struct node *last = NULL;

    last = addatBeg(last, 52);
    last = addatBeg(last, 26);
    last = addatEnd(last, 65);
    last = addAfter(last, 39, 26);
    last = addBefore(last, 13, 26);
    display(last);
    last = createList(last);
    display(last);
    last = del(last, 13);
    display(last);
    printf("Hello World!!");
    return 0;
}
