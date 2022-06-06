/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2022-04-11 13:29:35
 * @LastEditors  : Mirst
 * @LastEditTime : 2022-04-11 13:29:38
 */
//头文件引用
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

//文件路径
const string pmsFilePath = "pms.txt";

//常量 屏幕输入位置
const int idx = 31;
const int idy = 2;
const int namex = 31;
const int namey = 4;
const int genderx = 31;
const int gendery = 6;
const int bidayx = 35;
const int bidayy = 8;
const int postx = 31;
const int posty = 10;
const int departx = 31;
const int departy = 12;
const int workhx = 31;
const int workhy = 14;

//员工：编号 姓名 性别 出生日期 职位 部门 工时
struct emp
{
    int id;
    char name[20];
    bool gender;
    tm biday;
    char post[20];
    char depart[20];
    int workh;
    emp *next;
};
emp *head, *e, *etemp; //头指针
//**函数声明***********************************************************************************
emp *new_node();
void addInfo();
void adminInfo();
void displayInfo();
void exitPms(int &choice);
void modify();
void modi_all();
void del();
void sort();
void find();
void find_name();
void find_num();
void find_namenum();
void save();
void read();
void displayOneEmp(emp* e);
void gotoxy(int x, int y);

void testInfo();

//构造员工结点函数   没有头结点
emp *new_node()
{
    e = new emp;
    e->next = nullptr;
    return e;
}

//**采集信息************************************************************************************
void addInfo()
{
    system("cls");
    int j, k;
    bool repeatTag = false;
    bool chTag = false;

    e = new_node(); //新建一个节点
    cout
        << "\t\t\t┏━━━━━━━━━━━━━━采集员工信息━━━━━━━━━━━━━━━┓\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃编号:                                    ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃姓名:                                    ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃性别:                                    ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃出生日期:                                ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃职位:                                    ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃部门:                                    ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┃工时:                                    ┃\n"
        << "\t\t\t┃                                         ┃\n"
        << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    //**id*******************************************************************
    while (1)
    {
        gotoxy(idx, idy);
        cin >> e->id; //输入 录入
        //检查输入是否合规
        if (cin.fail() || e->id < 10000 || e->id > 99999)
        {
            cin.clear(); //先用 std::cin.clear() 清除 fail 状态
            cin.sync();  //清除缓存区
            gotoxy(idx, idy);
            cout << "工号是5位数字,请重新输入";
            Sleep(400);
            gotoxy(idx, idy);
            for (k = 0; k < 34; k++)
                cout << " ";
            continue;
        }
        //查重
        for (etemp = head->next; etemp != NULL; etemp = etemp->next)
        {
            if (etemp->id == e->id)
            {
                cin.sync();  //清除缓存区
                repeatTag = false;
                gotoxy(idx, idy);
                cout << "该编号已经存,请重新给予一个编号";
                Sleep(400);
                gotoxy(idx, idy);
                for (k = 0; k < 34; k++)
                    cout << " ";
                break;
            }
        }
        if (etemp == NULL) //新节点
        {
            repeatTag = true;
        }

        if (e->id >= 10000 && e->id <= 99999 && repeatTag)
        {
            break;
        }
    }

    //**name*******************************************************************
    while (1)
    {
        gotoxy(namex, namey);
        cin >> e->name; //输入 录入
        if (strlen(e->name) > 15)
        {
            gotoxy(namex, namey);
            cout << "姓名过长,请重新输入";
            Sleep(400);
            gotoxy(namex, namey);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //清除缓存区
            continue;
        }

        for (j = 0; j < strlen(e->name); j++)
        {
            if (e->name[j] >= 0 && e->name[j] <= 255)
            {
                chTag = false;
                gotoxy(namex, namey);
                cout << "不是中文,请重新输入";
                Sleep(400);
                gotoxy(namex, namey);
                for (k = 0; k < 34; k++)
                    cout << " ";
                cin.sync(); //清除缓存区
                break;
            }
            chTag = true;
        }
        if (chTag)
        {
            break;
        }
    }

    //**gender*******************************************************************
    while (1)
    {
        gotoxy(genderx, gendery);
        string str;
        cin >> str;      //输入
        if (str == "男") //录入
        {
            e->gender = 0;
            break;
        }
        else if (str == "女")
        {
            e->gender = 1;
            break;
        }
        else
        {
            gotoxy(genderx, gendery);
            cout << "输入非法，请输入 男/女";
            Sleep(400);
            gotoxy(genderx, gendery);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //清除缓存区
            continue;
        }
    }

    //biday*******************************************************************
    while (1)
    {
        gotoxy(bidayx, bidayy);
        int y, m, d, md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //md是每月天数数组
        scanf("%d%d%d", &y, &m, &d);
        md[1] = y % 4 == 0 && y % 100 || y % 400 == 0 ? 29 : 28; //闰年调整
        if (y > 0 && m > 0 && m < 13 && d > 0 && d <= md[m - 1])
        { //日期合法
            e->biday.tm_year = y;
            e->biday.tm_mon = m;
            e->biday.tm_mday = d;
            break;
        }
        else //日期非法
        {
            gotoxy(bidayx, bidayy);
            cout << "日期格式错误，示例 1998 02 12";
            Sleep(400);
            gotoxy(bidayx, bidayy);
            for (k = 0; k < 30; k++)
                cout << " ";
            cin.sync(); //清除缓存区
            continue;
        }
    }

    //**post*******************************************************************
    while (1)
    {
        gotoxy(postx, posty);
        cin >> e->post; //输入 录入
        if (strlen(e->post) > 15)
        {
            gotoxy(postx, posty);
            cout << "职位过长,请重新输入";
            Sleep(400);
            gotoxy(postx, posty);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //清除缓存区
            continue;
        }

        for (j = 0; j < strlen(e->post); j++)
        {
            if (e->post[j] >= 0 && e->post[j] <= 255)
            {
                chTag = false;
                gotoxy(postx, posty);
                cout << "不是中文,请重新输入";
                Sleep(400);
                gotoxy(postx, posty);
                for (k = 0; k < 34; k++)
                    cout << " ";
                cin.sync(); //清除缓存区
                break;
            }
            chTag = true;
        }
        if (chTag)
        {
            break;
        }
    }

    //**depart*******************************************************************
    while (1)
    {
        gotoxy(departx, departy);
        cin >> e->depart; //输入 录入
        if (strlen(e->depart) > 15)
        {
            gotoxy(departx, departy);
            cout << "部门过长,请重新输入";
            Sleep(400);
            gotoxy(departx, departy);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //清除缓存区
            continue;
        }

        for (j = 0; j < strlen(e->depart); j++)
        {
            if (e->depart[j] >= 0 && e->depart[j] <= 255)
            {
                chTag = false;
                gotoxy(departx, departy);
                cout << "不是中文,请重新输入";
                Sleep(400);
                gotoxy(departx, departy);
                for (k = 0; k < 34; k++)
                    cout << " ";
                cin.sync(); //清除缓存区
                break;
            }
            chTag = true;
        }
        if (chTag)
        {
            break;
        }
    }

    //**worKh*******************************************************************
    while (1)
    {
        gotoxy(workhx, workhy);
        cin >> e->workh; //输入 录入
        if (cin.fail())
        {
            gotoxy(workhx, workhy);
            cout << "工时是数字,请重新输入";
            Sleep(400);
            gotoxy(workhx, workhy);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.clear(); //先用 cin.clear() 清除 fail 状态
            cin.sync();  //清除缓存区
            continue;
        }
        if (e->workh > 600 || e->workh < 0)
        {
            gotoxy(workhx, workhy);
            cout << "工时不合实际,请重新输入";
            Sleep(400);
            gotoxy(workhx, workhy);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //清除缓存区
            continue;
        }
        break;
    }
    e->next = head->next; //采用头插法将新节点的尾指针指向第二个节点
    head->next = e;       //将新节点放在头节点后面
    cout << "\n\t\t\t┗--->采集成功!\n";
    save();
    cout << "\n\t\t\t";
    system("pause");
    system("cls");
}

void adminInfo()
{
    int choice;
    do
    {
        if (head->next == NULL)
        {
            cout << "\n\t\t\t--->没有员工信息!!!\n\n"
                 << "\t\t\t--->请添加员工信息后再进行员工信息管理!!!\n\n"
                 << "\t\t\t--->即将返回主界面!!!\n";
            Sleep(3000);
            system("cls");
            return;
        }

        cout
            << "\t\t\t┏━━━━━━━━━━ 员工管理系统 ━━━━━━━━┓\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         1. 查询员工信息        ┃\n" //新增addInfo()
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         2. 修改员工信息        ┃\n" //查询find()  修改modify() 删除del() 排序sort();
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         3. 删除员工信息        ┃\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         4. 排序员工信息        ┃\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         0. 返回主界面          ┃\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
            << "\t\t\t请选择功能:";
        if (scanf("%d", &choice)) //判断输入的choice是否为整形
        {
            system("cls");
            switch (choice)
            {
            case 1:
                find();
                break;
            case 2:
                modify();
                break;
            case 3:
                del();
                break;
            case 4:
                sort();
                break;
            case 0:
                return;
            default:
                cout << "\n--->无效的指令!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t不能输入非整型，请重新输入：\n";
            cin.sync(); //清除缓冲区
            choice = 1; //防止跳出循环
        }
    } while (choice != 0);

    return;
}

void testInfo()
{
    cout << "\n*************************************功能建设中,即将返回上一步*************************************\n"
         << endl;
    Sleep(3000);
    system("cls");
}

//**退出程序*******************************************************************
void exitPms(int &choice)
{
    char c[100];
    cout << "\n\t\t\t确定退出？(y/n): ";
    while (1)
    {
        cin >> c;
        if ((strcmp(c, "n") != 0) && (strcmp(c, "y") != 0))
        {
            cout << ("\t\t\t请输入合法字符!\n");
            cout << ("\t\t\t请重新输入: ");
            cin.sync(); //清除缓冲区
        }
        if ((strcmp(c, "n") == 0) || (strcmp(c, "y") == 0))
        {
            break;
        }
    }
    if ((strcmp(c, "n") == 0))
    {
        cout << "\t\t\t不保存\n";
        choice = 1;
        return;
    }
    system("cls");
    cout
        << "\n\n"
        << "\t\t\t∷ ∷ ∷ ∷ ∷ ∷ ∷ ∷ ∷ ∷\n"
        << "\t\t\t∷ ∷ ∷ 谢谢使用 ∷ ∷ ∷ ∷\n"
        << "\t\t\t∷ ∷ ∷ ∷ ∷ ∷ ∷ ∷ ∷ ∷\n";
    // exit(0);
    return;
}

//**位置函数**********************************************************************
void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    /*COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：
    typedef struct _COORD {
    SHORT X; // horizontal coordinate
    SHORT Y; // vertical coordinate
    } COORD;*/

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//**保存员工文件*******************************************************************
void save()
{
    string str;
    cout << "\n\t\t\t确认保存？(y/n): ";
    while (1)
    {
        cin >> str;
        if (str == "n")
        {
            cout << "\t\t\t不保存\n";
            return;
        }
        else if (str == "y")
        {
            break;
        }
        else
        {
            cout << "\t\t\t请输入合法字符!\n";
            cout << "\t\t\t请重新输入: ";
            cin.sync(); //清除缓冲区
            continue;
        }
    }
    ofstream pmsFile(pmsFilePath, ios::out);
    if (!pmsFile.is_open())
    {
        cout << "无法打开pms.txt文件！！！" << endl;
        return;
    }

    //从头节点开始依次写入文件；
    for (e = head->next; e != NULL; e = e->next)
    {
        pmsFile << e->id << '\t' << e->name << '\t' << e->gender << '\t'
                << e->biday.tm_year << '\t' << e->biday.tm_mon << '\t' << e->biday.tm_mday << '\t'
                << e->post << '\t' << e->depart << '\t' << e->workh << endl;
    }
    pmsFile.close();
    cout << "\n\t\t\t--->信息成功存入\n\n";
    system("pause");
    system("cls");
}
//**读取员工文件*******************************************************************
void read()
{
    string line;
    ifstream pmsFile(pmsFilePath, ios::in);
    if (!pmsFile.is_open())
    {
        cout << "无法打开pms.txt文件！！！" << endl;
        return;
    }

    while (getline(pmsFile, line))
    {
        stringstream items(line);
        string id, gender, year, mon, mday, workh;
        etemp = new_node();
        items >> id >> etemp->name >> gender >> year >> mon >> mday >> etemp->post >> etemp->depart >> workh;
        etemp->id = stoi(id);
        etemp->gender = stoi(gender);
        etemp->biday.tm_year = stoi(year);
        etemp->biday.tm_mon = stoi(mon);
        etemp->biday.tm_mday = stoi(mday);
        etemp->workh = stoi(workh);

        etemp->next = head->next; //头插法建立链表
        head->next = etemp;
    }
    pmsFile.close();
}

//**修改员工信息*****************************************************************************
void modify()
{
    int id;
    bool exisTag = false;
    cout << "\n\t\t\t请输入您要修改员工的编号: ";
    if (scanf("%d", &id))
    {
        for (e = head; e != NULL; e = e->next)
        {
            if (e->id == id)
            {
                exisTag = true;
                modi_all();
                save();
                break;
            }
        }
    }
    if (!exisTag)
        cout << "\n\t\t\t--->没有该员工的信息!\n\n";
}
void modi_all()
{
    int choice;
    int j;
    do
    {
        bool repeatTag = false;
        bool chTag = false;
        int id;
        displayOneEmp(e);
        cout
            << "\n"
            << "\t\t\t*******************修改信息********************\n"
            << "\t\t\t*       1.修改编号        2.修改姓名          *\n"
            << "\t\t\t*       3.修正性别        4.修改生日          *\n"
            << "\t\t\t*       5.调动职位        6.调动部门          *\n"
            << "\t\t\t*       7.修改工时        0.返回              *\n"
            << "\t\t\t***********************************************\n"
            << "\t\t\t请选择：";
        if (scanf("%d", &choice))
        {
            switch (choice)
            {
                case 1:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请输入新的员工编号:__\b\b";
                        cin >> id; 
                        //检查输入是否合规
                        if (cin.fail() || id < 10000 || id > 99999)
                        {
                            cin.clear(); //先用 std::cin.clear() 清除 fail 状态
                            cin.sync();  //清除缓存区
                            cout << "工号是5位数字,请重新输入\n";
                            continue;
                        }
                        //查重
                        for (etemp = head->next; etemp != NULL; etemp = etemp->next)
                        {
                            if (etemp->id == id)
                            {
                                cin.sync();  //清除缓存区
                                repeatTag = false;
                                cout << "该编号已经存,请重新给予一个编号\n";
                                break;
                            }
                        }
                        if (etemp == NULL) //新节点
                        {
                            repeatTag = true;
                        }
                        if (id >= 10000 && id <= 99999 && repeatTag)
                        {
                            break;
                        } 
                    }
                    e->id=id;
                    cout<<"\n\t\t\t--->修改成功!\n";
                    break;
                }
                case 2:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请输入新的员工姓名:__\b\b";
                        cin >> e->name; //输入 录入
                        if (strlen(e->name) > 15)
                        {
                            cout << "姓名过长,请重新输入";
                            cin.sync(); //清除缓存区
                            continue;
                        }

                        for (j = 0; j < strlen(e->name); j++)
                        {
                            if (e->name[j] >= 0 && e->name[j] <= 255)
                            {
                                cin.sync(); //清除缓存区
                                chTag = false;
                                cout << "不是中文,请重新输入";
                                break;
                            }
                            chTag = true;
                        }
                        if (chTag)
                        {
                            break;
                        }
                    }
                    cout<<"\n\t\t\t--->修改成功!\n";
                    break;
                }
                case 3:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请修正员工性别:__\b\b";
                        string str;
                        cin >> str;      //输入
                        if (str == "男") //录入
                        {
                            e->gender = 0;
                            break;
                        }
                        else if (str == "女")
                        {
                            e->gender = 1;
                            break;
                        }
                        else
                        {
                            cout << "输入非法，请输入 男/女";
                            cin.sync(); //清除缓存区
                            continue;
                        }
                    }
                    cout<<"\n\t\t\t--->修改成功!\n";
                    break;
                }
                case 4:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请输入新的生日:__\b\b";
                        int y, m, d, md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //md是每月天数数组
                        cin>>y>>m>>d;
                        md[1] = y % 4 == 0 && y % 100 || y % 400 == 0 ? 29 : 28; //闰年调整
                        if (y > 0 && m > 0 && m < 13 && d > 0 && d <= md[m - 1])
                        { //日期合法
                            e->biday.tm_year = y;
                            e->biday.tm_mon = m;
                            e->biday.tm_mday = d;
                            break;
                        }
                        else //日期非法
                        {

                            cout << "日期格式错误，示例 1998 02 12";
                            cin.sync(); //清除缓存区
                            continue;
                        }
                    }
                    cout<<"\n\t\t\t--->修改成功!\n";
                    break;
                }
                case 5:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请输入新的职位:__\b\b";
                        cin >> e->post; //输入 录入
                        if (strlen(e->post) > 15)
                        {
                            cout << "职位过长,请重新输入";
                            cin.sync(); //清除缓存区
                            continue;
                        }

                        for (j = 0; j < strlen(e->post); j++)
                        {
                            if (e->post[j] >= 0 && e->post[j] <= 255)
                            {
                                chTag = false;
                                cout << "不是中文,请重新输入";
                                cin.sync(); //清除缓存区
                                break;
                            }
                            chTag = true;
                        }
                        if (chTag)
                        {
                            break;
                        }
                    }
                    cout<<"\n\t\t\t--->修改成功!\n";
                    break;
                }
                case 6:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请输入新的部门:__\b\b";
                        cin >> e->depart; //输入 录入
                        if (strlen(e->depart) > 15)
                        {
                            cout << "部门过长,请重新输入";
                            cin.sync(); //清除缓存区
                            continue;
                        }
                        for (j = 0; j < strlen(e->depart); j++)
                        {
                            if (e->depart[j] >= 0 && e->depart[j] <= 255)
                            {
                                chTag = false;
                                cout << "不是中文,请重新输入";
                                cin.sync(); //清除缓存区
                                break;
                            }
                            chTag = true;
                        }
                        if (chTag)
                        {
                            break;
                        }
                        cout<<"\n\t\t\t--->修改成功!\n";
                        break;
                    }
                }
                case 7:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*请输入新的工时:__\b\b";
                        cin >> e->workh; //输入 录入
                        if (cin.fail())
                        {
                            cin.clear(); //先用 cin.clear() 清除 fail 状态
                            cin.sync();  //清除缓存区
                            cout << "工时是数字,请重新输入";
                            continue;
                        }
                        if (e->workh > 600 || e->workh < 0)
                        {
                            cin.sync(); //清除缓存区
                            cout << "工时不合实际,请重新输入";
                            continue;
                        }
                        break;
                    }
                    cout<<"\n\t\t\t--->修改成功!\n";
                    break;
                }
                case 0:
                    return;
                default:
                    cout<<"\n\t\t\t--->无效的指令!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t不能输入非整型，请重新输入：\n";
            cin.sync(); //清除缓冲区
            choice = 1; //防止跳出循环
        }
    } while (choice != 0);
    return;
};

//**删除员工信息*****************************************************************************
void del()
{
    int id;
    bool exisTag = false;
    cout << "\n\t\t\t请输入您要修改员工的编号: ";
    if (scanf("%d", &id))
    {
        for (etemp = head; etemp != NULL; etemp = etemp->next)
        {
            if (etemp->id == id)
            {
                exisTag = true;
                displayOneEmp(etemp);
                e->next=etemp->next;
                delete etemp;
                cout << "\n\t\t\t--->该员工信息已被清除!\n\n";
                save();
                break;
            }
            e=etemp;
        }
    }
    if (!exisTag)
        cout << "\n\t\t\t--->没有该员工的信息!\n\n";
}

//**排序员工信息*****************************************************************************
void sort()
{
    testInfo();
}

//**查询员工信息*****************************************************************************
void find()
{
    int choice;
    do
    {
        cout
            << "\t\t\t********************************\n"
            << "\t\t\t*        1.按工号查找          *\n"
            << "\t\t\t*        2.按姓名查找          *\n"
            << "\t\t\t*        3.按姓名和工号查找    *\n"
            << "\t\t\t*        0.返回上一步          *\n"
            << "\t\t\t********************************\n"
            << "\t\t\t请选择：";
        if (scanf("%d", &choice))
        {
            system("cls");
            switch (choice)
            {
            case 1:
                find_name();
                break;
            case 2:
                find_num();
                break;
            case 3:
                find_namenum();
                break;
            case 0:
                return;
            default:
                cout << "\n\t\t\t--->无效的指令!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t不能输入非整型，请重新输入：\n";
            cin.sync(); //清除缓冲区
            choice = 1; //防止跳出循环
        }
    } while (choice != 0);
    return;
}

void find_name()
{
    testInfo();
}
void find_num()
{
    testInfo();
}
void find_namenum()
{
    testInfo();
}

//**打印该公司所有员工的信息*******************************************************************
void displayInfo()
{
    read();


    int n = 0;
    if (head->next == NULL)
    {
        cout << "--->没有员工信息!\n";
        return;
    }
    cout << "\n"
         << setiosflags(ios::left) << setw(10) << "编号" << setw(10) << "姓名" << setw(10) << "性别" << setw(15) << "出生日期" << setw(15) << "职位" << setw(15) << "部门" << setw(15) << "工时" << endl;
    cout << "┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n";
    for (etemp = head->next; etemp != NULL; etemp = etemp->next)
    {
        n++;
        string gender, biday, workh;
        biday = to_string(etemp->biday.tm_year) + "-" + to_string(etemp->biday.tm_mon) + "-" + to_string(etemp->biday.tm_mday);
        gender = etemp->gender == 0 ? "男" : "女";
        workh = to_string(etemp->workh) + "小时";
        cout << setiosflags(ios::left) << setw(10) << etemp->id << setw(10) << etemp->name << setw(10) << gender
             << setw(15) << biday << setw(15) << etemp->post << setw(15) << etemp->depart << setw(15) << workh << endl;

        cout << "┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n";
    }
    cout << "\n--->该公司共有" << n << "个员工.\n\n";
    system("pause");
    system("cls");
}

//**打印当前选中员工的信息*******************************************************************
void displayOneEmp(emp* e)
{
    cout << "\n\t\t\t\t*员工初始信息*\n";
    cout << "┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n";
    cout << setiosflags(ios::left) << setw(10) << "编号" << setw(10) << "姓名" << setw(10) << "性别" << setw(15) << "出生日期" << setw(15) << "职位" << setw(15) << "部门" << setw(15) << "工时" << endl;
    cout << "┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n";
    string gender, biday, workh;
    biday = to_string(e->biday.tm_year) + "-" + to_string(e->biday.tm_mon) + "-" + to_string(e->biday.tm_mday);
    gender = e->gender == 0 ? "男" : "女";
    workh = to_string(e->workh) + "小时";
    cout << setiosflags(ios::left) << setw(10) << e->id << setw(10) << e->name << setw(10) << gender
            << setw(15) << biday << setw(15) << e->post << setw(15) << e->depart << setw(15) << workh << endl;
    cout << "┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n";
}

//**程序入口*******************************************************************
int main()
{
    int choice;
    head = new_node();
    read();
    //初始化界面
    system("color 3f");
    do
    {
        cout
            << "\t\t\t┏━━━━━━━━━━ 员工管理系统 ━━━━━━━━┓\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         1. 采集员工信息        ┃\n" //新增addInfo()
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         2. 管理员工信息        ┃\n" //查询find()  修改modify() 删除del() 排序sort();
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         3. 浏览员工信息        ┃\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┃         0. 退出管理系统        ┃\n"
            << "\t\t\t┃                                ┃\n"
            << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
            << "\t\t\t请选择功能:";
        if (scanf("%d", &choice)) //判断输入的choice是否为整形
        {
            system("cls");
            switch (choice)
            {
            case 1:
                addInfo();
                break;
            case 2:
                adminInfo();
                break;
            case 3:
                displayInfo();
                break;
            case 0:
                exitPms(choice);
                break;
            default:
                cout << "\n--->无效的指令!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t不能输入非整型，请重新输入：\n";
            cin.sync(); //清除缓冲区
            choice = 1; //防止跳出循环
        }
    } while (choice != 0);

    system("pause");
    return 0;
}
