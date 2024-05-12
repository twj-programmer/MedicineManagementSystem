#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"
#include "OperateMedicine.h"

int main() {
    //��ͷ��������
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
                printf("�����������������\n");
                break;
        }
        if (op == '0') {
            break;
        }
        clear_input_buffer();
    }
    return 0;
}