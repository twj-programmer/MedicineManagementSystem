#include <stdio.h>
#include "Welcome.h"

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