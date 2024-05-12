#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"

void Load(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    FILE * fHead = fopen("./Medicine.txt", "r");
    if (fHead == NULL) {
        return;
    }
    Medicine * fresh = malloc(sizeof(Medicine));
    while (fscanf_s(fHead, "%s %s %s %d %s %s %s %s %s %d",
                    fresh -> name, fresh -> code,
                    fresh -> production_date, &fresh -> shelf_life, fresh -> entry_date,
                    fresh -> nature, fresh -> attribute, fresh -> symptoms,
                    &fresh -> quantity) != EOF) {
        fresh -> next = head -> next;
        head -> next = fresh;
        fresh = malloc(sizeof(Medicine));

    }
    free(fresh);
    fclose(fHead);

    FILE * fPurchaseList = fopen("./PurchaseList.txt", "r");
    if (fPurchaseList == NULL) {
        return;
    }
    PurchaseList * freshPurchaseList = malloc(sizeof(PurchaseList));
    while (fscanf_s(fPurchaseList, "%s %s %d",
                    freshPurchaseList -> name, freshPurchaseList -> code, &freshPurchaseList -> quantity) != EOF) {
        freshPurchaseList -> next = purchaseList -> next;
        purchaseList -> next = freshPurchaseList;
        freshPurchaseList = malloc(sizeof(PurchaseList));
    }
    free(freshPurchaseList);
    fclose(fPurchaseList);

    FILE * fSellList = fopen("./SellList.txt", "r");
    if (fSellList == NULL) {
        return;
    }
    SellList * freshSellList = malloc(sizeof(SellList));
    while (fscanf_s(fSellList, "%s %s %d",
                    freshSellList -> name, freshSellList -> code, &freshSellList -> quantity) != EOF) {
        freshSellList -> next = sellList -> next;
        sellList -> next = freshSellList;
        freshSellList = malloc(sizeof(SellList));
    }
    free(freshSellList);
    fclose(fSellList);

    printf("加载成功\n");
}

//欢迎界面的具体实现
void Welcome() {
    printf("*****************************\n");
    printf("*        药品管理系统          *\n");
    printf("*****************************\n");
    printf("*        请选择功能列表        *\n");
    printf("*****************************\n");
    printf("*       1：药品进货入库        *\n");
    printf("*       2：药品销售出库        *\n");
    printf("*       3：药品库存管理        *\n");
    printf("*       4：输出统计数据        *\n");
    printf("*       0：保存退出系统        *\n");
    printf("*****************************\n");
}

//获取用户操作的具体实现
char GetUserOP() {
    printf("请输入您的操作：");
    char op = (char)getchar();
    (void)getchar(); //读取回车
    return op;
}

//
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n') { }
}