#include<stdio.h>
#include<stdlib.h>

/* typedefs and structures */
struct Node
{
    int data;
    struct Node *next;
}*rear = NULL;

/* Function Declarations */
void insert(int item);
void display();
int dequeue();
int peek();
int isEmpty();

/* Function Definitions */
int isEmpty()
{
    if (rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insert(int item)
{
    struct Node *tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL){
        printf("Queue Overflow!\n");
        return;
    }
    tmp->data = item;
    if (rear == NULL){
        rear = tmp;
        tmp->next = rear;
    }
    else{
        tmp->next = rear->next;
        rear->next = tmp;
        rear = tmp;
    }
}

int dequeue()
{
    if (isEmpty()){
        printf("Stack UnderFlow!\n");
        exit(1);
    }
    struct Node *tmp;
    int item;
    if (rear->next == rear){
        tmp = rear;
        rear = NULL;
    }
    else{
        tmp = rear->next;
        rear->next = rear->next->next;
    }
    item = tmp->data;
    free(tmp);
    printf("This element %d is deleted.\n", item);
    return item;
}

int peek()
{
    if (isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    int item = rear->next->data;
    printf("The element is the front of the queue is: %d\n", item);
    return item;
}

void display()
{
    if(isEmpty()){
        printf("Queue is Empty.\n");
        exit(1);
    }
    struct Node *ptr;
    ptr = rear->next;
    printf("The elements in the Queue are: \n");
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while (ptr != rear->next);
    printf("\n\n");
}

int main()
{
    insert(5);
    insert(10);
    insert(20);
    insert(40);
    peek();
    dequeue();
    display();

    printf("Hello World!\n");
    return 0;
}
