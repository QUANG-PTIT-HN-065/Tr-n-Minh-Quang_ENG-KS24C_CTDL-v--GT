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


void addEdge(int graph[SIZE][SIZE], int nodeStart, int nodeEnd) {
    if (nodeStart >= 0 && nodeStart < SIZE && nodeEnd >= 0 && nodeEnd < SIZE) {
        graph[nodeStart][nodeEnd] = 1; 
    } else {
        printf("Chi so node khong hop le!\n");
    }
}


void printGraph(int graph[SIZE][SIZE]) {
    printf("Ma tran ke cua do thi co huong:\n[\n");
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
