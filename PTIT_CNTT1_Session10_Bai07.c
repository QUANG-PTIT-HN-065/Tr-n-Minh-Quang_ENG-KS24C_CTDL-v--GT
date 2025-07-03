#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    struct Node* next;     
}Node;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void sort(struct Node* head) {
    if (head == NULL) return;
    struct Node* current;
    struct Node* index;
    int temp;

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

void printNode(Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    head = createNode(10);
    temp = head;

    for (int i = 9; i > 0; i--)
    {
        temp->next = createNode(i);
        temp = temp->next;
    }
    printNode(head);
    sort(head);
    printNode(head);
    return 0;
}
