#include"head.h"
void Print(List L) {
    List p;
    int tag = 1;
    p = L->Next;
    while (p) {
        if (tag) { /* ��һ��Ԫ��ǰ�治���ո�*/
            printf("%d", p->Data);
            tag = 0;
            p = p->Next;
        }
        else {
            printf(" %d", p->Data);
            p = p->Next;
        }
    }
    if (tag) {
        printf("NULL");
    }
    printf("\n");
}
