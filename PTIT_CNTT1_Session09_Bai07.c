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
void addHead(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;       
}
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void addNode(struct Node** headRef, int value, int pos) {
    int total = countNodes(*headRef);
    if (pos < 1 || pos > total + 1) {
        return;
    }
    if (pos == 1) {
        addHead(headRef, value); 
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* temp = *headRef;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

    for (int i = 1; i <= 5; i++) {
        temp->next = createNode(i);
        temp = temp->next;
    }

    printNode(head);

    int value, pos;
    printf("Nhap gia tri: ");
    scanf("%d", &value);
    printf("Nhap vi tri: ");
    scanf("%d", &pos);

    addNode(&head, value, pos);  
    printNode(head);

    return 0;
}
