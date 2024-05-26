#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"

// ��ʼ������
void Load(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    //��ȡҩƷ��Ϣ
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
    //��ȡ������Ϣ
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
    //��ȡ������Ϣ
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

    printf("��ʼ������ɹ�\n");
    system("pause");
    system("cls");
}

//��ӭ����ľ���ʵ��
void Welcome() {
    printf("*****************************\n");
    printf("*        ҩƷ����ϵͳ          *\n");
    printf("*****************************\n");
    printf("*        ��ѡ�����б�        *\n");
    printf("*****************************\n");
    printf("*       1��ҩƷ�������        *\n");
    printf("*       2��ҩƷ���۳���        *\n");
    printf("*       3��ҩƷ������        *\n");
    printf("*       4�����ͳ������        *\n");
    printf("*       0�������˳�ϵͳ        *\n");
    printf("*****************************\n");
}

//��ȡ�û������ľ���ʵ��
char GetUserOP() {
    printf("���������Ĳ�����");
    char op = (char)getchar();
    (void)getchar(); //��ȡ�س�
    return op;
}