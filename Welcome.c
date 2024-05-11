#include <stdio.h>
#include "Welcome.h"

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