#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int data;
    struct stack * prev;
}stack;

int isempty (stack * top) {
    return top == NULL;
}

stack * push (stack * top,int key) {
    stack * newtop = (stack *)malloc (sizeof(stack));
    newtop->data = key;
    newtop->prev = top;
    return newtop;
}

stack * pop (stack * top) {
    stack * temp = top;
    top = top->prev;
    free(temp);
    return top;
}

void print(stack * top) {
    stack * temp  = top;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp -> prev;
    }
    printf("\n");
}
int main() {
    stack * top = NULL;
    top = push (top,1);
    top = push (top,2);
    top = push (top,3);
    top = push (top,4);
    top = push (top,5);
    print(top);
    top = pop (top);
    print(top);
}