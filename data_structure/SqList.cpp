/*
 * @Description  : 顺序表的静态实现
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-25 14:17:30
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 08:36:05
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>

#define MAXSIZE 10
typedef struct SqList
{
    int data[MAXSIZE];
    int length;
} SqList;
enum SqListDesc
{
    NullElement = -1,
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

void InitList(SqList &List)
{
    memset(&List, 0, sizeof(List));
    List.length = 0;
}

void Destroy(SqList &List)
{
    memset(&List, 0, sizeof(List));
}

bool ListInsert(SqList &List, int index, int element)
{
    return true;
}

bool ListDelete(SqList &List, int index, int &deletedElement)
{
    return true;
}

int LocateElem(SqList List, int element)
{
    if (IsEmpty(List))
    {
        return NullElement;
    }

    for (size_t i = 0; i < GetLength(List); i++)
    {
        if (element = GetElem(List, i))
        {
            return i;
        }
    }
    return NullElement;
}

int GetElem(SqList List, int index)
{
    if (IsEmpty(List) || index > GetLength(List) - 1 || index < 0)
    {
        return NullIndex;
    }

    return List.data[index];
}

int GetLength(SqList List)
{
    return List.length;
}

void PrintList(SqList List)
{
    if (IsEmpty(List))
    {
        printf("Empty!");
        return;
    }

    for (size_t i = 0; i < GetLength(List); i++)
    {
        printf("List[%d]:%d\n", i, GetElem(List, i));
    }
}

bool IsEmpty(SqList List)
{
    return List.length == 0 || List.length == -1;
}

int main()
{
    SqList sqList;
    InitList(sqList);
    printf("IsEmpty:%d\n", IsEmpty(sqList));
    PrintList(sqList);
    Destroy(sqList);

    return 0;
}
