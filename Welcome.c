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

    printf("���سɹ�\n");
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

//
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n') { }
}