#pragma once
//Circle_queue 头文件名
#ifndef HEAD_H //就是头文件名（全大写后加个_H
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
