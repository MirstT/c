/*
 * @Description  : 顺序表的动态实现
 * @version      : 1.0.0
 * @Author       : Mirst
 * @Date         : 2021-11-25 14:17:57
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-27 13:36:22
 */
#include "SeqList.h"

int main()
{
    SeqList List;
    InitList(List);
    PrintList(List);
    for (size_t i = 0; i < 25; ++i)
    {
        ListInsert(List, i, i + 100);
    }
    PrintList(List);

    for (size_t i = 10; i < 25; ++i)
    {
        int temp = -1;
        ListDelete(List, 0, temp);
        std::cout << "Deleted:" << temp << std::endl;
    }
    PrintList(List);
    DestroyList(List);
    return 0;
}

void InitList(SeqList &List)
{
    List.data = new int[kInitSize];
    // List.data = (int *)malloc(kInitSize*sizeof(int));
    List.max_size = kInitSize;
    List.length = 0;
}

void IncreaseSize(SeqList &List, int increasedSize)
{
    int *oldData = List.data;
    List.max_size += increasedSize;
    List.data = new int[List.max_size];
    for (size_t i = 0; i < List.length; ++i)
    {
        List.data[i] = oldData[i];
    }
    delete[] oldData;
}

void DestroyList(SeqList &List)
{
    delete[] List.data;
    List.max_size = 0;
    List.length = 0;
}

bool ListInsert(SeqList &List, int index, int element)
{
    if (index > List.length || index < 0)
    {
        return false;
    }

    if (List.length == List.max_size)
    {
        IncreaseSize(List, kInitSize);
    }

    for (size_t i = List.length; i > index; --i)
    {
        List.data[i] = List.data[i - 1];
    }
    List.data[index] = element;
    List.length++;
    return true;
}

bool ListDelete(SeqList &List, int index, int &deletedElement)
{
    if (index >= List.length || index < 0)
    {
        return false;
    }
    deletedElement = List.data[index];
    for (size_t i = index; i < List.length - 1; ++i)
    {
        List.data[i] = List.data[i + 1];
    }
    List.length--;
    return true;
}

int LocateElem(SeqList List, int element)
{
    for (size_t i = 0; i < List.length; ++i)
    {
        if (List.data[i] == element)
        {
            return i;
        }
    }
    return kNullIndex;
}

int GetElem(SeqList List, int index)
{
    if (index >= List.length || index < 0)
    {
        return kNullElement;
    }
    return List.data[index];
}

int GetLength(SeqList List)
{
    return List.length;
}

void PrintList(SeqList List)
{
    if (IsEmpty(List))
    {
        std::cout << "Empty!" << std::endl;
    }

    for (size_t i = 0; i < List.length; ++i)
    {
        std::cout << List.data[i] << std::endl;
    }
}

bool IsEmpty(SeqList List)
{
    return List.length == 0;
}