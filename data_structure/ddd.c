/*
 * @Description  :
 * @version      :
 * @Author       : Mirst
 * @Date         : 2022-04-27 14:51:00
 * @LastEditors  : Mirst
 * @LastEditTime : 2022-04-27 14:53:17
 */
/*
 * @Description  :16124278 王浩
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
    printf("请按行输入迷宫，0表示通路，1表示障碍:\n\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &maze[i][j]);
}
void zidong_maze(int m, int n)
{
    int i, j;
    printf("\n迷宫生成中……\n\n");
    system("pause");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            maze[i][j] = rand() % 2;
    //由于rand()产生的随机数是从0到RAND_MAX
    // RAND_MAX是定义在stdlib.h中的,其值至少为32767)
    //要产生从X到Y的数,只需要这样写：k=rand()%(Y-X+1)+X;
}
void print_maze(int m, int n)
{
    int i, j;
    printf("\n迷宫生成结果如下:\n\n");
    printf("迷宫入口\n");
    printf("↓");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            if (maze[i][j] == 0)
                printf("□");
            if (maze[i][j] == 1)
                printf("■");
        }
    }
    printf("→迷宫出口\n");
}
void result_maze(int m, int n)
{
    int i, j;
    printf("迷宫通路(用☆表示)如下所示：\n\t");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            if (maze[i][j] == 0 || maze[i][j] == 2)
                printf("□");
            if (maze[i][j] == 1)
                printf("■");
            if (maze[i][j] == 3)
                printf("☆");
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
        printf("此迷宫无解\n\n");
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
        printf("迷宫路径为：\n");
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
        printf("此迷宫无解！\n\n");
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
        printf("                              欢迎进入迷宫求解系统\n");
        printf("                                                    16124278 王浩\n");
        printf("********************************************************************************\n");
        printf("                           ☆  手动生成迷宫  请按：1\n");
        printf("                           ☆  自动生成迷宫  请按：2\n");
        printf("                           ☆  退出          请按：3\n\n");
        printf("********************************************************************************\n");
        printf("\n");
        printf("请选择你的操作：\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\n请输入行数：");
            scanf("%d", &m);
            printf("\n");
            printf("请输入列数：");
            scanf("%d", &n);
            while ((m <= 0 || m > 39) || (n <= 0 || n > 39))
            {
                printf("\n抱歉，你输入的行列数超出预设范围(0-39,0-39),请重新输入：\n\n");
                printf("请输入行数：");
                scanf("%d", &m);
                printf("\n");
                printf("请输入列数：");
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
            printf("\n请输入行数：");
            scanf("%d", &m);
            printf("\n");
            printf("请输入列数：");
            scanf("%d", &n);
            while ((m <= 0 || m > 39) || (n <= 0 || n > 39))
            {
                printf("\n抱歉，你输入的行列数超出预设范围(0-39,0-39),请重新输入：\n\n");
                printf("请输入行数：");
                scanf("%d", &m);
                printf("\n");
                printf("请输入列数：");
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
            printf("你的输入有误!\n");
            printf("\nPress Enter Contiue!\n");
            getchar();
            while (getchar() != '\n')
                ;
            break;
        }
    }
}