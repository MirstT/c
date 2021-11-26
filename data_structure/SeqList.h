/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-26 15:17:24
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 15:21:21
 */
#include <iostream>
#include "LinerList.h"

#define INITSIZE 10
struct SeqList
{
    int *data;
    int maxSize;
    int length;
};

void InitList(SeqList &List);
void IncreaseSize(SeqList &List, int increasedSize);
void DestroyList(SeqList &List);
bool ListInsert(SeqList &List, int index, int element);
bool ListDelete(SeqList &List, int index, int &deletedElement);
int LocateElem(SeqList List, int element);
int GetElem(SeqList List, int index);

int GetLength(SeqList List);
void PrintList(SeqList List);
bool IsEmpty(SeqList List);