#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    struct Node* next; 
    struct Node* prev;
}Node;
typedef struct Queue {
    Node* front;   
    Node* rear;    
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  
    if (q == NULL) {
        exit(1);
    }
    q->front = NULL;  
    q->rear = NULL;
    return q;
}

int main() {
    Queue* myQueue = createQueue();
    if (myQueue->front == NULL && myQueue->rear == NULL) {
        printf("hang doi da dckhoi tao");
    }
    return 0;
}
