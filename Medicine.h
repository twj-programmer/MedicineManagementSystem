// 药品结构体定义
typedef struct Medicine {
    char name[50]; // 药品名称
    char code[50]; // 药品编码
    char production_date[50]; // 生产日期
    char shelf_life[50]; // 保质期（月）
    char entry_date[50]; // 入库时间
    char nature[100]; // 性质
    char attribute[100]; // 属性
    char symptoms[500]; // 适用症状
    int quantity; // 数量
    struct Medicine * next; // 指向下一个药品节点的指针
} Medicine;
// 药品进货信息结构体定义
typedef struct PurchaseList {
    char name[50]; // 药品名称
    char code[50]; // 药品编码
    int quantity; // 进货数量
    struct PurchaseList * next; // 指向下一个药品节点的指针
} PurchaseList;
// 药品销售信息结构体定义
typedef struct SellList {
    char name[50]; // 药品名称
    char code[50]; // 药品编码
    int quantity; // 销售数量
    struct SellList * next; // 指向下一个药品节点的指针
} SellList;