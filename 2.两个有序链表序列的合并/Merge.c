#include"head.h"

List Merge(List L1, List L2) {
	List L = (List)malloc(sizeof(struct Node));
	List head = L;  //记录 L 的头结点
	List tmpL1 = L1->Next;   //tmpL1->Data 才开始存值
	List tmpL2 = L2->Next;
	while (tmpL1 && tmpL2) {   //当 L1 或 L2 结点为空
		if (tmpL1->Data < tmpL2->Data) {
			L->Next = tmpL1;
			tmpL1 = tmpL1->Next;
		}
		else {
			L->Next = tmpL2;
			tmpL2 = tmpL2->Next;
		}
		L = L->Next;
	}
	if (tmpL1)  //如果此时 L1 剩余结点为空，将剩余结点链接到 L 后面
		L->Next = tmpL1;
	if (tmpL2)
		L->Next = tmpL2;
	L1->Next = NULL;  //合并后 L1 L2 为 NULL
	L2->Next = NULL;
	return head;
}

