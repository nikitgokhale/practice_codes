#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Defines */
#define MAX 20

/* Variables */
char stack_arr[MAX];
int top = -1;

/* Function Declarations */
void push(char);
char popOut();

/* Function Declarations */
void push(char item)
{
    if (top == MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    stack_arr[++top] = item;
}

char popOut()
{
    if (top == -1){
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack_arr[top--];
}

int main()
{
    char string[MAX];
    unsigned int i;
    printf("Enter the string you want to reverse: \n");
    gets(string);
    /* Push the characters of the sting string onto the stack */
    for (i = 0; i<strlen(string); i++)
        push(string[i]);
    /* Pop the characters from the stack into string */
    for (i = 0; i<strlen(string); i++)
        string[i] = popOut();
    printf("The reversed string is: ");
    puts(string);
    return 0;
}
