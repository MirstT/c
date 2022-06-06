/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2022-04-11 13:29:35
 * @LastEditors  : Mirst
 * @LastEditTime : 2022-04-11 13:29:38
 */
//ͷ�ļ�����
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

//�ļ�·��
const string pmsFilePath = "pms.txt";

//���� ��Ļ����λ��
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

//Ա������� ���� �Ա� �������� ְλ ���� ��ʱ
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
emp *head, *e, *etemp; //ͷָ��
//**��������***********************************************************************************
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

//����Ա����㺯��   û��ͷ���
emp *new_node()
{
    e = new emp;
    e->next = nullptr;
    return e;
}

//**�ɼ���Ϣ************************************************************************************
void addInfo()
{
    system("cls");
    int j, k;
    bool repeatTag = false;
    bool chTag = false;

    e = new_node(); //�½�һ���ڵ�
    cout
        << "\t\t\t�������������������������������ɼ�Ա����Ϣ��������������������������������\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t�����:                                    ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t������:                                    ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t���Ա�:                                    ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t����������:                                ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t��ְλ:                                    ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t������:                                    ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t����ʱ:                                    ��\n"
        << "\t\t\t��                                         ��\n"
        << "\t\t\t��������������������������������������������������������������������������������������\n";

    //**id*******************************************************************
    while (1)
    {
        gotoxy(idx, idy);
        cin >> e->id; //���� ¼��
        //��������Ƿ�Ϲ�
        if (cin.fail() || e->id < 10000 || e->id > 99999)
        {
            cin.clear(); //���� std::cin.clear() ��� fail ״̬
            cin.sync();  //���������
            gotoxy(idx, idy);
            cout << "������5λ����,����������";
            Sleep(400);
            gotoxy(idx, idy);
            for (k = 0; k < 34; k++)
                cout << " ";
            continue;
        }
        //����
        for (etemp = head->next; etemp != NULL; etemp = etemp->next)
        {
            if (etemp->id == e->id)
            {
                cin.sync();  //���������
                repeatTag = false;
                gotoxy(idx, idy);
                cout << "�ñ���Ѿ���,�����¸���һ�����";
                Sleep(400);
                gotoxy(idx, idy);
                for (k = 0; k < 34; k++)
                    cout << " ";
                break;
            }
        }
        if (etemp == NULL) //�½ڵ�
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
        cin >> e->name; //���� ¼��
        if (strlen(e->name) > 15)
        {
            gotoxy(namex, namey);
            cout << "��������,����������";
            Sleep(400);
            gotoxy(namex, namey);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //���������
            continue;
        }

        for (j = 0; j < strlen(e->name); j++)
        {
            if (e->name[j] >= 0 && e->name[j] <= 255)
            {
                chTag = false;
                gotoxy(namex, namey);
                cout << "��������,����������";
                Sleep(400);
                gotoxy(namex, namey);
                for (k = 0; k < 34; k++)
                    cout << " ";
                cin.sync(); //���������
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
        cin >> str;      //����
        if (str == "��") //¼��
        {
            e->gender = 0;
            break;
        }
        else if (str == "Ů")
        {
            e->gender = 1;
            break;
        }
        else
        {
            gotoxy(genderx, gendery);
            cout << "����Ƿ��������� ��/Ů";
            Sleep(400);
            gotoxy(genderx, gendery);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //���������
            continue;
        }
    }

    //biday*******************************************************************
    while (1)
    {
        gotoxy(bidayx, bidayy);
        int y, m, d, md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //md��ÿ����������
        scanf("%d%d%d", &y, &m, &d);
        md[1] = y % 4 == 0 && y % 100 || y % 400 == 0 ? 29 : 28; //�������
        if (y > 0 && m > 0 && m < 13 && d > 0 && d <= md[m - 1])
        { //���ںϷ�
            e->biday.tm_year = y;
            e->biday.tm_mon = m;
            e->biday.tm_mday = d;
            break;
        }
        else //���ڷǷ�
        {
            gotoxy(bidayx, bidayy);
            cout << "���ڸ�ʽ����ʾ�� 1998 02 12";
            Sleep(400);
            gotoxy(bidayx, bidayy);
            for (k = 0; k < 30; k++)
                cout << " ";
            cin.sync(); //���������
            continue;
        }
    }

    //**post*******************************************************************
    while (1)
    {
        gotoxy(postx, posty);
        cin >> e->post; //���� ¼��
        if (strlen(e->post) > 15)
        {
            gotoxy(postx, posty);
            cout << "ְλ����,����������";
            Sleep(400);
            gotoxy(postx, posty);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //���������
            continue;
        }

        for (j = 0; j < strlen(e->post); j++)
        {
            if (e->post[j] >= 0 && e->post[j] <= 255)
            {
                chTag = false;
                gotoxy(postx, posty);
                cout << "��������,����������";
                Sleep(400);
                gotoxy(postx, posty);
                for (k = 0; k < 34; k++)
                    cout << " ";
                cin.sync(); //���������
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
        cin >> e->depart; //���� ¼��
        if (strlen(e->depart) > 15)
        {
            gotoxy(departx, departy);
            cout << "���Ź���,����������";
            Sleep(400);
            gotoxy(departx, departy);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //���������
            continue;
        }

        for (j = 0; j < strlen(e->depart); j++)
        {
            if (e->depart[j] >= 0 && e->depart[j] <= 255)
            {
                chTag = false;
                gotoxy(departx, departy);
                cout << "��������,����������";
                Sleep(400);
                gotoxy(departx, departy);
                for (k = 0; k < 34; k++)
                    cout << " ";
                cin.sync(); //���������
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
        cin >> e->workh; //���� ¼��
        if (cin.fail())
        {
            gotoxy(workhx, workhy);
            cout << "��ʱ������,����������";
            Sleep(400);
            gotoxy(workhx, workhy);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.clear(); //���� cin.clear() ��� fail ״̬
            cin.sync();  //���������
            continue;
        }
        if (e->workh > 600 || e->workh < 0)
        {
            gotoxy(workhx, workhy);
            cout << "��ʱ����ʵ��,����������";
            Sleep(400);
            gotoxy(workhx, workhy);
            for (k = 0; k < 34; k++)
                cout << " ";
            cin.sync(); //���������
            continue;
        }
        break;
    }
    e->next = head->next; //����ͷ�巨���½ڵ��βָ��ָ��ڶ����ڵ�
    head->next = e;       //���½ڵ����ͷ�ڵ����
    cout << "\n\t\t\t��--->�ɼ��ɹ�!\n";
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
            cout << "\n\t\t\t--->û��Ա����Ϣ!!!\n\n"
                 << "\t\t\t--->�����Ա����Ϣ���ٽ���Ա����Ϣ����!!!\n\n"
                 << "\t\t\t--->��������������!!!\n";
            Sleep(3000);
            system("cls");
            return;
        }

        cout
            << "\t\t\t���������������������� Ա������ϵͳ ������������������\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         1. ��ѯԱ����Ϣ        ��\n" //����addInfo()
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         2. �޸�Ա����Ϣ        ��\n" //��ѯfind()  �޸�modify() ɾ��del() ����sort();
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         3. ɾ��Ա����Ϣ        ��\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         4. ����Ա����Ϣ        ��\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         0. ����������          ��\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��������������������������������������������������������������������\n"
            << "\t\t\t��ѡ����:";
        if (scanf("%d", &choice)) //�ж������choice�Ƿ�Ϊ����
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
                cout << "\n--->��Ч��ָ��!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t������������ͣ����������룺\n";
            cin.sync(); //���������
            choice = 1; //��ֹ����ѭ��
        }
    } while (choice != 0);

    return;
}

void testInfo()
{
    cout << "\n*************************************���ܽ�����,����������һ��*************************************\n"
         << endl;
    Sleep(3000);
    system("cls");
}

//**�˳�����*******************************************************************
void exitPms(int &choice)
{
    char c[100];
    cout << "\n\t\t\tȷ���˳���(y/n): ";
    while (1)
    {
        cin >> c;
        if ((strcmp(c, "n") != 0) && (strcmp(c, "y") != 0))
        {
            cout << ("\t\t\t������Ϸ��ַ�!\n");
            cout << ("\t\t\t����������: ");
            cin.sync(); //���������
        }
        if ((strcmp(c, "n") == 0) || (strcmp(c, "y") == 0))
        {
            break;
        }
    }
    if ((strcmp(c, "n") == 0))
    {
        cout << "\t\t\t������\n";
        choice = 1;
        return;
    }
    system("cls");
    cout
        << "\n\n"
        << "\t\t\t�� �� �� �� �� �� �� �� �� ��\n"
        << "\t\t\t�� �� �� ллʹ�� �� �� �� ��\n"
        << "\t\t\t�� �� �� �� �� �� �� �� �� ��\n";
    // exit(0);
    return;
}

//**λ�ú���**********************************************************************
void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    /*COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��
    typedef struct _COORD {
    SHORT X; // horizontal coordinate
    SHORT Y; // vertical coordinate
    } COORD;*/

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//**����Ա���ļ�*******************************************************************
void save()
{
    string str;
    cout << "\n\t\t\tȷ�ϱ��棿(y/n): ";
    while (1)
    {
        cin >> str;
        if (str == "n")
        {
            cout << "\t\t\t������\n";
            return;
        }
        else if (str == "y")
        {
            break;
        }
        else
        {
            cout << "\t\t\t������Ϸ��ַ�!\n";
            cout << "\t\t\t����������: ";
            cin.sync(); //���������
            continue;
        }
    }
    ofstream pmsFile(pmsFilePath, ios::out);
    if (!pmsFile.is_open())
    {
        cout << "�޷���pms.txt�ļ�������" << endl;
        return;
    }

    //��ͷ�ڵ㿪ʼ����д���ļ���
    for (e = head->next; e != NULL; e = e->next)
    {
        pmsFile << e->id << '\t' << e->name << '\t' << e->gender << '\t'
                << e->biday.tm_year << '\t' << e->biday.tm_mon << '\t' << e->biday.tm_mday << '\t'
                << e->post << '\t' << e->depart << '\t' << e->workh << endl;
    }
    pmsFile.close();
    cout << "\n\t\t\t--->��Ϣ�ɹ�����\n\n";
    system("pause");
    system("cls");
}
//**��ȡԱ���ļ�*******************************************************************
void read()
{
    string line;
    ifstream pmsFile(pmsFilePath, ios::in);
    if (!pmsFile.is_open())
    {
        cout << "�޷���pms.txt�ļ�������" << endl;
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

        etemp->next = head->next; //ͷ�巨��������
        head->next = etemp;
    }
    pmsFile.close();
}

//**�޸�Ա����Ϣ*****************************************************************************
void modify()
{
    int id;
    bool exisTag = false;
    cout << "\n\t\t\t��������Ҫ�޸�Ա���ı��: ";
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
        cout << "\n\t\t\t--->û�и�Ա������Ϣ!\n\n";
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
            << "\t\t\t*******************�޸���Ϣ********************\n"
            << "\t\t\t*       1.�޸ı��        2.�޸�����          *\n"
            << "\t\t\t*       3.�����Ա�        4.�޸�����          *\n"
            << "\t\t\t*       5.����ְλ        6.��������          *\n"
            << "\t\t\t*       7.�޸Ĺ�ʱ        0.����              *\n"
            << "\t\t\t***********************************************\n"
            << "\t\t\t��ѡ��";
        if (scanf("%d", &choice))
        {
            switch (choice)
            {
                case 1:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*�������µ�Ա�����:__\b\b";
                        cin >> id; 
                        //��������Ƿ�Ϲ�
                        if (cin.fail() || id < 10000 || id > 99999)
                        {
                            cin.clear(); //���� std::cin.clear() ��� fail ״̬
                            cin.sync();  //���������
                            cout << "������5λ����,����������\n";
                            continue;
                        }
                        //����
                        for (etemp = head->next; etemp != NULL; etemp = etemp->next)
                        {
                            if (etemp->id == id)
                            {
                                cin.sync();  //���������
                                repeatTag = false;
                                cout << "�ñ���Ѿ���,�����¸���һ�����\n";
                                break;
                            }
                        }
                        if (etemp == NULL) //�½ڵ�
                        {
                            repeatTag = true;
                        }
                        if (id >= 10000 && id <= 99999 && repeatTag)
                        {
                            break;
                        } 
                    }
                    e->id=id;
                    cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                    break;
                }
                case 2:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*�������µ�Ա������:__\b\b";
                        cin >> e->name; //���� ¼��
                        if (strlen(e->name) > 15)
                        {
                            cout << "��������,����������";
                            cin.sync(); //���������
                            continue;
                        }

                        for (j = 0; j < strlen(e->name); j++)
                        {
                            if (e->name[j] >= 0 && e->name[j] <= 255)
                            {
                                cin.sync(); //���������
                                chTag = false;
                                cout << "��������,����������";
                                break;
                            }
                            chTag = true;
                        }
                        if (chTag)
                        {
                            break;
                        }
                    }
                    cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                    break;
                }
                case 3:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*������Ա���Ա�:__\b\b";
                        string str;
                        cin >> str;      //����
                        if (str == "��") //¼��
                        {
                            e->gender = 0;
                            break;
                        }
                        else if (str == "Ů")
                        {
                            e->gender = 1;
                            break;
                        }
                        else
                        {
                            cout << "����Ƿ��������� ��/Ů";
                            cin.sync(); //���������
                            continue;
                        }
                    }
                    cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                    break;
                }
                case 4:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*�������µ�����:__\b\b";
                        int y, m, d, md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //md��ÿ����������
                        cin>>y>>m>>d;
                        md[1] = y % 4 == 0 && y % 100 || y % 400 == 0 ? 29 : 28; //�������
                        if (y > 0 && m > 0 && m < 13 && d > 0 && d <= md[m - 1])
                        { //���ںϷ�
                            e->biday.tm_year = y;
                            e->biday.tm_mon = m;
                            e->biday.tm_mday = d;
                            break;
                        }
                        else //���ڷǷ�
                        {

                            cout << "���ڸ�ʽ����ʾ�� 1998 02 12";
                            cin.sync(); //���������
                            continue;
                        }
                    }
                    cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                    break;
                }
                case 5:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*�������µ�ְλ:__\b\b";
                        cin >> e->post; //���� ¼��
                        if (strlen(e->post) > 15)
                        {
                            cout << "ְλ����,����������";
                            cin.sync(); //���������
                            continue;
                        }

                        for (j = 0; j < strlen(e->post); j++)
                        {
                            if (e->post[j] >= 0 && e->post[j] <= 255)
                            {
                                chTag = false;
                                cout << "��������,����������";
                                cin.sync(); //���������
                                break;
                            }
                            chTag = true;
                        }
                        if (chTag)
                        {
                            break;
                        }
                    }
                    cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                    break;
                }
                case 6:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*�������µĲ���:__\b\b";
                        cin >> e->depart; //���� ¼��
                        if (strlen(e->depart) > 15)
                        {
                            cout << "���Ź���,����������";
                            cin.sync(); //���������
                            continue;
                        }
                        for (j = 0; j < strlen(e->depart); j++)
                        {
                            if (e->depart[j] >= 0 && e->depart[j] <= 255)
                            {
                                chTag = false;
                                cout << "��������,����������";
                                cin.sync(); //���������
                                break;
                            }
                            chTag = true;
                        }
                        if (chTag)
                        {
                            break;
                        }
                        cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                        break;
                    }
                }
                case 7:
                {
                    while (1)
                    {
                        cout<<"\n\t\t\t*�������µĹ�ʱ:__\b\b";
                        cin >> e->workh; //���� ¼��
                        if (cin.fail())
                        {
                            cin.clear(); //���� cin.clear() ��� fail ״̬
                            cin.sync();  //���������
                            cout << "��ʱ������,����������";
                            continue;
                        }
                        if (e->workh > 600 || e->workh < 0)
                        {
                            cin.sync(); //���������
                            cout << "��ʱ����ʵ��,����������";
                            continue;
                        }
                        break;
                    }
                    cout<<"\n\t\t\t--->�޸ĳɹ�!\n";
                    break;
                }
                case 0:
                    return;
                default:
                    cout<<"\n\t\t\t--->��Ч��ָ��!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t������������ͣ����������룺\n";
            cin.sync(); //���������
            choice = 1; //��ֹ����ѭ��
        }
    } while (choice != 0);
    return;
};

//**ɾ��Ա����Ϣ*****************************************************************************
void del()
{
    int id;
    bool exisTag = false;
    cout << "\n\t\t\t��������Ҫ�޸�Ա���ı��: ";
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
                cout << "\n\t\t\t--->��Ա����Ϣ�ѱ����!\n\n";
                save();
                break;
            }
            e=etemp;
        }
    }
    if (!exisTag)
        cout << "\n\t\t\t--->û�и�Ա������Ϣ!\n\n";
}

//**����Ա����Ϣ*****************************************************************************
void sort()
{
    testInfo();
}

//**��ѯԱ����Ϣ*****************************************************************************
void find()
{
    int choice;
    do
    {
        cout
            << "\t\t\t********************************\n"
            << "\t\t\t*        1.�����Ų���          *\n"
            << "\t\t\t*        2.����������          *\n"
            << "\t\t\t*        3.�������͹��Ų���    *\n"
            << "\t\t\t*        0.������һ��          *\n"
            << "\t\t\t********************************\n"
            << "\t\t\t��ѡ��";
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
                cout << "\n\t\t\t--->��Ч��ָ��!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t������������ͣ����������룺\n";
            cin.sync(); //���������
            choice = 1; //��ֹ����ѭ��
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

//**��ӡ�ù�˾����Ա������Ϣ*******************************************************************
void displayInfo()
{
    read();


    int n = 0;
    if (head->next == NULL)
    {
        cout << "--->û��Ա����Ϣ!\n";
        return;
    }
    cout << "\n"
         << setiosflags(ios::left) << setw(10) << "���" << setw(10) << "����" << setw(10) << "�Ա�" << setw(15) << "��������" << setw(15) << "ְλ" << setw(15) << "����" << setw(15) << "��ʱ" << endl;
    cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
    for (etemp = head->next; etemp != NULL; etemp = etemp->next)
    {
        n++;
        string gender, biday, workh;
        biday = to_string(etemp->biday.tm_year) + "-" + to_string(etemp->biday.tm_mon) + "-" + to_string(etemp->biday.tm_mday);
        gender = etemp->gender == 0 ? "��" : "Ů";
        workh = to_string(etemp->workh) + "Сʱ";
        cout << setiosflags(ios::left) << setw(10) << etemp->id << setw(10) << etemp->name << setw(10) << gender
             << setw(15) << biday << setw(15) << etemp->post << setw(15) << etemp->depart << setw(15) << workh << endl;

        cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
    }
    cout << "\n--->�ù�˾����" << n << "��Ա��.\n\n";
    system("pause");
    system("cls");
}

//**��ӡ��ǰѡ��Ա������Ϣ*******************************************************************
void displayOneEmp(emp* e)
{
    cout << "\n\t\t\t\t*Ա����ʼ��Ϣ*\n";
    cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
    cout << setiosflags(ios::left) << setw(10) << "���" << setw(10) << "����" << setw(10) << "�Ա�" << setw(15) << "��������" << setw(15) << "ְλ" << setw(15) << "����" << setw(15) << "��ʱ" << endl;
    cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
    string gender, biday, workh;
    biday = to_string(e->biday.tm_year) + "-" + to_string(e->biday.tm_mon) + "-" + to_string(e->biday.tm_mday);
    gender = e->gender == 0 ? "��" : "Ů";
    workh = to_string(e->workh) + "Сʱ";
    cout << setiosflags(ios::left) << setw(10) << e->id << setw(10) << e->name << setw(10) << gender
            << setw(15) << biday << setw(15) << e->post << setw(15) << e->depart << setw(15) << workh << endl;
    cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
}

//**�������*******************************************************************
int main()
{
    int choice;
    head = new_node();
    read();
    //��ʼ������
    system("color 3f");
    do
    {
        cout
            << "\t\t\t���������������������� Ա������ϵͳ ������������������\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         1. �ɼ�Ա����Ϣ        ��\n" //����addInfo()
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         2. ����Ա����Ϣ        ��\n" //��ѯfind()  �޸�modify() ɾ��del() ����sort();
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         3. ���Ա����Ϣ        ��\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��         0. �˳�����ϵͳ        ��\n"
            << "\t\t\t��                                ��\n"
            << "\t\t\t��������������������������������������������������������������������\n"
            << "\t\t\t��ѡ����:";
        if (scanf("%d", &choice)) //�ж������choice�Ƿ�Ϊ����
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
                cout << "\n--->��Ч��ָ��!\n";
            }
        }
        else
        {
            cout << "\n\t\t\t������������ͣ����������룺\n";
            cin.sync(); //���������
            choice = 1; //��ֹ����ѭ��
        }
    } while (choice != 0);

    system("pause");
    return 0;
}
