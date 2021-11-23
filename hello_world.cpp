/*
 * @Description  :  
 * @version      : 
 * @Author       : Mirst
 * @Date         : 2021-11-23 05:54:37
 * @LastEditors  : Mirst
 * @LastEditTime : 2021-11-23 17:18:43
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
