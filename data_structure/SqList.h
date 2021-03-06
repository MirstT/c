/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-26 15:10:38
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-27 13:35:16
 */
#ifndef DATA_STRUCTURE_SQLIST_H_
#define DATA_STRUCTURE_SQLIST_H_

#include <cstdio>
#include <cstring>
#include "LinerList.h"

constexpr int kMaxSize = 10;
struct SqList
{
    int data[kMaxSize];
    int length;
};

void InitList(SqList &List);
void Destroy(SqList &List);
bool ListInsert(SqList &List, int index, int element);
bool ListDelete(SqList &List, int index, int &deletedElement);
int LocateElem(SqList List, int element);
int GetElem(SqList List, int index);

int GetLength(SqList List);
void PrintList(SqList List);
bool IsEmpty(SqList List);

#endif