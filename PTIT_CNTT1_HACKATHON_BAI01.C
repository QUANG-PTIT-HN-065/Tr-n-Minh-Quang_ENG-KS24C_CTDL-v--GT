#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    char category[100];
    float price;
} Food;

typedef struct Node
{
    Food data;
    struct Node *next;
} Node;
typedef struct Node2
{
    Food data;
    struct Node2 *next;
    struct Node2 *per;
} Node2;

int id = 1;

Node *createNode(char name[], char category[], float price)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.id = id++;
    strcpy(newNode->data.name, name);
    strcpy(newNode->data.category, category);
    newNode->data.price = price;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node **head, Node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void printNode(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }

    while (head != NULL)
    {
        printf("ID: %d\n", head->data.id);
        printf("Ten mon: %s\n", head->data.name);
        printf("Danh muc: %s\n", head->data.category);
        printf("Gia: %.2f\n", head->data.price);
        printf("--------------------------\n");
        head = head->next;
    }
}

void updateFood(Node *head, int id)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            char name[100];
            char category[100];
            float price;
            printf("Thong tin hien tai:\n");
            printf("ID: %d\n", temp->data.id);
            printf("Ten mon: %s\n", temp->data.name);
            printf("Danh muc: %s\n", temp->data.category);
            printf("Gia: %.2f\n", temp->data.price);
            printf("--------------------------\n");
            printf("Nhap ten mon an moi: ");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Nhap danh muc mon an moi: ");
            fgets(category, sizeof(category), stdin);
            category[strcspn(category, "\n")] = '\0';

            printf("Nhap gia tien moi: ");
            scanf("%f", &price);
            getchar();
            strcpy(temp->data.name, name);
            strcpy(temp->data.category, category);
            temp->data.price = price;

            printf("Cap nhat thanh cong!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Khong tim thay mon an voi ID = %d\n", id);
}
void printNode2(Node2 *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }

    while (head != NULL)
    {
        printf("ID: %d\n", head->data.id);
        printf("Ten mon: %s\n", head->data.name);
        printf("Danh muc: %s\n", head->data.category);
        printf("Gia: %.2f\n", head->data.price);
        printf("--------------------------\n");
        head = head->next;
    }
}

void search(Node *head, char name[])
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (strstr(temp->data.name, name))
        {
            printf("ID: %d\n", temp->data.id);
            printf("Ten mon: %s\n", temp->data.name);
            printf("Danh muc: %s\n", temp->data.category);
            printf("Gia: %.2f\n", temp->data.price);
            printf("--------------------------\n");
            return;
        }
        temp = temp->next;
    }
    printf("khong tin thay");
}

void sort(Node *head)
{

    if (head == NULL || head->next == NULL)
        return;
    for (Node *i = head; i != NULL; i = i->next)
    {
        bool check = true;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data.price > j->data.price)
            {
                Food temp = i->data;
                i->data = j->data;
                j->data = temp;
                check = false;
            }
        }
        if (check)
        {
            break;
        }
    }
}
Node2 *createNode2(Food food)
{
    Node2 *newNode = (Node2 *)malloc(sizeof(Node2));
    newNode->data = food;
    newNode->next = NULL;
    newNode->per = NULL;
    return newNode;
}
void appendNode2(Node2 **head, Node2 *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node2 *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->per = temp;
    }
}
void moveList(Node **head, Node2 **head2, int id)
{
    Node *temp = *head, *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            Node2 *newNode2 = createNode2(temp->data);
            appendNode2(head2, newNode2);
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Da chuyen mon an co ID %d sang danh sach da ngung ban.\n", id);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Khong tim thay mon an voi ID = %d trong danh sach dang ban.\n", id);
}

int main()
{
    Node *head = NULL;
    Node2 *head2 = NULL;
    int choice;

    do
    {
        printf("=============RESTAURANT===========\n");
        printf("1. Them mon an\n");
        printf("2. Hien thi danh sach mon dang ban\n");
        printf("3. Cap nhat thong tin mon an\n");
        printf("4. Danh dau ngung ban (chuyen sang danh sach mon ngung ban)\n");
        printf("5. Hien thi danh sach mon da ngung ban\n");
        printf("6. Tim kiem theo ten mon\n");
        printf("7. Sap xep mon theo gia tang dan\n");
        printf("8. Thoat chuong trinh\n");
        printf("----------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
        {
            system("cls");
            char name[100];
            char category[100];
            float price;

            printf("Nhap ten mon an: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Nhap danh muc mon an: ");
            fgets(category, sizeof(category), stdin);
            category[strcspn(category, "\n")] = '\0';

            printf("Nhap gia tien: ");
            scanf("%f", &price);
            getchar();

            Node *newNode = createNode(name, category, price);
            appendNode(&head, newNode);
            break;
        }
        case 2:
            system("cls");
            printNode(head);
            break;
        case 3:
            int id1;
            printf("nhap id mon an: ");
            scanf("%d", &id1);
            updateFood(head, id1);
            break;
        case 4:
            system("cls");
            int id2;
            printf("Nhap vao ID can chuyen: ");
            scanf("%d", &id2);
            moveList(&head, &head2, id2);
            break;
        case 5:
            system("cls");
            printNode2(head2);
            break;
        case 6:
            system("cls");
            char name[100];
            printf("nhap vao ten mon can tin:");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            search(head, name);
            break;
        case 7:
            system("cls");
            sort(head);
            printf("da xap xep xong\n");
            break;
        case 8:
            system("cls");
            printf("thoat chuong trinh");
            break;
        default:
            system("cls");
            printf("nhap ko hop le");
            break;
        }
    } while (choice != 8);

    return 0;
}
