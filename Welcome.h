#include "Medicine.h"
//加载已有药品信息
void Load(Medicine * head, PurchaseList * purchaseList, SellList * sellList);
// 欢迎界面
void Welcome();
//获取用户操作
char GetUserOP();
//清空输入缓冲区
void clear_input_buffer();
//去除字符串中的换行符
void remove_newline(char * str);