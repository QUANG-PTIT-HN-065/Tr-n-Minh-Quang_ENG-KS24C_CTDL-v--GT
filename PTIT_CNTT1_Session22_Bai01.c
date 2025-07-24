#include <stdio.h>
#include <stdlib.h>


int initializeGraph(int n) {
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    return graph; 
}

void addEdge(int **graph, int node1, int node2,int n) {
    if (node1 >= 0 && node1 < n && node2 >= 0 && node2 < n) {
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;  
    } else {
        printf("Chi so node khong hop le! (Chi so phai tu 0 den %d)\n", n - 1);
    }
}

void printGraph(int **graph, int n) {
    printf("Ma tran ke:\n[\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("\t%d", graph[i][j]);
        }
        printf("\n");
    }
    printf("]\n");
}
void freeGraph(int **graph, int n) {
    for (int i = 0; i < n; i++) {
        free(graph[i]);  
    }
    free(graph);        
}


int main() {
    int n;
    printf("Nhap so luong node (n): ");
    scanf("%d", &n);

    int **graph = initializeGraph(n);

    addEdge(graph, 0, 1, n);
    addEdge(graph, 1, 2, n);
    addEdge(graph, 2, 0, n);

    printGraph(graph, n);

    freeGraph(graph,n);

    return 0;
}

