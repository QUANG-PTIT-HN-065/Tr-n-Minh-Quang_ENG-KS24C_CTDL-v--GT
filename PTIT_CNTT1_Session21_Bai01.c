#include <stdio.h>
#include <stdlib.h>

#define SIZE 3  

void initializeGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int node1, int node2) {
    if (node1 >= 0 && node1 < SIZE && node2 >= 0 && node2 < SIZE) {
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;  
    } else {
        printf("Chi so node khong hop le! (Chi so phai tu 0 den %d)\n", SIZE - 1);
    }
}

void printGraph(int graph[SIZE][SIZE]) {
    printf("Ma tran ke:\n[\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("\t%d", graph[i][j]);
        }
        printf("\n");
    }
    printf("]\n");
}

int main() {
    int graph[SIZE][SIZE];

    initializeGraph(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}
