#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc dữ liệu Order
typedef struct Order {
    int id;
    char customer[100];
    int status; // 0: chưa giao, 1: đã giao
    float total;
} Order;

// Node danh sách liên kết đôi (chưa giao)
typedef struct Node {
    Order data;
    struct Node* next;
    struct Node* prev;
} Node;

// Node danh sách liên kết đơn (đã giao)
typedef struct DeliveredNode {
    Order data;
    struct DeliveredNode* next;
} DeliveredNode;

Node* head = NULL;
DeliveredNode* deliveredHead = NULL;


Order nhapDonHang() {
    Order order;
    printf("Nhap ID: ");
    scanf("%d", &order.id);
    printf("Nhap ten khach hang: ");
    getchar();
    fgets(order.customer, sizeof(order.customer), stdin);
    order.customer[strcspn(order.customer, "\n")] = 0;
    printf("Nhap tong tien: ");
    scanf("%f", &order.total);
    order.status = 0;
    return order;
}


void themDonHang() {
    Order order = nhapDonHang();
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = order;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void hienThiDonHang() {
    printf("\n--- DANH SACH DON HANG CHUA GIAO ---\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("ID: %d | Ten: %s | Tien: %.2f | Trang thai: %s\n", 
            temp->data.id, temp->data.customer, temp->data.total,
            temp->data.status == 0 ? "Chua giao" : "Da giao");
        temp = temp->next;
    }

    printf("\n--- LICH SU DON HANG DA GIAO ---\n");
    DeliveredNode* dTemp = deliveredHead;
    while (dTemp != NULL) {
        printf("ID: %d | Ten: %s | Tien: %.2f | Trang thai: Da giao\n", 
            dTemp->data.id, dTemp->data.customer, dTemp->data.total);
        dTemp = dTemp->next;
    }
}


void xoaDonHang(int id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == id) {
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            free(temp);
            printf("Da xoa don hang ID %d\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay don hang ID %d\n", id);
}


void capNhatDonHang(int id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == id) {
            printf("Nhap ten moi: ");
            getchar();
            fgets(temp->data.customer, sizeof(temp->data.customer), stdin);
            temp->data.customer[strcspn(temp->data.customer, "\n")] = 0;
            printf("Nhap tong tien moi: ");
            scanf("%f", &temp->data.total);
            printf("Cap nhat thanh cong!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay don hang ID %d\n", id);
}


void danhDauDaGiao(int id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == id) {
            temp->data.status = 1;

            DeliveredNode* dNode = (DeliveredNode*)malloc(sizeof(DeliveredNode));
            dNode->data = temp->data;
            dNode->next = deliveredHead;
            deliveredHead = dNode;

            // Xóa khỏi danh sách chưa giao
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            free(temp);

            printf("Don hang da duoc danh dau la da giao!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay don hang ID %d\n", id);
}


void sapXepDonHang() {
    if (head == NULL || head->next == NULL) return;

    Node* i = head;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data.total > j->data.total) {
                Order temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }

    printf("Da sap xep don hang theo tong tien tang dan.\n");
}


void timKiemDonHang(char* ten) {
    int found = 0;
    printf("\n--- Ket qua tim kiem trong danh sach chua giao ---\n");
    Node* temp = head;
    while (temp != NULL) {
        if (strstr(temp->data.customer, ten)) {
            printf("ID: %d | Ten: %s | Tien: %.2f | Chua giao\n",
                temp->data.id, temp->data.customer, temp->data.total);
            found = 1;
        }
        temp = temp->next;
    }

    printf("\n--- Ket qua tim kiem trong lich su da giao ---\n");
    DeliveredNode* dTemp = deliveredHead;
    while (dTemp != NULL) {
        if (strstr(dTemp->data.customer, ten)) {
            printf("ID: %d | Ten: %s | Tien: %.2f | Da giao\n",
                dTemp->data.id, dTemp->data.customer, dTemp->data.total);
            found = 1;
        }
        dTemp = dTemp->next;
    }

    if (!found) {
        printf("Khong tim thay don hang nao voi ten chua '%s'\n", ten);
    }
}


void menu() {
    int choice;
    do {
        printf("\n\n========= ORDER MANAGER =========\n");
        printf("1. Them don hang moi\n");
        printf("2. Hien thi danh sach don hang\n");
        printf("3. Xoa don hang theo ID\n");
        printf("4. Cap nhat thong tin don hang\n");
        printf("5. Danh dau da giao\n");
        printf("6. Sap xep theo tong tien\n");
        printf("7. Tim kiem don hang theo ten\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        int id;
        char name[100];
        switch (choice) {
            case 1: themDonHang(); break;
            case 2: hienThiDonHang(); break;
            case 3:
                printf("Nhap ID don hang can xoa: ");
                scanf("%d", &id);
                xoaDonHang(id);
                break;
            case 4:
                printf("Nhap ID don hang can cap nhat: ");
                scanf("%d", &id);
                capNhatDonHang(id);
                break;
            case 5:
                printf("Nhap ID don hang da giao: ");
                scanf("%d", &id);
                danhDauDaGiao(id);
                break;
            case 6: sapXepDonHang(); break;
            case 7:
                printf("Nhap ten khach hang can tim: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                timKiemDonHang(name);
                break;
            case 8: printf("Ket thuc chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le.\n");
        }

    } while (choice != 8);
}


int main() {
    menu();
    return 0;
}
