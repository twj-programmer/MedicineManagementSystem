#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Medicine.h"
// 用户选择1: 进货入库
void PurchaseMedicine(Medicine * head, PurchaseList * purchaseList) {
    printf("\t进货入库\n");
    label:
    /**
     * 这里默认每次进货时相同药品的生产日期不同
     * 因此每次进货时单独为其创建一个新的药品节点
     */
    Medicine * newMedicine = (Medicine*)malloc(sizeof(Medicine));
    printf("请输入药品名称：");scanf("%s", newMedicine -> name);(void)getchar(); //读取回车
    printf("请输入药品编码：");scanf("%s", newMedicine -> code);(void)getchar(); //读取回车
    printf("请输入生产日期：");scanf("%s", newMedicine -> production_date);(void)getchar(); //读取回车
    printf("请输入保质期（月）：");scanf("%s", newMedicine -> shelf_life);(void)getchar(); //读取回车
    printf("请输入入库时间：");scanf("%s", newMedicine -> entry_date);(void)getchar(); //读取回车
    printf("请输入性质：");scanf("%s", newMedicine -> nature);(void)getchar(); //读取回车
    printf("请输入属性：");scanf("%s", newMedicine -> attribute);(void)getchar(); //读取回车
    printf("请输入适用症状：");scanf("%s", newMedicine -> symptoms);(void)getchar(); //读取回车
    printf("请输入数量：");scanf_s("%d", &newMedicine -> quantity);(void)getchar(); //读取回车
    newMedicine -> next = head -> next;
    head -> next = newMedicine;
    /**
     * 这里仅统计某种药品进货总的数量
     * 不对药品其他属性进行区分
     */
    int flg = 0;
    PurchaseList * pPurchaseList = purchaseList;
    pPurchaseList = pPurchaseList -> next;
    while (pPurchaseList != NULL) {
        if (strcmp(pPurchaseList -> name, newMedicine -> name) == 0) {
            pPurchaseList -> quantity += newMedicine -> quantity;
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
    printf("入库成功\n");
    sleep(1);
    printf("是否继续进货入库？(y/n)");
    char op = (char)getchar();
    (void)getchar(); //读取回车
    if (op == 'y' || op == 'Y') {
        goto label;
    }
}
// 销售出库
void SellMedicine(Medicine * head, SellList * sellList) {
    printf("\t销售出库\n");
    label:
    char name[50];
    printf("请输入药品名称：");scanf("%s", name);(void)getchar(); //读取回车
    char code[20];
    printf("请输入药品编码：");scanf("%s", code);(void)getchar(); //读取回车
    int quantity;
    printf("请输入数量：");scanf_s("%d", &quantity);(void)getchar(); //读取回车
    Medicine * p = head->next;
    while (p != NULL) {
        if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
            if (p->quantity < quantity) {
                printf("库存不足\n");
                sleep(3);
                return;
            }
            p -> quantity -= quantity;
            break;
        }
        p = p -> next;
    }
    if (p == NULL) {
        printf("未找到该药品\n");
        system("pause");
        return;
    }
    /**
     * 这里仅统计某种药品销售总的数量
     * 不对药品其他属性进行区分
     */
    SellList * pSellList = sellList;
    int flg = 0;
    pSellList = pSellList -> next;
    while (pSellList != NULL) {
        if (strcmp(pSellList -> name, name) == 0) {
            pSellList -> quantity += quantity;
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
    printf("出库成功\n");
    sleep(1);
    printf("是否继续销售出库？(y/n)");
    char op = (char)getchar();
    (void)getchar(); //读取回车
    if (op == 'y' || op == 'Y') {
        goto label;
    }
}
// 库存管理
void inventoryManagement(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    printf("\t库存管理\n");
    label:
    printf("输入操作\n");
    printf("a：修改药品信息\n");
    printf("b：查询药品信息\n");

    char op = (char)getchar();
    (void)getchar(); //读取回车
    if (op == 'a') {
        printf("\t修改药品信息\n");
        /**
         * 输入原药品的名称和编码
         * 通过名称和编码找到原药品并修改其信息
         */
        char name[50];
        printf("请输入药品名称：");scanf("%s", name);(void)getchar(); //读取回车
        char code[20];
        printf("请输入药品编码：");scanf("%s", code);(void)getchar(); //读取回车
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("请输入新的药品名称：");scanf("%s", p -> name);(void)getchar(); //读取回车
                printf("请输入新的药品编码：");scanf("%s", p -> code);(void)getchar(); //读取回车
                printf("请输入新的生产日期：");scanf("%s", p -> production_date);(void)getchar(); //读取回车
                printf("请输入新的保质期（月）：");scanf("%s", p -> shelf_life);(void)getchar(); //读取回车
                printf("请输入新的入库时间：");scanf("%s", p -> entry_date);(void)getchar(); //读取回车
                printf("请输入新的性质：");scanf("%s", p -> nature);(void)getchar(); //读取回车
                printf("请输入新的属性：");scanf("%s", p -> attribute);(void)getchar(); //读取回车
                printf("请输入新的适用症状：");scanf("%s", p -> symptoms);(void)getchar(); //读取回车
                printf("请输入新的数量：");scanf_s("%d", &p -> quantity);(void)getchar(); //读取回车
                break;
            }
            p = p -> next;
        }
        PurchaseList * pPurchaseList = purchaseList -> next;
        while (pPurchaseList != NULL) {
            if (strcmp(pPurchaseList -> name, name) == 0 && strcmp(pPurchaseList -> code, code) == 0) {
                strcpy(pPurchaseList -> name, name);
                strcpy(pPurchaseList -> code, code);
                break;
            }
            pPurchaseList = pPurchaseList -> next;
        }
        SellList * pSellList = sellList -> next;
        while (pSellList != NULL) {
            if (strcmp(pSellList -> name, name) == 0 && strcmp(pSellList -> code, code) == 0) {
                strcpy(pSellList -> name, name);
                strcpy(pSellList -> code, code);
                break;
            }
            pSellList = pSellList -> next;
        }
        if (p == NULL) {
            printf("未找到该药品\n");
            system("pause");
        }
        printf("修改成功\n");
        system("pause");
    } else if (op == 'b') {
        printf("\t查询药品信息\n");
        char name[50];
        printf("请输入药品名称：");scanf("%s", name);(void)getchar(); //读取回车
        char code[20];
        printf("请输入药品编码：");scanf("%s", code);(void)getchar(); //读取回车
        /**
         * 这里找到药品后并没有直接break
         * 而是继续查找是否有相同的药品（生产日期不同）
         */
        int flg = 0;
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("药品名称：%s\t", p -> name);
                printf("药品编码：%s\n", p -> code);
                printf("生产日期：%s\t", p -> production_date);
                printf("保质期（月）：%s\n", p -> shelf_life);
                printf("入库时间：%s\n", p -> entry_date);
                printf("性质：%s\t", p -> nature);
                printf("属性：%s\n", p -> attribute);
                printf("适用症状：%s\n", p -> symptoms);
                printf("数量：%d\n\n", p -> quantity);
                flg = 1;
            }
            p = p -> next;
        }
        if (flg == 0) {
            printf("未找到该药品\n");
        }
        system("pause");
    } else {
        printf("输入错误，请重新输入\n");
        goto label;
    }
}
// 输出统计数据
void Statistics(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    printf("\t输出统计数据\n");
    label:
    printf("选择查询的数据\n");
    printf("a：查询进货数据\n");
    printf("b：查询销售数据\n");
    printf("c：查询库存数据\n");
    char op = (char)getchar();
    (void)getchar(); //读取回车
    if (op == 'a') {
        printf("\t查询进货数据\n");
        PurchaseList * pPurchaseList = purchaseList -> next;
        if (pPurchaseList == NULL) {
            printf("无进货数据\n");
            sleep(1);
            printf("是否继续查询？(y/n)");
            char op1 = (char)getchar();
            (void)getchar(); //读取回车
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
        while (pPurchaseList != NULL) {
            printf("药品名称：%s\t", pPurchaseList -> name);
            printf("药品编码：%s\n", pPurchaseList -> code);
            printf("进货数量：%d\n", pPurchaseList -> quantity);
            pPurchaseList = pPurchaseList -> next;
        }
        system("pause");
    } else if (op == 'b') {
        printf("\t查询销售数据\n");
        SellList * pSellList = sellList -> next;
        if (pSellList == NULL) {
            printf("无销售数据\n");
            sleep(1);
            printf("是否继续查询？(y/n)");
            char op1 = (char)getchar();
            (void)getchar(); //读取回车
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
        while (pSellList != NULL) {
            printf("药品名称：%s\t", pSellList -> name);
            printf("药品编码：%s\n", pSellList -> code);
            printf("售出数量：%d\n", pSellList -> quantity);
            pSellList = pSellList -> next;
        }
        system("pause");
    } else if (op == 'c') {
        printf("\t查询库存数据\n");
        Medicine * p = head -> next;
        if (p == NULL) {
            printf("无库存数据\n");
            sleep(1);
            printf("是否继续查询？(y/n)");
            char op1 = (char)getchar();
            (void)getchar(); //读取回车
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
        while (p != NULL) {
            printf("药品名称：%s\t", p -> name);
            printf("药品编码：%s\n", p -> code);
            printf("库存数量：%d\n", p -> quantity);
            p = p -> next;
        }
        system("pause");
    } else {
        printf("输入错误，请重新输入\n");
        sleep(1);
        goto label;
    }
}
// 保存药品信息
void Save(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    FILE * fHead = fopen("./Medicine.txt", "w");
    Medicine * pHead = head -> next;
    while (pHead != NULL) {
        fprintf(fHead, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
                pHead -> name, pHead -> code,
                pHead -> production_date, pHead -> shelf_life,
                pHead -> entry_date, pHead -> nature, pHead -> attribute,
                pHead -> symptoms, pHead -> quantity);
        pHead = pHead -> next;
    }
    fclose(fHead);

    FILE * fPurchaseList = fopen("./PurchaseList.txt", "w");
    PurchaseList * pPurchaseList = purchaseList -> next;
    while (pPurchaseList != NULL) {
        fprintf(fPurchaseList, "%s\t%s\t%d\n",
                pPurchaseList -> name, pPurchaseList -> code,
                pPurchaseList -> quantity);
        pPurchaseList = pPurchaseList -> next;
    }
    fclose(fPurchaseList);

    FILE * fSellList = fopen("./SellList.txt", "w");
    SellList * pSellList = sellList -> next;
    while (pSellList != NULL) {
        fprintf(fSellList, "%s\t%s\t%d\n",
                pSellList -> name, pSellList -> code,
                pSellList -> quantity);
        pSellList = pSellList -> next;
    }
    fclose(fSellList);

    printf("保存成功\n");
    sleep(1);
}