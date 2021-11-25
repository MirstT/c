/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-24 08:09:08
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-24 15:33:52
 */
#include <stdio.h>

//静态分配
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;




// void InitList(SqList &List)
// {
//     for (int i = 0; i < MAXSIZE; i++)
//     {
//         List.data[i] = 0;
//     }
//     List.length = 0;
// }

// bool ListInsert(SqList &List, int index, int element)
// {
//     if (index < 0 || index > List.length || List.length >= MAXSIZE)
//     {
//         return false;
//     }

//     for (size_t i = List.length; i > index; i--)
//     {
//         List.data[i] = List.data[i - 1];
//     }
//     List.data[index] = element;
//     List.length++;
//     return true;
// }
// bool ListDelete(SqList &List, int index, int deletedElement)
// {
//     if (index < 0 || index >= List.length)
//     {
//         return false;
//     }
//     deletedElement = List.data[index];
//     for (size_t i = index; i < List.length - 1; i++)
//     {
//         List.data[i] = List.data[i + 1];
//     }
//     List.length--;
//     return true;
// }

// int GetElem(SqList List,int index)
// {
//     return List.data[index];
// }

// int LocateElem(SqList List,int element)
// {
//     for (size_t i = 0; i < List.length; i++)
//     {
//         if (List.data[i]==element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int main()
{
    // SqList L;
    // InitList(L);
    // int e = -1;
    // ListInsert(L, 3, 3);
    // ListDelete(L, 3, e);
    return 0;
}
