/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 14:16:11
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 14:16:13
 */
#include <iostream>
using namespace std;

int getAns(int m)
{
    if (m == 1)
        return 0;
    if (m == 2)
        return 1;
    if (m == 3)
        return 2;
    int pre1 = 1, pre2 = 2;
    int res;
    for (int i = 4; i <= m; i++)
    {
        res = pre1 + pre2;
        pre1 = pre2;
        pre2 = res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << getAns(m) << endl;
    }
    return 0;
}