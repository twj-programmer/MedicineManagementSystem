#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Medicine.h"
// �û�ѡ��1: �������
void PurchaseMedicine(Medicine * head, PurchaseList * purchaseList) {
    printf("\t�������\n");
    label:
    /**
     * ����Ĭ��ÿ�ν���ʱ��ͬҩƷ���������ڲ�ͬ
     * ���ÿ�ν���ʱ����Ϊ�䴴��һ���µ�ҩƷ�ڵ�
     */
    Medicine * newMedicine = (Medicine*)malloc(sizeof(Medicine));
    printf("������ҩƷ���ƣ�");scanf("%s", newMedicine -> name);(void)getchar(); //��ȡ�س�
    printf("������ҩƷ���룺");scanf("%s", newMedicine -> code);(void)getchar(); //��ȡ�س�
    printf("�������������ڣ�");scanf("%s", newMedicine -> production_date);(void)getchar(); //��ȡ�س�
    printf("�����뱣���ڣ��£���");scanf("%s", newMedicine -> shelf_life);(void)getchar(); //��ȡ�س�
    printf("���������ʱ�䣺");scanf("%s", newMedicine -> entry_date);(void)getchar(); //��ȡ�س�
    printf("���������ʣ�");scanf("%s", newMedicine -> nature);(void)getchar(); //��ȡ�س�
    printf("���������ԣ�");scanf("%s", newMedicine -> attribute);(void)getchar(); //��ȡ�س�
    printf("����������֢״��");scanf("%s", newMedicine -> symptoms);(void)getchar(); //��ȡ�س�
    printf("������������");scanf_s("%d", &newMedicine -> quantity);(void)getchar(); //��ȡ�س�
    newMedicine -> next = head -> next;
    head -> next = newMedicine;
    /**
     * �����ͳ��ĳ��ҩƷ�����ܵ�����
     * ����ҩƷ�������Խ�������
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
    printf("���ɹ�\n");
    sleep(1);
    printf("�Ƿ����������⣿(y/n)");
    char op = (char)getchar();
    (void)getchar(); //��ȡ�س�
    if (op == 'y' || op == 'Y') {
        goto label;
    }
}
// ���۳���
void SellMedicine(Medicine * head, SellList * sellList) {
    printf("\t���۳���\n");
    label:
    char name[50];
    printf("������ҩƷ���ƣ�");scanf("%s", name);(void)getchar(); //��ȡ�س�
    char code[20];
    printf("������ҩƷ���룺");scanf("%s", code);(void)getchar(); //��ȡ�س�
    int quantity;
    printf("������������");scanf_s("%d", &quantity);(void)getchar(); //��ȡ�س�
    Medicine * p = head->next;
    while (p != NULL) {
        if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
            if (p->quantity < quantity) {
                printf("��治��\n");
                sleep(3);
                return;
            }
            p -> quantity -= quantity;
            break;
        }
        p = p -> next;
    }
    if (p == NULL) {
        printf("δ�ҵ���ҩƷ\n");
        system("pause");
        return;
    }
    /**
     * �����ͳ��ĳ��ҩƷ�����ܵ�����
     * ����ҩƷ�������Խ�������
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
    printf("����ɹ�\n");
    sleep(1);
    printf("�Ƿ�������۳��⣿(y/n)");
    char op = (char)getchar();
    (void)getchar(); //��ȡ�س�
    if (op == 'y' || op == 'Y') {
        goto label;
    }
}
// ������
void inventoryManagement(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    printf("\t������\n");
    label:
    printf("�������\n");
    printf("a���޸�ҩƷ��Ϣ\n");
    printf("b����ѯҩƷ��Ϣ\n");

    char op = (char)getchar();
    (void)getchar(); //��ȡ�س�
    if (op == 'a') {
        printf("\t�޸�ҩƷ��Ϣ\n");
        /**
         * ����ԭҩƷ�����ƺͱ���
         * ͨ�����ƺͱ����ҵ�ԭҩƷ���޸�����Ϣ
         */
        char name[50];
        printf("������ҩƷ���ƣ�");scanf("%s", name);(void)getchar(); //��ȡ�س�
        char code[20];
        printf("������ҩƷ���룺");scanf("%s", code);(void)getchar(); //��ȡ�س�
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("�������µ�ҩƷ���ƣ�");scanf("%s", p -> name);(void)getchar(); //��ȡ�س�
                printf("�������µ�ҩƷ���룺");scanf("%s", p -> code);(void)getchar(); //��ȡ�س�
                printf("�������µ��������ڣ�");scanf("%s", p -> production_date);(void)getchar(); //��ȡ�س�
                printf("�������µı����ڣ��£���");scanf("%s", p -> shelf_life);(void)getchar(); //��ȡ�س�
                printf("�������µ����ʱ�䣺");scanf("%s", p -> entry_date);(void)getchar(); //��ȡ�س�
                printf("�������µ����ʣ�");scanf("%s", p -> nature);(void)getchar(); //��ȡ�س�
                printf("�������µ����ԣ�");scanf("%s", p -> attribute);(void)getchar(); //��ȡ�س�
                printf("�������µ�����֢״��");scanf("%s", p -> symptoms);(void)getchar(); //��ȡ�س�
                printf("�������µ�������");scanf_s("%d", &p -> quantity);(void)getchar(); //��ȡ�س�
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
            printf("δ�ҵ���ҩƷ\n");
            system("pause");
        }
        printf("�޸ĳɹ�\n");
        system("pause");
    } else if (op == 'b') {
        printf("\t��ѯҩƷ��Ϣ\n");
        char name[50];
        printf("������ҩƷ���ƣ�");scanf("%s", name);(void)getchar(); //��ȡ�س�
        char code[20];
        printf("������ҩƷ���룺");scanf("%s", code);(void)getchar(); //��ȡ�س�
        /**
         * �����ҵ�ҩƷ��û��ֱ��break
         * ���Ǽ��������Ƿ�����ͬ��ҩƷ���������ڲ�ͬ��
         */
        int flg = 0;
        Medicine * p = head->next;
        while (p != NULL) {
            if (strcmp(p -> name, name) == 0 && strcmp(p -> code, code) == 0) {
                printf("ҩƷ���ƣ�%s\t", p -> name);
                printf("ҩƷ���룺%s\n", p -> code);
                printf("�������ڣ�%s\t", p -> production_date);
                printf("�����ڣ��£���%s\n", p -> shelf_life);
                printf("���ʱ�䣺%s\n", p -> entry_date);
                printf("���ʣ�%s\t", p -> nature);
                printf("���ԣ�%s\n", p -> attribute);
                printf("����֢״��%s\n", p -> symptoms);
                printf("������%d\n\n", p -> quantity);
                flg = 1;
            }
            p = p -> next;
        }
        if (flg == 0) {
            printf("δ�ҵ���ҩƷ\n");
        }
        system("pause");
    } else {
        printf("�����������������\n");
        goto label;
    }
}
// ���ͳ������
void Statistics(Medicine * head, PurchaseList * purchaseList, SellList * sellList) {
    printf("\t���ͳ������\n");
    label:
    printf("ѡ���ѯ������\n");
    printf("a����ѯ��������\n");
    printf("b����ѯ��������\n");
    printf("c����ѯ�������\n");
    char op = (char)getchar();
    (void)getchar(); //��ȡ�س�
    if (op == 'a') {
        printf("\t��ѯ��������\n");
        PurchaseList * pPurchaseList = purchaseList -> next;
        if (pPurchaseList == NULL) {
            printf("�޽�������\n");
            sleep(1);
            printf("�Ƿ������ѯ��(y/n)");
            char op1 = (char)getchar();
            (void)getchar(); //��ȡ�س�
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
        while (pPurchaseList != NULL) {
            printf("ҩƷ���ƣ�%s\t", pPurchaseList -> name);
            printf("ҩƷ���룺%s\n", pPurchaseList -> code);
            printf("����������%d\n", pPurchaseList -> quantity);
            pPurchaseList = pPurchaseList -> next;
        }
        system("pause");
    } else if (op == 'b') {
        printf("\t��ѯ��������\n");
        SellList * pSellList = sellList -> next;
        if (pSellList == NULL) {
            printf("����������\n");
            sleep(1);
            printf("�Ƿ������ѯ��(y/n)");
            char op1 = (char)getchar();
            (void)getchar(); //��ȡ�س�
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
        while (pSellList != NULL) {
            printf("ҩƷ���ƣ�%s\t", pSellList -> name);
            printf("ҩƷ���룺%s\n", pSellList -> code);
            printf("�۳�������%d\n", pSellList -> quantity);
            pSellList = pSellList -> next;
        }
        system("pause");
    } else if (op == 'c') {
        printf("\t��ѯ�������\n");
        Medicine * p = head -> next;
        if (p == NULL) {
            printf("�޿������\n");
            sleep(1);
            printf("�Ƿ������ѯ��(y/n)");
            char op1 = (char)getchar();
            (void)getchar(); //��ȡ�س�
            if (op1 == 'y' || op1 == 'Y') {
                goto label;
            }
        }
        while (p != NULL) {
            printf("ҩƷ���ƣ�%s\t", p -> name);
            printf("ҩƷ���룺%s\n", p -> code);
            printf("���������%d\n", p -> quantity);
            p = p -> next;
        }
        system("pause");
    } else {
        printf("�����������������\n");
        sleep(1);
        goto label;
    }
}
// ����ҩƷ��Ϣ
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

    printf("����ɹ�\n");
    sleep(1);
}