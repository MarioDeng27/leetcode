/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 14:03:01
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 14:03:24
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string his, target;
    cin >> his >> target;

    int cnt = 0;
    for (int i = 0; i < his.size(); i++)
    {
        if ((his[i] >= 'a' && his[i] <= 'z') || (his[i] >= 'A' && his[i] <= 'Z') || (his[i] >= '0' && his[i] <= '9'))
        {
            if (target[i] == '1')
                cnt++;
        }
        else
        {
            if (target[i] == '0')
                cnt++;
        }
    }
    double result = cnt * 100.0 / his.size();
    printf("%.2lf%%\n", result);
}