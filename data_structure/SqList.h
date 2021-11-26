/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-26 15:10:38
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 15:15:57
 */
#include <cstdio>
#include <cstring>

#define MAXSIZE 10
struct SqList
{
    int data[MAXSIZE];
    int length;
};
enum SqListDesc
{
    NullElement = 0,
    NullIndex = -1
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