/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-27 12:04:43
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-27 13:30:27
 */
#include <cstdio>

//函数定义为inline即:内联函数
inline const char *dbtest(const int i)
{
    return (i % 2 > 0) ? "奇" : "偶";
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        printf("i:%d\t奇偶性:%s\t\n", i, dbtest(i));
    }
}