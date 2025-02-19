#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
} Node;

Node * startinsert(Node * head,int key) {
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = key;
    temp->prev = NULL;
    temp->next = head;
    if (head==NULL) {
        return temp;
    }
    else {
        head->prev = temp;
        return temp; 
    }
}

Node * endinsert(Node * head, int key) {
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = key;
    temp->next = NULL;
    if (head == NULL) {
        temp->prev = NULL;
        return temp;
    }
    else {
        Node * new = head;
        while (new->next != NULL) {
            new = new->next;
        }
        new->next = temp;
        temp->prev = new;
        return head;
    }
}

Node * startdelete (Node * head) {
    if (head==NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        free(head);
        return NULL;
    }
    else {
        Node * temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
}

Node * endDelete (Node * head) {
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        free(head);
        return NULL;
    }
    else {
        Node * temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
    }
}

void traverse (Node * head) {
    Node * temp = head;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main () {

    Node * head = (Node *)malloc(sizeof(Node));
    Node * two = (Node *)malloc(sizeof(Node));
    Node * three = (Node *)malloc(sizeof(Node));
    Node * four = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->prev = NULL;
    head->next = two;
    two->data = 2;
    two->prev = head;
    two->next = three;
    three->prev = two;
    three->data = 3;
    three->next = four;
    four->prev = three;
    four->data = 4;
    four->next = NULL;
    printf("Linked List : ");
    traverse(head);

    printf("After Start Insert : ");
    head = startinsert(head,0);
    traverse(head);

    printf("After End Insert : ");
    head = endinsert(head,5);
    traverse(head);

    printf("After Start Delete : ");
    head = startdelete(head);
    traverse(head);
    
    printf("After End Delete : ");
    head = endDelete(head);
    traverse(head);
}