#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

Node * start_insert (Node * head, int key) {
    Node * temp = (Node * )malloc(sizeof(Node));
    temp->data = key;
    temp->next = head;
    Node * new = head;
    while (new->next != head) {
        new = new->next;
    }
    new->next = temp;
    return temp;
}

Node * end_insert (Node * head, int key) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp->data = key;
    Node * new = head;
    while (new->next != head) {
        new = new->next;
    }
    new->next = temp;
    temp->next = head;
    return head;
}

Node * start_delete (Node * head) {
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        free(head);
        return NULL;
    }
    else {
        Node * new = head;
        while (new->next != head) {
            new = new->next;
        }
        Node * temp = head;
        head = head->next;
        free(temp);
        new->next = head;
        return head;
    }
}

Node * end_delete (Node * head) {
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        free(head);
        return NULL;
    }
    else {
        Node * temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
        return head;
    }
}

void traverse (Node * head) {
    Node * temp = head;
    for (int i=0; i<10; i++) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node * head = (Node *)malloc(sizeof(Node));
    Node * two = (Node * )malloc(sizeof(Node)); 
    Node * three = (Node * )malloc(sizeof(Node));
    Node * four = (Node * )malloc(sizeof(Node));  
    head->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;
    head->next = two;
    two->next = three;
    three->next = four;
    four->next = head;
    printf("Linked List Circular : ");
    traverse(head);

    printf("Insert At Starting : ");
    head = start_insert(head,0);
    traverse(head);

    printf("Insert At Ending : ");
    head = end_insert(head,5);
    traverse(head);

    printf("Delete At Starting : ");
    head = start_delete(head);
    traverse(head);

    printf("Delete At End : ");
    head = end_delete(head);
    traverse(head);
    return 0;
}