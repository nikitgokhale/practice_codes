#include<stdio.h>
#include<stdlib.h>

/* Defines */
#define MAX 10

/* Global Varaibles */
int queue_arr[MAX];
int front = -1;
int rear  = -1;

/* Function Declarations */
void display();
void insert(int item);
int dequeue();
int Peek();
int isEmpty();
int isFull();


/* Function Definitions */
void display()
{
    if(isEmpty()){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i = front; i<=rear; i++){
        printf("%d ", queue_arr[i]);
    }
    printf("\n\n");
}

void insert(int item)
{
    if (isFull()){
        printf("Stack Overflow!\n");
        return;
    }
    if (front == -1){
        front = 0;
    }
    rear += 1;
    queue_arr[rear] = item;
}

int dequeue()
{
    int item;
    if(isEmpty()){
        printf("Stack UnderFlow!\n");
        exit(1);
    }
    item = queue_arr[front];
    front = front+1;
    return item;
}

int isEmpty()
{
    if (front == -1 || front == rear+1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == MAX-1)
        return 1;
    else
        return 0;
}

int Peek()
{
    if (isEmpty()){
        printf("Stack is Empty.\n");
        exit(1);
    }
    return queue_arr[front];
}

int main()
{
    insert(20);
    insert(10);
    insert(30);
    dequeue();
    insert(42);
    printf("Peeked element is: %d\n", Peek());
    display();

    printf("Hello World");
    return 0;
}
