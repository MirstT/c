/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-26 15:17:24
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 18:16:51
 */
#ifndef DATA_STRUCTURE_SEQLISH_H_
#define DATA_STRUCTURE_SEQLISH_H_

#include <iostream>

#include "LinerList.h"

#define INITSIZE 10
struct SeqList
{
    int *data;
    int max_size;
    int length;
};

void InitList(SeqList &List);
void IncreaseSize(SeqList &List, int increasedSize);
void DestroyList(SeqList &List);
bool ListInsert(SeqList &List, int index, int element);
bool ListDelete(SeqList &List, int index, int &deletedElement);
int LocateElem(SeqList List, int element);
int GetElem(SeqList List, int index);

int GetLength(const SeqList List);
void PrintList(const SeqList List);

#endif