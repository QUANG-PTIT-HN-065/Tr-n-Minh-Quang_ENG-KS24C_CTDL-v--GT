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
void delete(struct Node** headRef, int pos) {
    if (*headRef == NULL || pos < 1) {
        printf("Vi tri khong hop le .\n");
        return;
    }

    struct Node* temp = *headRef;

    if (pos == 1) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    struct Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
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

    int pos;
    printf("Nhap vi tri: ");
    scanf("%d", &pos);
    delete(&head,pos);
    printNode(head);

    return 0;
}
