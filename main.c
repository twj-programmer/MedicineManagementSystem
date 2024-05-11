#include <stdio.h>
#include <stdlib.h>
#include "Medicine.h"
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
                statistics(head, purchaseList, sellList);
                break;
            case '0':
                printf("保存退出系统\n");
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