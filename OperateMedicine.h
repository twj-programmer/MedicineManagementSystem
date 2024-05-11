//药品进货入库
void PurchaseMedicine(Medicine * head, PurchaseList * purchaseList);
//药品销售出库
void SellMedicine(Medicine * head, SellList * sellList);
//药品库存管理
void inventoryManagement(Medicine * head);
//输出统计数据
void statistics(Medicine * head, PurchaseList * purchaseList, SellList * sellList);