#include"head.h"
void Print(List L) {
    List p;
    int tag = 1;
    p = L->Next;
    while (p) {
        if (tag) { /* 第一个元素前面不带空格*/
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
