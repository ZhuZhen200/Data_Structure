#pragma once
//Circle_queue ͷ�ļ���
#ifndef HEAD_H //����ͷ�ļ�����ȫ��д��Ӹ�_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>

typedef int Elementype;
typedef struct Node* PtrToNode;
struct Node
{
    int Data;
    struct Node* Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
List Merge(List L1, List L2);
#endif
