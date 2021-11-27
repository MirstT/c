/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-24 15:49:31
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 15:26:50
 */
#include "LinkList.h"

// bool InitList(LinkList &List)
// {
// 	List = nullptr;
// 	return true;
// }

bool InitList(LinkList &List)
{
	List = (LNode *)malloc(sizeof(LNode));
	if (List == nullptr)
	{
		return false;
	}
	List->next = nullptr;
	return true;
}

// bool IsEmpty(LinkList List)
// {
// 	return List == nullptr;
// }

bool IsEmpty(LinkList List)
{
	return List->next == nullptr;
}

int main()
{
	LinkList L;
	InitList(L);
	return 0;
}