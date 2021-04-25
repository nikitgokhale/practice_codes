#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *link;
};

/* Local Function Declaration */
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int item);
struct node *createList(struct node *start);
struct node *addatBeg(struct node *start, int data);
struct node *addatEnd(struct node *start, int data);
struct node *addAfter(struct node *start, int data, int item);
struct node *addBefore(struct node *start, int data, int item);
struct node *addatPos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);
struct node *reverseRecursion(struct node *start);
struct node *rotate_counter(struct node *start, int rotation);
struct node *rotate(struct node *start, int rotation);
struct node* insert_s(struct node *start, int data);
void selection(struct node *start);
void bubble(struct node *start);
struct node *selection_l(struct node *start);
struct node *bubble_l(struct node *start);

/* Local Function Definitions */
void display(struct node *start)
{
    struct node *p = start;
    if(start == NULL)
    {
        printf("The Linked List is empty!!");
        return;
    }
    printf("List is : ");
    while(p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->link;
    }
    printf("NULL");
    printf("\n\n");
}

void search(struct node *start, int item)
{
    struct node *p = start;
    int pos = 1;
    while (p != NULL)
    {
        if (p->info == item)
        {
            printf("Item %d found at position %d", item, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item %d not found in the list", item);
}

void count(struct node *start)
{
    struct node *p;
    int count = 0;
    p = start;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    printf("The number of elements are %d", count);
    printf("\n\n");
}

struct node *addatBeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    // When the linked list is empty
    if (start == NULL)
    {
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}

struct node *addatEnd(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    if (start == NULL)
    {
        start = addatBeg(start, data);
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = tmp;
    tmp->link = NULL;
    return start;
}
struct node *addAfter(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Item %d not found in the linked list.\n", item);
    return start;
}

struct node *addBefore(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty.");
        return start;
    }
    /* If the item to be inserted is at the start of the list */
    if (item == start->info)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if (p->link->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Item is not present int the Linked List");
    return start;
}

struct node *addatPos(struct node *start, int data, int pos)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    if (pos == 1)
    {
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    for (int i = 1; i < pos-1 && p != NULL; i++)
        p = p->link;
    if (p == NULL)
        printf("There are less item in linked list than %d", pos);
    else
    {
        tmp->link = p->link;
        p->link = tmp;
        return start;
    }
    return start;
}

struct node *createList(struct node *start)
{
    int i, nodes, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &nodes);
    start = NULL;
    if (nodes == 0)
        return start;
    printf("Enter the elements to be inserted : ");
    scanf("%d", &data);
    start = addatBeg(start, data);
    for (i=1; i<nodes; i++)
    {
        printf("Enter the elements to be inserted : ");
        scanf("%d", &data);
        start = addatEnd(start, data);
    }
    return start;
}

struct node *del(struct node *start, int data)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty!!");
        return start;
    }
    if (start->info == data)   /* Deletion of the first node */
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("Element not found in the linked list");
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *prev, *p, *next;
    prev = NULL;
    p = start;
    while (p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
}

struct node *reverseRecursion(struct node *start)
{
    struct node *p, *q;
    p = start;
    q = p->link;
    if (start == NULL)
        return start;
    if (q == NULL)
        return start;
    q = reverseRecursion(q);
    p->link->link = p;
    p->link = NULL;
    return q;
}
/* When you want to maintain ascending order when inserting the elements in the list */
struct node* insert_s(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
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

void selection(struct node *start)
{
    struct node *p, *q;
    int tmp;
    p = start;
    for(p = start; p->link != NULL; p = p->link)
    {
        for(q = p->link; q != NULL; q = q->link)
        {
            if(p->info > q->info)
            {
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

void bubble(struct node *start)
{
    struct node *end, *p, *q;
    int tmp;
    p = start;
    for(end=NULL; end!=start->link; end=q)
    {
        for(p = start; p->link != end; p = p->link)
        {
            q = p->link;
            if (p->info > q->info)
            {
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

struct node *selection_l(struct node *start)
{
    struct node *p, *q, *r, *s, *tmp;
    for(r=p=start; p->link != NULL; r=p, p=p->link)
    {
        for(s=q=p->link; q != NULL; s=q, q=q->link)
        {
            if(p->info > q->info)
            {
                tmp = p->link;
                p->link = q->link;
                q->link = tmp;
                if (p != start)
                    r->link = q;
                s->link = p;
                if (p == start)
                    start = q;
                tmp = p;
                p = q;
                q = tmp;
            }
        }
    }
    return start;
}

struct node *bubble_l(struct node *start)
{
    struct node *end, *p, *q, *r, *tmp;
    for(end=NULL; end!=start->link; end=q)
    {
        for(r=p=start; p->link!=end; r=p, p=p->link)
        {
            q = p->link;
            if (p->info > q->info)
            {
                p->link = q->link;
                q->link = p;
                if(start != p)
                    r->link = q;
                else
                    start = q;
                tmp = p;
                p = q;
                q = tmp;
            }
        }
    }
    return start;
}

struct node *rotate_counter(struct node *start, int rotation)
{
    struct node *p, *end;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = start;
    while (rotation--)
    {
        end = start;
        start = start->link;
    }
    end->link = NULL;
    return start;
}

struct node *rotate(struct node *start, int rotation)
{
    struct node *p, *end;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = start;
    while (rotation++)
    {
        end = start;
        start = start->link;
    }
    end->link = NULL;
    return start;
}

int main()
{
    struct node *start = NULL;
    start = createList(start);
    display(start);
    start = rotate_counter(start, 3);
    display(start);
//    start = addatBeg(start, 15);
//    start = addatEnd(start, 23);
//    start = addAfter(start, 24, 23);
//    start = addBefore(start, 26, 23);
//    start = addatBeg(start, 36);
//    start = del(start, 36);
//    display(start);
//    start = reverseRecursion(start);
//    start = insert_s(start, 13);
//    start = insert_s(start, 39);
//    start = insert_s(start, 65);
//    start = insert_s(start, 26);
//    start = insert_s(start, 52);
//    selection(start);
//    bubble(start);
//    start = selection_l(start);
    //start = bubble_l(start);
    //display(start);
    return 0;
}
