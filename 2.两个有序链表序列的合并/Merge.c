#include"head.h"

List Merge(List L1, List L2) {
	List L = (List)malloc(sizeof(struct Node));
	List head = L;  //��¼ L ��ͷ���
	List tmpL1 = L1->Next;   //tmpL1->Data �ſ�ʼ��ֵ
	List tmpL2 = L2->Next;
	while (tmpL1 && tmpL2) {   //�� L1 �� L2 ���Ϊ��
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
	if (tmpL1)  //�����ʱ L1 ʣ����Ϊ�գ���ʣ�������ӵ� L ����
		L->Next = tmpL1;
	if (tmpL2)
		L->Next = tmpL2;
	L1->Next = NULL;  //�ϲ��� L1 L2 Ϊ NULL
	L2->Next = NULL;
	return head;
}

