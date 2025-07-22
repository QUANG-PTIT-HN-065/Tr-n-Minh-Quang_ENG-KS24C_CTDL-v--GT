#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funtion.h"

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addTreeNode(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        addTreeNode(&((*root)->left), data);
    } else {
        addTreeNode(&((*root)->right), data);
    }
}

void inputTree() {
    int n, data;

    printf("nhap so node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("nhap node so %d: ", i + 1);
        scanf("%d", &data);
        addTreeNode(&root, data);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void searchNode(Node* root, int data) {
    if (root == NULL) {
        printf("Fasle");
        return ; 
    }
    if (root->data == data) {
        printf("True");
        return ; 
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < Max - 1) {
        q->data[++q->rear] = node;
    } else {
        printf("Queue is full\n");
    }
}

struct Node* dequeue(Queue* q) {
    if (!isQueueEmpty(q)) {
        return q->data[q->front++];
    } else {
        printf("Queue is empty\n");
        return NULL;
    }
}

void BFS(struct Node* root,int data) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {
        struct Node* current = dequeue(&q);
        if (current->data == data) {
            printf("True\n");
            return;
        } 
        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    printf("False\n");
}

//bai 3
void addNodeLevelOrder(struct Node* root, int data) {
    if (root == NULL) {
        printf("Cây rỗng, không thể thêm vào.\n");
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {
        struct Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(data);
            return;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(data);
            return;
        } else {
            enqueue(&q, current->right);
        }
    }
}

// bai 4
int countLeafRecursive(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafRecursive(root->left) + countLeafRecursive(root->right);
}

//bai 5
 int findMaxValue(struct Node* root) {
    if (root == NULL) {
        printf("Cây rỗng!\n");
        return -99999; 
    }

    int max = root->data;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);

        if (current->data > max) {
            max = current->data;
        }

        if (current->left != NULL) {
            enqueue(&q, current->left);
        }

        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    return max;
}
//bai 6
int findLevel(Node* root, int value, int level) {
    if (root == NULL) return -1; 
    if (root->data == value) return level;
    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != -1) return leftLevel;
    return findLevel(root->right, value, level + 1);
}