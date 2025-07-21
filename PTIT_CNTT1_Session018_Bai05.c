#include<stdio.h>
#include<stdlib.h>
#include "funtion.c"

int main() {
    int data;
    inputTree();
    printf("Enter data for the root node: ");
    scanf("%d", &data);
    searchNode(root, data);
    return 0;
}