#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int size;
    int top;
    int * arr;

} stack;

int isempty (stack * s) {
    return s->top == -1;
}

int isfull (stack * s) {
    return s->top == s->size - 1;
}

stack * push (stack * s, int key) {
    if (isfull(s)) return s;
    s->arr[++(s->top)] = key;
    return s;
}

int pop (stack ** s) {
    if (isempty(*s)) return -1;
    return ((*s)->arr[(*s)->top--]);
}

int stacktop (stack *s) {
    int i = pop(&s);
    s = push(s,i);
    return i;
}

void print (stack * s) {
    for (int i=0; i<=s->top; i++) {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main() {
    stack * s = (stack *)malloc (sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int * ) malloc(sizeof(int)*s->size);
    push(s,1);
    push(s,2);
    push(s,3);
    printf("After Pushing 1,2,3 : ");
    print(s);
    printf("After Pop The Element : %d\n",pop(&s));
    print(s);
    printf("Use The Function Stack TOP %d\n",stacktop(s));
    return 0;
}