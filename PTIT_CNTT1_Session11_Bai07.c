#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void addHead(Node **headRef, int value)
{
    Node *newNode = createNode(value);
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode; 
    }
    *headRef = newNode;
}
void add(Node **headRef, int value,int pos)
{
    if (pos <= 0 || *headRef == NULL) {
        addHead(headRef, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = *headRef;
    int index = 0;

    while (temp->next != NULL && index < pos- 1) {
        temp = temp->next;
        index++;
    }

    if (temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}
int main()
{
    Node *head = NULL;
    Node *temp = NULL;
    head = createNode(10);
    temp = head;

    for (int i = 2; i <= 5; i++)
    {
        Node *newNode = createNode(i * 10);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    int value,pos;
    printf("\nNhap gia tri: ");
    scanf("%d", &value);
    printf("nhap vao vi tri: ");
    scanf("%d",&pos);
    add(&head,value,pos-1);
    printf("sau khi them: \n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
