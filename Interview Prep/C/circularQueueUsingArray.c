#include<stdio.h>
#include<stdlib.h>

/* Defines */
#define MAX 10

/* Global variables */
int cqueue_arr[MAX];
int front = -1;
int rear  = -1;

/* Function Declarations */
void insert(int item);
int dequeue();
int peek();
int isEmpty();
int isFull();
void display();

/* Function Definitions */
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
        return 1;
    else
        return 0;
}

void insert(int item)
{
    if (isFull()){
        printf("Queue OverFlow!!\n");
        return;
    }
    if (front == -1)
        front = 0;

    if (rear == MAX-1)
        rear = 0;
    else
        rear += 1;
    cqueue_arr[rear] = item;
}

int dequeue()
{
    if (isEmpty()){
        printf("Queue UnderFlow!!\n");
        exit(1);
    }
    int item = cqueue_arr[front];
    if (front == rear) /* If the queue has only one element */
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX-1)
        front = 0;
    else
        front += 1;
    printf("The element %d was deleted from the queue.\n", item);
    return item;
}

int peek()
{
    if (isEmpty()){
        printf("Queue is Empty!!\n");
        exit(1);
    }
    int item = cqueue_arr[front];
    printf("This element is at the front of the queue: %d\n", item);
    return item;

}

void display()
{
    if(isEmpty()){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i = front; i<=rear; i++){
        printf("%d ", cqueue_arr[i]);
    }
    printf("\n\n");
}

int main()
{
    insert(20);
    insert(10);
    insert(30);
    dequeue();
    insert(42);
    peek();
    display();

    printf("Hello World!\n");
    return 0;
}
