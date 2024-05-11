#include <stdio.h>
#include <stdlib.h>
#include "Welcome.h"

int main() {
    while (true) {
        Welcome();
        char op = GetUserOP();
        switch (op) {
            case '1':

                break;
            case '2':

                break;
            case '3':
                printf("修改药品条目\n");
                break;
            case '4':
                printf("删除药品条目\n");
                break;
            case '5':
                printf("显示过期药品\n");
                break;
            case '6':
                printf("生成销售统计\n");
                break;
            case '7':
                printf("保存药品信息\n");
                break;
            case '8':
                printf("清理屏幕\n");
                break;
            case '0':
                printf("保存退出系统\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
        if (op == '0') {
            break;
        }
    }
    return 0;
}