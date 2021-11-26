/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-25 16:48:48
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-26 10:38:46
 */

#include <stdio.h>
#include <string.h>
#include <iostream>

// int main1(void)
// {
//     int a = NULL;
//     printf("%p\n", a);
//     printf("%d\n", a);
//     return 0;
// }

// int main2(void)
// {
//     char a = '\0';
//     char b = '0';
//     char c = '\60';
//     char d[] = "\0";
//     printf("sizeof str is %d,string len is %d\n", sizeof(d), strlen(d));
//     printf("a=%d,b=%d,c=%d\n", a, b, c);
//     return 0;
// }

// int main3(void)
// {
//     char p[] = "12345";
//     int *a =(void*)p;
//     return 0;
// }

int main(void)
{
    int a =3;
    int *b;
    b=&a;
    *b=3;
    
    int arr[]={11,22,3};
    int *p=arr;
    int (*pp)[3]=&arr;
    printf("%d\n",(*pp)[1]);
    return 0;
}