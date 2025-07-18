#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int id;
    char title[100];
    int Priority;
    char Deadline[100];
} Quest;

typedef struct Node
{
    Quest data;
    struct Node *next;
} Node;
typedef struct Node2
{
    Quest data;
    struct Node2 *next;
    struct Node2 *per;
} Node2;

int id = 1;

void deleteID(Node **head, int id)
{
    Node *temp = *head;
    Node *prev = NULL;
    if (temp != NULL && temp->data.id == id)
    {
        *head = temp->next;
        free(temp);
        printf("Đã xoá ID %d\n", id);
        return;
    }
    while (temp != NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Không tìm thấy ID %d\n", id);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Đã xoá ID %d\n", id);
}

Node *createNode(char title[], char Deadline[], int Priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.id = id++;
    strcpy(newNode->data.title, title);
    strcpy(newNode->data.Deadline, Deadline);
    newNode->data.Priority = Priority;
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
        printf("Ten nhiem vu: %s\n", head->data.title);
        printf("muc do uu tien: %d\n", head->data.Priority);
        printf("thoi gian: %s\n", head->data.Deadline);
        printf("--------------------------\n");
        head = head->next;
    }
}

void updateQuest(Node *head, int id)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            char title[100];
            int Priority;
            char Deadline[100];
            printf("Thong tin hien tai:\n");
            printf("ID: %d\n", temp->data.id);
            printf("Ten nhiem vu: %s\n", temp->data.title);
            printf("Muc do uu tien: %d\n", temp->data.Priority);
            printf("thoi gian: %s\n", temp->data.Deadline);
            printf("--------------------------\n");
            printf("Nhap ten mon an moi: ");
            getchar();
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';

            printf("Nhap thoi gian: ");
            fgets(Deadline, sizeof(Deadline), stdin);
            Deadline[strcspn(Deadline, "\n")] = '\0';

            printf("Nhap muc uu tien: ");
            scanf("%d", &Priority);
            getchar();
            strcpy(temp->data.title, title);
            strcpy(temp->data.Deadline, Deadline);
            temp->data.Priority = Priority;

            printf("Cap nhat thanh cong!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Khong tim thay mon an voi ID = %d\n", id);
}

void search(Node *head, char title[])
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (strstr(temp->data.title, title))
        {
            printf("ID: %d\n", temp->data.id);
            printf("Ten nhiem vu: %s\n", temp->data.title);
            printf("muc do uu tien: %d\n", temp->data.Priority);
            printf("thoi gian: %s\n", temp->data.Deadline);
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
            if (i->data.Priority > j->data.Priority)
            {
                Quest temp = i->data;
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
Node2 *createNode2(Quest Quest)
{
    Node2 *newNode = (Node2 *)malloc(sizeof(Node2));
    newNode->data = Quest;
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
            printf("Da chuyen nhiem vu co ID %d sang da hoan thanh.\n", id);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Khong tim thay ID %d \n", id);
}

int main()
{
    Node *head = NULL;
    Node2 *head2 = NULL;
    int choice;

    do
    {
        printf("=============Quest===========\n");
        printf("1. Them nhiem vu\n");
        printf("2. Hien thi nhiem vu\n");
        printf("3. xoa nhiem vu\n");
        printf("4. cap nhat thong tin nhiem vu\n");
        printf("5. danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. Tim kiem nhiem vu\n");
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
            char title[100];
            char Deadline[100];
            int Priority;

            printf("Nhap ten nhiem vu: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';

            printf("Nhap thoi gian nhien vu: ");
            fgets(Deadline, sizeof(Deadline), stdin);
            Deadline[strcspn(Deadline, "\n")] = '\0';

            printf("Nhap muc do uu tien: ");
            scanf("%d", &Priority);
            getchar();

            Node *newNode = createNode(title, Deadline, Priority);
            appendNode(&head, newNode);
            break;
        }
        case 2:
            system("cls");
            printNode(head);
            break;
        case 3:{
            int id1;
            printf("nhap id nhiem vu: ");
            scanf("%d", &id1);
            deleteID(&head, id1);
            break;
        }
        case 4:{
            system("cls");
            int id2;
            printf("Nhap vao ID can cap nhat: ");
            scanf("%d", &id2);
            updateQuest(head, id2);
            break;
        }
        case 5:
            system("cls");
            int id3;
            printf("Nhap ID nhiem vu hoan thanh: ");
            scanf("%d", &id3);
            moveList(&head, &head2, id3);
            break;
        case 6:
            system("cls");
            sort(head);
            printf("da xap xep xong\n");
            break;
        case 7:{
            char searchTitle[100];
            getchar();
            printf("nhap vao ten nhiem vu can tim: ");
            fgets(searchTitle, sizeof(searchTitle), stdin);
            searchTitle[strcspn(searchTitle, "\n")] = '\0';
            search(head, searchTitle);
            break;
        }
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
