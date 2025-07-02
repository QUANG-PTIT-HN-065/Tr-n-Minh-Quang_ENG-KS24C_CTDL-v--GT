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

void seach(Node* head) {
    struct Node* temp = head;
    int count =0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("danh sach co %d phan tu\n",count);
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    head = createNode(10);
    temp = head;

    for (int i = 1; i <= 10; i++)
    {
        temp->next = createNode(i);
        temp = temp->next;
    }
    seach(head);

    return 0;
}
