#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int capacity;
    int size;
} Stack;

// Tạo stack
Stack createStack(int maxSize) {
    Stack s;
    s.top = NULL;
    s.capacity = maxSize;
    s.size = 0;
    return s;
}

// Thêm phần tử vào stack
void push(Stack* s, int value) {
    if (s->size == s->capacity) {
        printf("Stack đầy, không thể thêm %d\n", value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// Lấy phần tử khỏi stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack rỗng! Không thể lấy phần tử.\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return value;
}

// In stack
void printStack(Stack s) {
    if (s.top == NULL) {
        printf("Ngăn xếp đang rỗng!\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp (từ trên xuống dưới):\n");
    Node* temp = s.top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Đảo ngược mảng bằng stack
void reverseArray(int arr[], int n) {
    Stack s = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

// Kiểm tra chuỗi đối xứng
bool isPalindrome(char str[]) {
    int len = strlen(str);
    Stack s = createStack(len / 2);
    for (int i = 0; i < len / 2; i++) {
        push(&s, (int)str[i]);  
    }

    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    for (int i = start; i < len; i++) {
        char topChar = (char)pop(&s);
        if (topChar != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    Stack myStack = createStack(5);
    // Nhập dữ liệu cho stack
    for (int i = 0; i < 5; i++) {
        int value;
        printf("Nhập số nguyên thứ %d: ", i + 1);
        scanf("%d", &value);
        push(&myStack, value);
    }

    printStack(myStack);

    int arr[5];
    for (int i = 0; i < 5; i++) arr[i] = i + 1;
    reverseArray(arr, 5);
    printf("\nMảng sau khi đảo ngược:\n");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    char chuoi[100];
    printf("\nNhập chuỗi để kiểm tra đối xứng: ");
    scanf("%s", chuoi);
    if (isPalindrome(chuoi)) {
        printf("Chuỗi \"%s\" là đối xứng.\n", chuoi);
    } else {
        printf("Chuỗi \"%s\" không đối xứng.\n", chuoi);
    }

    return 0;
}
