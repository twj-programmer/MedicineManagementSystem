#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"
#include "OperateMedicine.h"

int main() {
    //带头结点的链表
    Medicine * head = (Medicine *)malloc(sizeof(Medicine));
    head->next = NULL;

    PurchaseList * purchaseList = (PurchaseList *)malloc(sizeof(PurchaseList));
    purchaseList->next = NULL;

    SellList * sellList = (SellList *)malloc(sizeof(SellList));
    sellList->next = NULL;

    Load(head, purchaseList, sellList);

    while (true) {
        Welcome();
        char op = GetUserOP();
        switch (op) {
            case '1':
                PurchaseMedicine(head, purchaseList);
                break;
            case '2':
                SellMedicine(head, sellList);
                break;
            case '3':
                inventoryManagement(head);
                break;
            case '4':
                Statistics(head, purchaseList, sellList);
                break;
            case '0':
                Save(head, purchaseList, sellList);
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
        if (op == '0') {
            break;
        }
        clear_input_buffer();
    }
    return 0;
}