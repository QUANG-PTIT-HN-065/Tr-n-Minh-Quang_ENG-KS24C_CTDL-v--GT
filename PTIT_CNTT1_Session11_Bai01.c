#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    struct Node* next; 
    struct Node* prev;
}Node;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    head = createNode(10);
    temp = head;

    for (int i = 2; i <= 5; i++)
    {
        Node* newNode = createNode(i*10);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
