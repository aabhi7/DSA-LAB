#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;
void insert(Node **head, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = *head;
    *head = newNode;
}
void display(Node *head) {
    while (head != NULL) { printf("%d ", head->data); head = head->next; }
}
int main() {
    Node *head = NULL;
    insert(&head, 10); insert(&head, 20); display(head);
    return 0;
}
