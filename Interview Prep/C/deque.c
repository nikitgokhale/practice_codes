#include<stdio.h>
#include<stdlib.h>

/* Defines */
#define MAX 10

/* Global Variables */
int deque_arr[MAX];
int front = -1;
int rear  = -1;

/* Function Declarations */
void insert_FrontEnd(int item);  // Push Operation
void insert_RearEnd(int item);   // Inject Operation
int del_FrontEnd();              // Pop Operation
int del_rearEnd();               // Eject Operation
int isEmpty();
int isFull();
void display();

/* Function Definitions */
void insert_FrontEnd(int item)
{
    if(isFull()){
        printf("DeQue OverFlow!\n");
        return;
    }

    if (front == -1){
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX-1;
    else
        front -= 1;

    deque_arr[front] = item;
}

void insert_RearEnd(int item)
{
    if (isFull()){
        printf("DeQue OverFlow!\n");
        return;
    }

    if (front == -1){
        front = 0;
        rear = 0;
    }
    else if(rear == MAX-1)
        rear = 0;
    else
        rear += 1;
    deque_arr[rear] = item;
}

int del_FrontEnd()
{
    int item;
    if(isEmpty()){
        printf("DeQue UnderFlow!\n");
        exit(1);
    }
    item = deque_arr[front];
    if(front==rear){
        front = -1;
        rear = -1;
    }
    else{
        if (front == MAX-1)
            front = 0;
        else
            front += 1;
    }
    return item;
}

int del_rearEnd()
{
    int item;
    if (isEmpty()){
        printf("DeQue UnderFLow!\n");
        exit(1);
    }
    item = deque_arr[rear];
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else if (rear == 0){
        rear = MAX-1;
    }
    else{
        rear -= 1;
    }
    return item;
}

int isEmpty()
{
    if (front == -1){
        return 1;
    }
    else
        return 0;
}

int isFull()
{
    if ((front==0 && rear==MAX-1) || (front==rear+1)){
        return 1;
    }
    else
        return 0;
}

void display()
{
    if (isEmpty()){
        printf("DeQue is Empty.\n");
        return;
    }
    printf("Deque Elements are: ");
    int i = front;
    if (front <= rear){
        while (i<=rear)
            printf("%d ", deque_arr[i++]);
    }
    else{
        while (i<=MAX-1)
            printf("%d ", deque_arr[i++]);
        i=0;
        while (i<=rear)
            printf("%d ", deque_arr[i++]);
    }
    printf("\n\n");
}


int main()
{
    insert_RearEnd(20);
    insert_RearEnd(15);
    insert_FrontEnd(10);
    insert_FrontEnd(25);
    insert_FrontEnd(35);
    display();
    del_FrontEnd();
    display();
    del_rearEnd();
    display();
    printf("Hello World!\n");
    return 0;
}
