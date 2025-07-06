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
void deleteHead(Node **headRef)
{
    Node *temp = *headRef;   
    *headRef = temp->next;    
    if (*headRef != NULL)
    {
        (*headRef)->prev = NULL; 
    }

    free(temp); 
}
void delete(Node** headRef, int position) {
    if (*headRef == NULL || position < 0) {
        return;
    }

    Node* temp = *headRef;
    int index = 0;

    if (position == 0) {
        deleteHead(headRef);
        return;
    }

    while (temp != NULL && index < position) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("vi tri ko hop le!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
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
    int pos;
    printf("\nnhap vao vi tri muon xoa: ");
    scanf("%d",&pos);
    delete(&head,pos-1);
    printf("sau khi xoa: \n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
