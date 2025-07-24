#include <stdio.h>
#include <stdlib.h>
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

void addEdge(Node** adjList, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printAdjList(Node** adjList, int n) {
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

int main() {
    int n;
    printf("Nhap vao sa dinh cua do thi: ");
    scanf("%d", &n);
    Node** adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    int m;
    printf("Nhap so luong canh: ");
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Nhap canh thu %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }
    printf("\nDanh sach ke :\n");
    printAdjList(adjList, n);
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adjList);

    return 0;
}
