// Author: Ajit J.
// Subject: Data Structures
// Description: Implementation of stack using array

#include "mydef.h"
#define N 5

int arr[N], top = -1;

void printStack()
{
    int i;
    for(i=0; i<=top; i++)
        printf("|%d%s", arr[i], i==top ? "\n":"");
}

int pop()
{
    if(top == -1){
        fprintf(stderr, Red "[ERROR]: Stack Underflow\n" Reset);
        exit(1);
    }
    return arr[top--];
}

void push(int item)
{
    if(top == N-1){
        fprintf(stderr, Red "[ERROR]: Stack Overflow" Reset);
        exit(2);
    }
    arr[++top] = item;
}

int main(int argc, char const *argv[])
{
    push(2);
    push(4);
    push(5);
    printStack();
    push(8);
    push(11);
    printStack();
    //push(22); // Overflow
    printf("%d\n", pop());
    printf("%d\n", pop());
    printStack();
    return 0;
}
