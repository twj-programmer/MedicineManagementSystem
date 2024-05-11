// 药品结构体定义
typedef struct Medicine {
    char name[50]; // 药品名称
    char code[20]; // 药品编码
    char production_date[20]; // 生产日期
    int shelf_life; // 保质期（月）
    char entry_date[20]; // 入库时间
    char exit_date[20]; // 出库时间
    char nature[50]; // 性质
    char attribute[50]; // 属性
    char symptoms[100]; // 适用症状
    long long int quantity; // 数量
    struct Medicine * next; // 指向下一个药品节点的指针
} Medicine;