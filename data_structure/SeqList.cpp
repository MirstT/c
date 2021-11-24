/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-24 08:09:08
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-24 14:29:22
 */
#include <stdlib.h>

//动态分配
#define INITSIZE 10
typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList &L)
{
    L.data = (int *)malloc(INITSIZE * sizeof(int));
    L.length = 0;
    L.MaxSize = INITSIZE;
}

void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.MaxSize = L.MaxSize + len;
    L.data = (int *)malloc(L.MaxSize * sizeof(int));
    for (size_t i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    free(p);
}

int main()
{
    SeqList L;
    InitList(L);
    return 0;
}
