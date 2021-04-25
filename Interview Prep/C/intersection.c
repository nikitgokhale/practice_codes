#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

/*Function Declaration */
struct node *newNode(int data);
int ListLength(struct node *head);
void display(struct node *head);
int intersection_point(struct node *p, struct node *q);
struct node *intersection_twoptr(struct node *head1, struct node *head2);
void print(struct node *p);

/* Function Definition */
struct node *newNode(int data)
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	p->data = data;                 // First node
	p->next = NULL;
	return p;
}

int ListLength(struct node *head)
{
    struct node *p;
    int count = 0;
    if (head == NULL)
    {
        printf("List is empty!\n");
        return -1;
    }
    p = head;
    while (p!= NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void display(struct node *head)
{
    struct node *p;
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    p = head;
    printf("The List is: ");
    while (p!= NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n\n");
}

void print(struct node *p)
{
    if (p == NULL)
    {
        printf("NULL");
    }
    else{
        printf("Intersection point is: %d ", p->data);
    }
}

int intersection_point(struct node *p, struct node *q)
{
    struct node *small, *large;
    int length1 = ListLength(p);
    int length2 = ListLength(q);
    int difference = length1 - length2;
    /* To find the absolute value */
    if (difference < 0)
        difference = difference*-1;

    if (length1 > length2){
        small = q;
        large = p;
    }
    else{
        small = p;
        large = q;
    }

    while (difference--){
        large = large->next;
    }
    while (large != small){
        large = large->next;
        small = small->next;
    }
    return large->data;
}

struct node *intersection_twoptr(struct node *head1, struct node *head2)
{
    struct node *p1, *p2;
    p1 = head1;
    p2 = head2;

    if (p1 == NULL || p2 == NULL)
    {
        return NULL;
    }

    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == p2)
            return p1;

        if (p1 == NULL)
            p1 = head2;

        if (p2 == NULL)
            p2 = head1;
    }
    return p1;
}

int main()
{
    struct node *p , *q , *intersection, *intersectionNode = NULL;
	p = newNode(1);
	p->next = newNode(2);
	p->next->next = newNode(3);
	p->next->next->next = newNode(4);
	intersection = p->next->next->next;
	p->next->next->next->next = newNode(5);
	p->next->next->next->next->next = newNode(6);
	display(p);

	q = newNode(7);
	q->next = newNode(8);
	q->next->next = intersection;
    display(q);
    //printf("The intersection point is: %d", intersection_point(p, q));

    intersectionNode = intersection_twoptr(p, q);
    print(intersectionNode);

    return 0;
}
