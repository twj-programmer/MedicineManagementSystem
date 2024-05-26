#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"

// 初始化载入
void Load(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    //读取药品信息
    FILE * fHead = fopen("./Medicine.txt", "r");
    if (fHead == NULL) {
        return;
    }
    Medicine * fresh = malloc(sizeof(Medicine));
    while ((fscanf_s(fHead, "%s", fresh -> name)) &&
           (fscanf_s(fHead, "%s", fresh -> code)) &&
           (fscanf_s(fHead, "%s", fresh -> production_date)) &&
           (fscanf_s(fHead, "%s", fresh -> shelf_life)) &&
           (fscanf_s(fHead, "%s", fresh -> entry_date)) &&
           (fscanf_s(fHead, "%s", fresh -> nature)) &&
           (fscanf_s(fHead, "%s", fresh -> attribute)) &&
           (fscanf_s(fHead, "%s", fresh -> symptoms)) &&
           (fscanf_s(fHead, "%d", &fresh -> quantity)) != EOF) {
        fresh -> next = head -> next;
        head -> next = fresh;
        fresh = malloc(sizeof(Medicine));
    }
    fclose(fHead);
    //读取进货信息
    FILE * fPurchaseList = fopen("./PurchaseList.txt", "r");
    if (fPurchaseList == NULL) {
        return;
    }
    PurchaseList * freshPurchaseList = malloc(sizeof(PurchaseList));
    while ((fscanf_s(fPurchaseList, "%s",freshPurchaseList -> name)) &&
           (fscanf_s(fPurchaseList, "%s",freshPurchaseList -> code)) &&
           (fscanf_s(fPurchaseList, "%d",&freshPurchaseList -> quantity)) != EOF) {
        freshPurchaseList -> next = purchaseList -> next;
        purchaseList -> next = freshPurchaseList;
        freshPurchaseList = malloc(sizeof(PurchaseList));
    }
    fclose(fPurchaseList);
    //读取销售信息
    FILE * fSellList = fopen("./SellList.txt", "r");
    if (fSellList == NULL) {
        return;
    }
    SellList * freshSellList = malloc(sizeof(SellList));
    while (fscanf_s(fSellList, "%s",freshSellList -> name) &&
          (fscanf_s(fSellList, "%s", freshSellList -> code)) &&
          (fscanf_s(fSellList, "%d", &freshSellList -> quantity)) != EOF) {
        freshSellList -> next = sellList -> next;
        sellList -> next = freshSellList;
        freshSellList = malloc(sizeof(SellList));
    }
    fclose(fSellList);

    printf("初始化载入成功\n");
    system("pause");
    system("cls");
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