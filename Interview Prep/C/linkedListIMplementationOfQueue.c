#include<stdio.h>
#include<stdlib.h>

/* Typedefs and Structures */
struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

/* Function Declarations */
void insert(int item);
void display();
int dequeue();
int peek();
int isEmpty();

/* Function Definitions */
int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void insert(int item)
{
    struct Node *tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL){
        printf("Memory not available, Queue Overflow.\n");
        return;
    }
    tmp->data = item;
    tmp->next = NULL;
    if (front == NULL)
        front = tmp;
    else
        rear->next = tmp;
    rear = tmp;
}

int dequeue()
{
    if (isEmpty()){
        printf("Queue Underflow!\n");
        exit(1);
    }
    struct Node *tmp = front;
    int item = tmp->data;
    front = front->next;
    free(tmp);
    printf("This %d item deleted.\n", item);
    return item;
}

int peek()
{
    if(isEmpty()){
        printf("Queue is Empty!\n");
        exit(1);
    }
    int item = front->data;
    return item;
}

void display()
{
    struct Node *ptr;
    ptr = front;
    if (isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }
    printf("The Queue elements are: ");
    while (ptr != NULL){
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

int main()
{
    insert(5);
    insert(10);
    insert(20);
    insert(40);
    printf("The element in the front of the queue is: %d\n", peek());
    dequeue();
    display();
    printf("Hello World!\n");
    return 0;
}
