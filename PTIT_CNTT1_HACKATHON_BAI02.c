#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[MAX];
    float price;
    int Size;
} Drink;
typedef struct StackNode {
    Drink data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, Drink d) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = d;
    newNode->next = s->top;
    s->top = newNode;
}

Drink pop(Stack* s) {
    Drink d = {"EMPTY"};
    if (isStackEmpty(s))
        return d;
    StackNode* temp = s->top;
    d = temp->data;
    s->top = s->top->next;
    free(temp);
    return d;
}
typedef struct Node {
    Drink data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Drink d) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Drink dequeue(Queue* q) {
    Drink d = {"EMPTY"};
    if (isQueueEmpty(q)) {
        return d;
    }
    Node* temp = q->front;
    d = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return d;
}

void viewQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Danh sach goi mon dang trong!\n");
        return;
    }
    Node* temp = q->front;
    printf("Danh sach cac mon dang cho phuc vu:\n");
    while (temp != NULL) {
        printf(" - %s\n", temp->data.name);
        temp = temp->next;
    }
}
int main() {
    Queue orderQueue;
    Stack cancelStack;
    initQueue(&orderQueue);
    initStack(&cancelStack);

    char command[20];
    while (1) {
        printf("\n—————— MENU COFFEE ——————\n");
        printf("ORDER: Goi mon moi\n");
        printf("CANCEL: Huy mon vua goi\n");
        printf("REORDER: Dat lai mon vua bi huy\n");
        printf("VIEW ORDERS: Hien thi cac mon dang cho phuc vu\n");
        printf("EXIT: Thoat chuong trinh\n");
        printf("-----------------------------\n");
        printf("Nhap lenh: ");

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; 

        if (strcmp(command, "ORDER") == 0) {
            Drink d;
            printf("Nhap ten do uong muon goi: ");
            fgets(d.name, MAX, stdin);
            d.name[strcspn(d.name, "\n")] = '\0';
            enqueue(&orderQueue, d);
            printf("Da goi mon: %s\n", d.name);
        }
        else if (strcmp(command, "CANCEL") == 0) {
            if (isQueueEmpty(&orderQueue)) {
                printf("Khong co mon nao de huy!\n");
            } else {
                Drink cancelled = dequeue(&orderQueue);
                push(&cancelStack, cancelled);
                printf("Da huy mon: %s\n", cancelled.name);
            }
        }
        else if (strcmp(command, "REORDER") == 0) {
            if (isStackEmpty(&cancelStack)) {
                printf("Khong co mon nao de dat lai!\n");
            } else {
                Drink redone = pop(&cancelStack);
                enqueue(&orderQueue, redone);
                printf("Da dat lai mon: %s\n", redone.name);
            }
        }
        else if (strcmp(command, "VIEW ORDERS") == 0) {
            viewQueue(&orderQueue);
        }
        else if (strcmp(command, "EXIT") == 0) {
            break;
        }
        else {
            printf(" khong hop le! Vui long nhap lai.\n");
        }
    }

    return 0;
}