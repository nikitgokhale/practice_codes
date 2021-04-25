#include<stdio.h>
#include<stdlib.h>

/* DEFINES */
#define MAX 10

/* Global Variables */
int stack_arr[MAX];
int top = -1;

/* Function Declaration */
void display();
int peek();
int isEmpty();
int isFull();
void push(int item);
int pop();

/* Function Definition */
void push(int item)
{
    if (isFull()){
        printf("StackOverFlow.\n");
        return;
    }
    top += 1;
    stack_arr[top] = item;
}

int pop()
{
    if (isEmpty()){
        printf("StackUnderFlow.\n");
        exit(1);
    }
    int item = stack_arr[top];
    top -= 1;
    return item;
}

int isFull()
{
    if (top == MAX-1){
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if (top == -1){
        return 1;
    }
    else
        return 0;
}

int peek()
{
    if (isEmpty()){
        printf("StackUnderFlow.\n");
        exit(1);
    }
    return stack_arr[top];
}

void display()
{
    if (isEmpty()){
        printf("StackUnderFlow.\n");
        exit(1);
    }
    printf("Stack Elements are:\n");
    for(int i=top; i>=0; i--){
        printf("%d\n", stack_arr[i]);
    }
    printf("\n");
}

int main()
{
    push(14);
    push(28);
    push(42);
    pop();
    push(56);
    display();
    return 0;
}
