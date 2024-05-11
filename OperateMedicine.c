#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medicine.h"

void PurchaseMedicine(Medicine * head, PurchaseList * purchaseList) {
    printf("进货入库\n");
    Medicine * newMedicine = (Medicine*)malloc(sizeof(Medicine));
    printf("请输入药品名称：");
    scanf("%s", newMedicine -> name);
    printf("请输入药品编码：");
    scanf("%s", newMedicine -> code);
    printf("请输入生产日期：");
    scanf("%s", newMedicine -> production_date);
    printf("请输入保质期（月）：");
    scanf_s("%d", &newMedicine -> shelf_life);
    printf("请输入入库时间：");
    scanf("%s", newMedicine -> entry_date);
    printf("请输入性质：");
    scanf("%s", newMedicine -> nature);
    printf("请输入属性：");
    scanf("%s", newMedicine -> attribute);
    printf("请输入适用症状：");
    scanf("%s", newMedicine -> symptoms);
    printf("请输入数量：");
    scanf_s("%lld", &newMedicine -> quantity);
    newMedicine -> next = head -> next;
    head -> next = newMedicine;

    int flg = 0;
    PurchaseList * pPurchaseList = purchaseList;
    while (pPurchaseList -> next != NULL) {
        if (strcmp(pPurchaseList -> next -> name, newMedicine -> name) == 0) {
            pPurchaseList -> next -> quantity += newMedicine -> quantity;
            flg = 1;
            break;
        }
        pPurchaseList = pPurchaseList -> next;
    }
    if (flg == 0) {
        PurchaseList * newPurchase = (PurchaseList *)malloc(sizeof(PurchaseList));
        strcpy(newPurchase -> name, newMedicine -> name);
        strcpy(newPurchase -> code, newMedicine -> code);
        newPurchase -> quantity = newMedicine -> quantity;
        newPurchase -> next = purchaseList -> next;
        purchaseList -> next = newPurchase;
    }
    (void)getchar(); //读取回车
    printf("是否继续进货入库？(y/n)");
    char op = (char)getchar();
    if (op == 'y' || op == 'Y') {
        PurchaseMedicine(head, purchaseList);
    }
    printf("入库成功\n");
}

void SellMedicine(Medicine * head, SellList * sellList) {
    printf("销售出库\n");
    char name[50];
    printf("请输入药品名称：");
    scanf("%s", name);
    char code[20];
    printf("请输入药品编码：");
    scanf("%s", code);
    int quantity;
    printf("请输入数量：");
    scanf_s("%d", &quantity);
    Medicine * p = head->next;
    while (p != NULL) {
        if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
            if (p->quantity < quantity) {
                printf("库存不足\n");
                return;
            }
            p -> quantity -= quantity;
            break;
        }
        p = p -> next;
    }
    if (p == NULL) {
        printf("未找到该药品\n");
        return;
    }

    SellList * pSellList = sellList;
    int flg = 0;
    while (pSellList -> next != NULL) {
        if (strcmp(pSellList -> next -> name, name) == 0) {
            pSellList -> next -> quantity += quantity;
            flg = 1;
            break;
        }
        pSellList = pSellList -> next;
    }
    if (flg == 0) {
        SellList * newSell = (SellList *)malloc(sizeof(SellList));
        strcpy(newSell -> name, name);
        strcpy(newSell -> code, code);
        newSell -> quantity = quantity;
        newSell -> next = sellList -> next;
        sellList -> next = newSell;
    }
    (void)getchar(); //读取回车
    printf("是否继续销售出库？(y/n)");
    char op = (char)getchar();
    if (op == 'y' || op == 'Y') {
        SellMedicine(head, sellList);
    }
    printf("出库成功\n");
}

void inventoryManagement(Medicine * head) {
    printf("库存管理\n");
    label:
    printf("输入操作\n");
    printf("a：修改药品信息\n");//默认名字和编码以及药品库存不修改
    printf("b：查询药品信息\n");
    char op = (char)getchar();
    if (op == 'a') {
        printf("修改药品信息\n");
        char name[50];
        printf("请输入药品名称：");
        scanf("%s", name);
        char code[20];
        printf("请输入药品编码：");
        scanf("%s", code);
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("请输入新的药品名称：");scanf("%s", p -> name);
                printf("请输入新的药品编码：");scanf("%s", p -> code);
                printf("请输入新的生产日期：");scanf("%s", p -> production_date);
                printf("请输入新的保质期（月）：");scanf_s("%d", &p -> shelf_life);
                printf("请输入新的入库时间：");scanf("%s", p -> entry_date);
                printf("请输入新的性质：");scanf("%s", p -> nature);
                printf("请输入新的属性：");scanf("%s", p -> attribute);
                printf("请输入新的适用症状：");scanf("%s", p -> symptoms);
                printf("请输入新的数量：");scanf_s("%d", &p -> quantity);
                break;
            }
            p = p -> next;
        }
        if (p == NULL) {
            printf("未找到该药品\n");
        }
    } else if (op == 'b') {
        printf("查询药品信息\n");
        char name[50];
        printf("请输入药品名称：");
        scanf("%s", name);
        char code[20];
        printf("请输入药品编码：");
        scanf("%s", code);
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("药品名称：%s\t", p -> name);
                printf("药品编码：%s\n", p -> code);
                printf("生产日期：%s\t", p -> production_date);
                printf("保质期（月）：%d\n", p -> shelf_life);
                printf("入库时间：%s\n", p -> entry_date);
                printf("性质：%s\t", p -> nature);
                printf("属性：%s\n", p -> attribute);
                printf("适用症状：%s\n", p -> symptoms);
                printf("数量：%d\n", p -> quantity);
                break;
            }
            p = p -> next;
        }
        if (p == NULL) {
            printf("未找到该药品\n");
        }
    } else {
        printf("输入错误，请重新输入\n");
        goto label;
    }
}
//
void statistics(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    printf("输出统计数据\n");
    label:
    printf("选择查询的数据\n");
    printf("a：查询进货数据\n");
    printf("b：查询销售数据\n");
    printf("c：查询库存数据\n");
    char op = (char)getchar();
    if (op == 'a') {
        printf("\t查询进货数据\n");
        PurchaseList * pPurchaseList = purchaseList -> next;
        while (pPurchaseList != NULL) {
            printf("药品名称：%s\t", pPurchaseList -> name);
            printf("药品编码：%s\n", pPurchaseList -> code);
            printf("数量：%d\n", pPurchaseList -> quantity);
            pPurchaseList = pPurchaseList -> next;
        }
        if (pPurchaseList == NULL) {
            printf("无进货数据\n");
            (void)getchar(); //读取回车
            printf("是否继续查询？(y/n)");
            char op1 = (char)getchar();
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
    } else if (op == 'b') {
        printf("查询销售数据\n");
        SellList * pSellList = sellList -> next;
        while (pSellList != NULL) {
            printf("药品名称：%s\t", pSellList -> name);
            printf("药品编码：%s\n", pSellList -> code);
            printf("数量：%d\n", pSellList -> quantity);
            pSellList = pSellList -> next;
        }
        if (purchaseList -> next == NULL) {
            printf("无销售数据\n");
            (void)getchar(); //读取回车
            printf("是否继续查询？(y/n)");
            char op1 = (char)getchar();
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
    } else if (op == 'c') {
        printf("查询库存数据\n");
        Medicine * p = head -> next;
        while (p != NULL) {
            printf("药品名称：%s\t", p -> name);
            printf("药品编码：%s\n", p -> code);
            printf("数量：%d\n", p -> quantity);
            p = p -> next;
        }
        if (head -> next == NULL) {
            printf("无库存数据\n");
            (void)getchar(); //读取回车
            printf("是否继续查询？(y/n)");
            char op1 = (char)getchar();
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
    } else {
        printf("输入错误，请重新输入\n");
        goto label;
    }
}