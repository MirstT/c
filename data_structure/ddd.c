/*
 * @Description  :
 * @version      :
 * @Author       : Mirst
 * @Date         : 2022-04-27 14:51:00
 * @LastEditors  : Mirst
 * @LastEditTime : 2022-04-27 14:53:17
 */
/*
 * @Description  :16124278 ����
 * @version      :
 * @Author       : Mirst
 * @Date         : 2022-04-27 14:41:46
 * @LastEditors  : Mirst
 * @LastEditTime : 2022-04-27 14:50:42
 */
#include "stdlib.h"
#include "stdio.h"
#define N 39
#define M 39
int X;
int maze[N + 2][M + 2];
struct point
{
    int row, col, predecessor;
} queue[512];
int head = 0, tail = 0;
void shoudong_maze(int m, int n)
{
    int i, j;
    printf("\n\n");
    printf("�밴�������Թ���0��ʾͨ·��1��ʾ�ϰ�:\n\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &maze[i][j]);
}
void zidong_maze(int m, int n)
{
    int i, j;
    printf("\n�Թ������С���\n\n");
    system("pause");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            maze[i][j] = rand() % 2;
    //����rand()������������Ǵ�0��RAND_MAX
    // RAND_MAX�Ƕ�����stdlib.h�е�,��ֵ����Ϊ32767)
    //Ҫ������X��Y����,ֻ��Ҫ����д��k=rand()%(Y-X+1)+X;
}
void print_maze(int m, int n)
{
    int i, j;
    printf("\n�Թ����ɽ������:\n\n");
    printf("�Թ����\n");
    printf("��");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            if (maze[i][j] == 0)
                printf("��");
            if (maze[i][j] == 1)
                printf("��");
        }
    }
    printf("���Թ�����\n");
}
void result_maze(int m, int n)
{
    int i, j;
    printf("�Թ�ͨ·(�á��ʾ)������ʾ��\n\t");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            if (maze[i][j] == 0 || maze[i][j] == 2)
                printf("��");
            if (maze[i][j] == 1)
                printf("��");
            if (maze[i][j] == 3)
                printf("��");
        }
    }
}
void enqueue(struct point p)
{
    queue[tail] = p;
    tail++;
}
struct point dequeue()
{
    head++;
    return queue[head - 1];
}
int is_empty()
{
    return head == tail;
}
void visit(int row, int col, int maze[41][41])
{
    struct point visit_point = {row, col, head - 1};
    maze[row][col] = 2;
    enqueue(visit_point);
}
int mgpath(int maze[41][41], int m, int n)
{
    X = 1;
    struct point p = {0, 0, -1};
    if (maze[p.row][p.col] == 1)
    {
        printf("\n===============================================\n");
        printf("���Թ��޽�\n\n");
        X = 0;
        return 0;
    }
    maze[p.row][p.col] = 2;
    enqueue(p);
    while (!is_empty())
    {
        p = dequeue();
        if ((p.row == m - 1) && (p.col == n - 1))
            break;
        if ((p.col + 1 < n) && (maze[p.row][p.col + 1] == 0))
            visit(p.row, p.col + 1, maze);
        if ((p.row + 1 < m) && (maze[p.row + 1][p.col] == 0))
            visit(p.row + 1, p.col, maze);
        if ((p.col - 1 >= 0) && (maze[p.row][p.col - 1] == 0))
            visit(p.row, p.col - 1, maze);
        if ((p.row - 1 >= 0) && (maze[p.row - 1][p.col] == 0))
            visit(p.row - 1, p.col, maze);
    }
    if (p.row == m - 1 && p.col == n - 1)
    {
        printf("\n==================================================================\n");
        printf("�Թ�·��Ϊ��\n");
        printf("(%d,%d)\n", p.row, p.col);
        maze[p.row][p.col] = 3;
        while (p.predecessor != -1)
        {
            p = queue[p.predecessor];
            printf("(%d,%d)\n", p.row, p.col);
            maze[p.row][p.col] = 3;
        }
    }
    else
    {
        printf("\n=============================================================\n");
        printf("���Թ��޽⣡\n\n");
        X = 0;
    }
    return 0;
}
int main()
{
    int i, m, n, cycle = 0;
    while (cycle != (-1))
    {
        printf("********************************************************************************\n");
        printf("                              ��ӭ�����Թ����ϵͳ\n");
        printf("                                                    16124278 ����\n");
        printf("********************************************************************************\n");
        printf("                           ��  �ֶ������Թ�  �밴��1\n");
        printf("                           ��  �Զ������Թ�  �밴��2\n");
        printf("                           ��  �˳�          �밴��3\n\n");
        printf("********************************************************************************\n");
        printf("\n");
        printf("��ѡ����Ĳ�����\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\n������������");
            scanf("%d", &m);
            printf("\n");
            printf("������������");
            scanf("%d", &n);
            while ((m <= 0 || m > 39) || (n <= 0 || n > 39))
            {
                printf("\n��Ǹ�������������������Ԥ�跶Χ(0-39,0-39),���������룺\n\n");
                printf("������������");
                scanf("%d", &m);
                printf("\n");
                printf("������������");
                scanf("%d", &n);
            }
            shoudong_maze(m, n);
            print_maze(m, n);
            mgpath(maze, m, n);
            if (X != 0)
                result_maze(m, n);
            printf("\n\nPress Enter Contiue!\n");
            getchar();
            while (getchar() != '\n')
                ;
            break;
        case 2:
            printf("\n������������");
            scanf("%d", &m);
            printf("\n");
            printf("������������");
            scanf("%d", &n);
            while ((m <= 0 || m > 39) || (n <= 0 || n > 39))
            {
                printf("\n��Ǹ�������������������Ԥ�跶Χ(0-39,0-39),���������룺\n\n");
                printf("������������");
                scanf("%d", &m);
                printf("\n");
                printf("������������");
                scanf("%d", &n);
            }
            zidong_maze(m, n);
            print_maze(m, n);
            mgpath(maze, m, n);
            if (X != 0)
                result_maze(m, n);
            printf("\n\nPress Enter Contiue!\n");
            getchar();
            while (getchar() != '\n')
                ;
            break;
        case 3:
            cycle = (-1);
            break;
        default:
            printf("\n");
            printf("�����������!\n");
            printf("\nPress Enter Contiue!\n");
            getchar();
            while (getchar() != '\n')
                ;
            break;
        }
    }
}