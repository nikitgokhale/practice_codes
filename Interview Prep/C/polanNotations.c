#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/* DEFINES */
#define BLANK ' '
#define TAB '\t'
#define MAX 50

/* VARIABLES */
int top;
long int stack_arr[MAX];
char infix[MAX];
char postfix[MAX];

/* FUNCTION DECLARATIONS */
void push(int item);
int pop();
int isEmpty();
void infixToPostfix();
int whiteSpace(char symbol);
int intStack_priority(char symbol);
int incoming_priority(char symbol);
long int evaluatePostfix();

/* FUCNTION DEFINITIONS */
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int item)
{
    if (top > MAX){
        printf("Stack OverFlow!\n");
        return;
    }
    stack_arr[++top] = item;
}

int pop()
{
    if (top == -1){
        printf("Stack UnderFlow!\n");
        exit(1);
    }
    return (stack_arr[top--]);
}

int whiteSpace(char symbol)
{
    if (symbol == BLANK || symbol == TAB)
        return 1;
    else
        return 0;
}

void infixToPostfix()
{
    unsigned int p = 0;
    char next;
    char symbol;
    for(int i = 0; i<strlen(infix); i++){
            symbol = infix[i];
            if(!whiteSpace(symbol)){
                switch(symbol)
                {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next=pop()) != '(')
                            postfix[p++] = next;
                    break;
                case '+':
                case '-':
                case '/':
                case '*':
                case '%':
                case '^':
                    while (!isEmpty() && intStack_priority(stack_arr[top]) >= incoming_priority(symbol))
                        postfix[p++] = pop();
                    push(symbol);
                    break;
                default:
                    postfix[p++] = symbol;
                }
            }
    }
    while (!isEmpty()){
        postfix[p++] = pop();
    }
}

int intStack_priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int incoming_priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 4;
    default:
        return 0;
    }
}

long int evaluatePostfix()
{
    long int a, b, tmp, result;
    unsigned int i;
    for(i = 0; i<strlen(postfix); i++){
            if (postfix[i] <= '9' && postfix[i] >= '0'){
                push(postfix[i]-'0');
            }
            else{
                a = pop();
                b = pop();
                switch(postfix[i])
                {
                case '+':
                    tmp = b+a; break;
                case '-':
                    tmp = b-a; break;
                case '*':
                    tmp = b*a; break;
                case '/':
                    tmp = b/a; break;
                case '%':
                    tmp = b%a; break;
                case '^':
                    tmp = pow(b, a); break;
                }
                push(tmp);
            }
    }
    result = pop();
    return result;
}

int main()
{
    long int value;
    top = -1;
    printf("Enter an infix expression: ");
    gets(infix);
    infixToPostfix();
    printf("Postfix : %s\n", postfix);
    value = evaluatePostfix();
    printf("Value of expression: %ld\n", value);
    printf("Hello World!\n");
    return 0;
}
