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
void printNode(Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void seach(Node* head,int mid) {
    struct Node* temp = head;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    printf("Node %d: %d",mid,temp->data);
}

int main() {
    Node* head = NULL;
    Node* temp = NULL;
    head = createNode(10);
    temp = head;
    int len=1;
    for (int i = 0; i < 5; i++)
    {
        temp->next = createNode(++len);
        temp = temp->next;
    }
    printNode(head);
    seach(head,(len/2)+1);

    return 0;
}
