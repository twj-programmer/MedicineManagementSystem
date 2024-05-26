#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"
#include "OperateMedicine.h"

int main() {
    //��ͷ��������

    //ҩƷ��Ϣ����
    Medicine * head = (Medicine*)malloc(sizeof(Medicine));
    head->next = NULL;
    //������Ϣ����
    PurchaseList * purchaseList = (PurchaseList*)malloc(sizeof(PurchaseList));
    purchaseList->next = NULL;
    //������Ϣ����
    SellList * sellList = (SellList*)malloc(sizeof(SellList));
    sellList->next = NULL;

    Load(head, purchaseList, sellList);//��ʼ�����룬���ļ���������

    while (1) {
        Welcome();//��ӭ����
        char op = GetUserOP();//��ȡ�û�����
        switch (op) {
            case '1':
                PurchaseMedicine(head, purchaseList);//ҩƷ�������
                break;
            case '2':
                SellMedicine(head, sellList);//ҩƷ���۳���
                break;
            case '3':
                inventoryManagement(head, purchaseList, sellList);//ҩƷ������
                break;
            case '4':
                Statistics(head, purchaseList, sellList);//���ͳ������
                break;
            case '0':
                Save(head, purchaseList, sellList);//����ҩƷ��Ϣ
                break;
            default:
                printf("�����������������\n");
                system("pause");
                break;
        }
        if (op == '0') {
            break;
        }
        system("cls");//ÿ�β���������
    }
    return 0;
}