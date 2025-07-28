#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Operation {
    char url[100];
    char timeStamp[100];
    struct Operation* next;
} Operation;


typedef struct Stack {
    Operation* top;
} Stack;

void getCurrentTime(char* buffer, int size) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}


Operation* createOperation(const char* url) {
    Operation* op = (Operation*)malloc(sizeof(Operation));
    strcpy(op->url, url);
    getCurrentTime(op->timeStamp, sizeof(op->timeStamp));
    op->next = NULL;
    return op;
}


void initStack(Stack* stack) {
    stack->top = NULL;
}


void push(Stack* stack, Operation* op) {
    op->next = stack->top;
    stack->top = op;
}


Operation* pop(Stack* stack) {
    if (stack->top == NULL) return NULL;
    Operation* temp = stack->top;
    stack->top = stack->top->next;
    temp->next = NULL;
    return temp;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void printOperation(Operation* op) {
    if (op != NULL) {
        printf("Trang hiện tại: %s\n", op->url);
        printf("Thời gian truy cập: %s\n", op->timeStamp);
    } else {
        printf("Không có trang nào đang mở.\n");
    }
}

void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        Operation* temp = pop(stack);
        free(temp);
    }
}

int main() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);
    Operation* current = NULL;

    char command[100];

    while (1) {
        printf("\n——————— WEB HISTORY ———————\n");
        printf("Nhap lenh (VISIT, BACKWARD, FORWARD, CURRENT, THOAT): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "VISIT", 5) == 0) {
            char url[100];
            sscanf(command + 6, "%s", url); 
            if (strlen(url) == 0) {
                printf("URL không hợp lệ.\n");
                continue;
            }

            if (current != NULL) push(&backStack, current);
            current = createOperation(url);
            clearStack(&forwardStack); 
            printf("Đã truy cập %s\n", url);
        }
        else if (strcmp(command, "BACKWARD") == 0) {
            if (isEmpty(&backStack)) {
                printf("Không thể quay lại.\n");
            } else {
                push(&forwardStack, current);
                current = pop(&backStack);
                printf("Đã quay lại trang trước.\n");
            }
        }
        else if (strcmp(command, "FORWARD") == 0) {
            if (isEmpty(&forwardStack)) {
                printf("Không thể đi tiếp.\n");
            } else {
                push(&backStack, current);
                current = pop(&forwardStack);
                printf("Đã đi tới trang tiếp theo.\n");
            }
        }
        else if (strcmp(command, "CURRENT") == 0) {
            printOperation(current);
        }
        else if (strcmp(command, "THOAT") == 0) {
            printf("Thoát chương trình.\n");
            break;
        }
        else {
            printf("Lệnh không hợp lệ. Vui lòng thử lại.\n");
        }
    }

    clearStack(&backStack);
    clearStack(&forwardStack);
    free(current);
    return 0;
}
