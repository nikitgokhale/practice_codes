#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* DEFINES */
#define MAX 20

/* VARIABLES */
int stack_arr[MAX];
int top = -1;

/* FUNCTION DECLARATIONS */
void push(char item);
char pop();
int check(char exp[]);
int match(char a, char b);

/* FUNCTION DEFINITIONS */
void push(char item)
{
    if (top == MAX-1){
        printf("Stack OverFlow!\n");
        return;
    }
    top += 1;
    stack_arr[top] = item;
}

char pop()
{
    if (top == -1){
        printf("Stack UnderFlow!\n");
        exit(1);
    }
    return stack_arr[top--];
}

int check(char exp[])
{
    char tmp;
    for (int i = 0; i<strlen(exp); i++){
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
                push(exp[i]);

        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if (top == -1){
                printf("Right parenthesis are more than left parenthesis!\n");
                return 0;
            }
            else{
                tmp = pop();
                if (!match(tmp, exp[i])){
                    printf("Mismatched Parenthesis!\n");
                    printf("%c and %c\n", tmp, exp[i]);
                    return 0;
                }
            }
        }
    }
    if (top == -1){
        printf("Balanced Parenthesis!\n");
        return 1;
    }
    else{
        printf("Left Parenthesis are more than right parenthesis!\n");
        return 0;
    }
}

int match(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
        return 1;
    else
        return 0;
}

int main()
{
    char expression[MAX];
    int valid;
    printf("Enter an algebraic expression: ");
    gets(expression);
    valid = check(expression);
    if (valid == 1)
        printf("INF: The given algebraic expression is valid!\n");
    else
        printf("WRN: The given algebraic expression is invalid!\n");

    printf("Hello World!\n");
    return 0;
}
