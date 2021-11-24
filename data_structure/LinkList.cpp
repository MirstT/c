/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-24 15:49:31
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-24 16:17:49
 */

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = nullptr;
}