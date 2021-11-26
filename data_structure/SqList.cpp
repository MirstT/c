/*
 * @Description  : 顺序表的静态实现
 * @version      : 1.1.2
 * @Author       : Mirst
 * @Date         : 2021-11-25 14:17:30
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 15:13:37
 */
#include "SqList.h"

int main()
{
    SqList sqList;
    InitList(sqList);
    printf("IsEmpty:%d\n", IsEmpty(sqList));
    PrintList(sqList);
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        ListInsert(sqList, i, i + 100);
    }
    PrintList(sqList);
    int deletedNum;
    ListDelete(sqList, 3, deletedNum);
    printf("deletedNum:%d\n", deletedNum);
    PrintList(sqList);
    Destroy(sqList);

    return 0;
}

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
    if (index > List.length || index < 0 || index >= MAXSIZE)
    {
        return false;
    }

    for (size_t i = List.length; i > index; i--)
    {
        List.data[i] = List.data[i - 1];
    }
    List.data[index] = element;
    List.length++;
    return true;
}

bool ListDelete(SqList &List, int index, int &deletedElement)
{
    if (index > List.length - 1 || index < 0)
    {
        return false;
    }
    deletedElement = List.data[index];
    for (size_t i = index; i < List.length - 1; i++)
    {
        List.data[i] = List.data[i + 1];
    }
    List.length--;
    return true;
}

int LocateElem(SqList List, int element)
{
    for (size_t i = 0; i < GetLength(List); i++)
    {
        if (element == GetElem(List, i))
        {
            return i;
        }
    }
    return NullIndex;
}

int GetElem(SqList List, int index)
{
    if (index >= GetLength(List) || index < 0)
    {
        return NullElement;
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
        printf("Empty!\n");
        return;
    }

    for (size_t i = 0; i < GetLength(List); i++)
    {
        printf("List[%d]:%d\n", i, GetElem(List, i));
    }
}

bool IsEmpty(SqList List)
{
    return List.length == 0;
}
