/*
 * @Description  : 
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-27 13:08:56
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-27 13:11:09
 */
#include <iostream>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line(double len); // 这是构造函数

private:
    double length;
};

// 成员函数定义，包括构造函数
Line::Line(double length) : length(length + 100)
{
    cout << "Object is being created, paraparaparaparaparalength = " << length << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}
// 程序的主函数
int main()
{
    Line line(10.0);

    // 获取默认设置的长度
    cout << "Length of line : " << line.getLength() << endl;
    // 再次设置长度
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

    return 0;
}