#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medicine.h"

void PurchaseMedicine(Medicine * head, PurchaseList * purchaseList) {
    printf("�������\n");
    Medicine * newMedicine = (Medicine*)malloc(sizeof(Medicine));
    printf("������ҩƷ���ƣ�");
    scanf("%s", newMedicine -> name);
    printf("������ҩƷ���룺");
    scanf("%s", newMedicine -> code);
    printf("�������������ڣ�");
    scanf("%s", newMedicine -> production_date);
    printf("�����뱣���ڣ��£���");
    scanf_s("%d", &newMedicine -> shelf_life);
    printf("���������ʱ�䣺");
    scanf("%s", newMedicine -> entry_date);
    printf("���������ʣ�");
    scanf("%s", newMedicine -> nature);
    printf("���������ԣ�");
    scanf("%s", newMedicine -> attribute);
    printf("����������֢״��");
    scanf("%s", newMedicine -> symptoms);
    printf("������������");
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
    (void)getchar(); //��ȡ�س�
    printf("�Ƿ����������⣿(y/n)");
    char op = (char)getchar();
    if (op == 'y' || op == 'Y') {
        PurchaseMedicine(head, purchaseList);
    }
    printf("���ɹ�\n");
}

void SellMedicine(Medicine * head, SellList * sellList) {
    printf("���۳���\n");
    char name[50];
    printf("������ҩƷ���ƣ�");
    scanf("%s", name);
    char code[20];
    printf("������ҩƷ���룺");
    scanf("%s", code);
    int quantity;
    printf("������������");
    scanf_s("%d", &quantity);
    Medicine * p = head->next;
    while (p != NULL) {
        if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
            if (p->quantity < quantity) {
                printf("��治��\n");
                return;
            }
            p -> quantity -= quantity;
            break;
        }
        p = p -> next;
    }
    if (p == NULL) {
        printf("δ�ҵ���ҩƷ\n");
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
    (void)getchar(); //��ȡ�س�
    printf("�Ƿ�������۳��⣿(y/n)");
    char op = (char)getchar();
    if (op == 'y' || op == 'Y') {
        SellMedicine(head, sellList);
    }
    printf("����ɹ�\n");
}

void inventoryManagement(Medicine * head) {
    printf("������\n");
    label:
    printf("�������\n");
    printf("a���޸�ҩƷ��Ϣ\n");//Ĭ�����ֺͱ����Լ�ҩƷ��治�޸�
    printf("b����ѯҩƷ��Ϣ\n");
    char op = (char)getchar();
    if (op == 'a') {
        printf("�޸�ҩƷ��Ϣ\n");
        char name[50];
        printf("������ҩƷ���ƣ�");
        scanf("%s", name);
        char code[20];
        printf("������ҩƷ���룺");
        scanf("%s", code);
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("�������µ�ҩƷ���ƣ�");scanf("%s", p -> name);
                printf("�������µ�ҩƷ���룺");scanf("%s", p -> code);
                printf("�������µ��������ڣ�");scanf("%s", p -> production_date);
                printf("�������µı����ڣ��£���");scanf_s("%d", &p -> shelf_life);
                printf("�������µ����ʱ�䣺");scanf("%s", p -> entry_date);
                printf("�������µ����ʣ�");scanf("%s", p -> nature);
                printf("�������µ����ԣ�");scanf("%s", p -> attribute);
                printf("�������µ�����֢״��");scanf("%s", p -> symptoms);
                printf("�������µ�������");scanf_s("%d", &p -> quantity);
                break;
            }
            p = p -> next;
        }
        if (p == NULL) {
            printf("δ�ҵ���ҩƷ\n");
        }
    } else if (op == 'b') {
        printf("��ѯҩƷ��Ϣ\n");
        char name[50];
        printf("������ҩƷ���ƣ�");
        scanf("%s", name);
        char code[20];
        printf("������ҩƷ���룺");
        scanf("%s", code);
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("ҩƷ���ƣ�%s\t", p -> name);
                printf("ҩƷ���룺%s\n", p -> code);
                printf("�������ڣ�%s\t", p -> production_date);
                printf("�����ڣ��£���%d\n", p -> shelf_life);
                printf("���ʱ�䣺%s\n", p -> entry_date);
                printf("���ʣ�%s\t", p -> nature);
                printf("���ԣ�%s\n", p -> attribute);
                printf("����֢״��%s\n", p -> symptoms);
                printf("������%d\n", p -> quantity);
                break;
            }
            p = p -> next;
        }
        if (p == NULL) {
            printf("δ�ҵ���ҩƷ\n");
        }
    } else {
        printf("�����������������\n");
        goto label;
    }
}
//
void statistics(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    printf("���ͳ������\n");
    label:
    printf("ѡ���ѯ������\n");
    printf("a����ѯ��������\n");
    printf("b����ѯ��������\n");
    printf("c����ѯ�������\n");
    char op = (char)getchar();
    if (op == 'a') {
        printf("\t��ѯ��������\n");
        PurchaseList * pPurchaseList = purchaseList -> next;
        while (pPurchaseList != NULL) {
            printf("ҩƷ���ƣ�%s\t", pPurchaseList -> name);
            printf("ҩƷ���룺%s\n", pPurchaseList -> code);
            printf("������%d\n", pPurchaseList -> quantity);
            pPurchaseList = pPurchaseList -> next;
        }
        if (pPurchaseList == NULL) {
            printf("�޽�������\n");
            (void)getchar(); //��ȡ�س�
            printf("�Ƿ������ѯ��(y/n)");
            char op1 = (char)getchar();
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
    } else if (op == 'b') {
        printf("��ѯ��������\n");
        SellList * pSellList = sellList -> next;
        while (pSellList != NULL) {
            printf("ҩƷ���ƣ�%s\t", pSellList -> name);
            printf("ҩƷ���룺%s\n", pSellList -> code);
            printf("������%d\n", pSellList -> quantity);
            pSellList = pSellList -> next;
        }
        if (purchaseList -> next == NULL) {
            printf("����������\n");
            (void)getchar(); //��ȡ�س�
            printf("�Ƿ������ѯ��(y/n)");
            char op1 = (char)getchar();
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
    } else if (op == 'c') {
        printf("��ѯ�������\n");
        Medicine * p = head -> next;
        while (p != NULL) {
            printf("ҩƷ���ƣ�%s\t", p -> name);
            printf("ҩƷ���룺%s\n", p -> code);
            printf("������%d\n", p -> quantity);
            p = p -> next;
        }
        if (head -> next == NULL) {
            printf("�޿������\n");
            (void)getchar(); //��ȡ�س�
            printf("�Ƿ������ѯ��(y/n)");
            char op1 = (char)getchar();
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
    } else {
        printf("�����������������\n");
        goto label;
    }
}