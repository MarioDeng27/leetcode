/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-04 22:56:50
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-04 22:57:12
 */
#include <iostream>

#include <stdlib.h> //rand()，srand()函数在这个头文件中
#include <time.h>   //time(0)在这个头文件中
#include <unordered_set>
using namespace std;
int main()
{
    const int MAX = 100;
    unordered_set<int> myset;
    srand(time(nullptr));
    while (myset.size() < 10)
    {
        int a = rand() % MAX + 1;
        if (myset.count(a) == 0)
            myset.insert(a);
    }
    for (auto s : myset)
        cout << s << " ";
    /* int arr[10];
    int i = 0;
    bool ret = false;
    srand((unsigned)time(NULL));
    while (1)
    {
        arr[i] = rand() % MAX + 1;

        for (int j = 0; j < i; j++)

        {
            if (arr[j] == arr[i])

                ret = true;
        }
        if (!ret)
        {
            i++;
            ret = false;
        }
        if (i == 10)
        {
            break;
        }
    }
    while (--i)
    {
        cout << arr[i] << " ";
    }
    cout << arr[0] << endl; */
}