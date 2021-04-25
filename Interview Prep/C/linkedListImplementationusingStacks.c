#include<stdio.h>
#include<stdlib.h>

/* typdefs and structs */
struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

/* Function Declarations */
void display();
void push(int item);
int pop();
int isEmpty();
int Peek();

/* Function Definitions */
void display()
{
    struct Node *ptr;
    ptr = top;
    if (ptr == NULL){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack Elements are: \n");
    while (ptr != NULL){
        printf(" %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void push(int item)
{
    struct Node *tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL){
        printf("Stack OverFlow!\n");
        return;
    }
    tmp->data = item;
    tmp->next = top;
    top = tmp;
}

int isEmpty()
{
    if (top == NULL){
        return 1;
    }
    else
        return 0;
}

int Peek()
{
    if(isEmpty()){
        printf("Stack is Empty!\n");
        exit(1);
    }
    return top->data;
}

int pop()
{
    struct Node *tmp;
    int item;
    if (isEmpty()){
        printf("Stack UnderFlow!\n");
        exit(1);
    }
    tmp = top;
    item = tmp->data;
    top = top->next;
    free(tmp);
    return item;
}

int main()
{
    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    isEmpty();
    int topElement = Peek();
    printf("Top Element of the Stack is: %d \n", topElement);
    display();
    printf("Bello World.\n");
    return 0;
}
