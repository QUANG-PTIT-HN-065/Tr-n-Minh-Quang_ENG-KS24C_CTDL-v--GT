#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void converList(int matrix[MAX][MAX], Node* adjList[MAX], int n) {
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL; 
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                Node* newNode = createNode(j);
                newNode->next = adjList[i];
                adjList[i] = newNode;
            }
        }
    }
}

void printAdjList(Node* adjList[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("dinh %d: ", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeAdjList(Node* adjList[MAX], int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];
    Node* adjList[MAX];
    do {
        printf("Nhap so dinh (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);
    printf("Nhap ma tran ke (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("matrix[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            } while (matrix[i][j] != 0 && matrix[i][j] != 1);
        }
    }
    converList(matrix, adjList, n);
    printf("\nDanh sach ke:\n");
    printAdjList(adjList, n);
    freeAdjList(adjList, n);

    return 0;
}
