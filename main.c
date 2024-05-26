#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"
#include "OperateMedicine.h"

int main() {
    //带头结点的链表

    //药品信息链表
    Medicine * head = (Medicine*)malloc(sizeof(Medicine));
    head->next = NULL;
    //进货信息链表
    PurchaseList * purchaseList = (PurchaseList*)malloc(sizeof(PurchaseList));
    purchaseList->next = NULL;
    //销售信息链表
    SellList * sellList = (SellList*)malloc(sizeof(SellList));
    sellList->next = NULL;

    Load(head, purchaseList, sellList);//初始化载入，从文件读入数据

    while (1) {
        Welcome();//欢迎界面
        char op = GetUserOP();//获取用户操作
        switch (op) {
            case '1':
                PurchaseMedicine(head, purchaseList);//药品进货入库
                break;
            case '2':
                SellMedicine(head, sellList);//药品销售出库
                break;
            case '3':
                inventoryManagement(head, purchaseList, sellList);//药品库存管理
                break;
            case '4':
                Statistics(head, purchaseList, sellList);//输出统计数据
                break;
            case '0':
                Save(head, purchaseList, sellList);//保存药品信息
                break;
            default:
                printf("输入错误，请重新输入\n");
                system("pause");
                break;
        }
        if (op == '0') {
            break;
        }
        system("cls");//每次操作后清屏
    }
    return 0;
}