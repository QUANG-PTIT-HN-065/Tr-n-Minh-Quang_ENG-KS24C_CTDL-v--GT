#ifndef FUNTION_H
#define FUNTION_H
#define Max 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue
{
    struct Node *data[Max];
    int front, rear;
} Queue;

struct Node *root = NULL;
struct Node *createNode(int data);
struct Node* dequeue(Queue* q);
void addTreeNode(Node **root, int data);
void inputTree();
void searchNode(Node *root, int data);
void postOrderTraversal(Node *root);
void inOrderTraversal(Node *root);
void preOrderTraversal(Node *root);
void initQueue(Queue* q);
void enqueue(Queue* q, Node* node);
int isQueueEmpty(Queue* q);
void BFS(struct Node* root,int data);

#endif
