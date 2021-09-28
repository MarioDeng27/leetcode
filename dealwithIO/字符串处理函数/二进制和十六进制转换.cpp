/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-28 14:32:07
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-28 14:42:44
 */
#include <bitset>
#include <iostream>
using namespace std;
//正负数都可以
bitset<numeric_limits<unsigned int>::digits> s(123);
string str = s.to_string();
cout << str.substr(16, 16);

//C中
printf("%05o\n", 35); //按八进制格式输出，保留5位高位补零
printf("%03d\n", 35); //按十进制格式输出，保留3位高位补零
printf("%05x\n", 35); //按十六进制格式输出，保留5位高位补零

//C++中
int main()
{
    cout << "35的8进制:" << std::oct << 35 << endl;
    cout << "35的10进制" << std::dec << 35 << endl;
    cout << "35的16进制:" << std::hex << 35 << endl;
    cout << "35的2进制: " << bitset<8>(35) << endl; //<8>：表示保留8位输出
    return 0;
}
/*
二.C/C++各种进制转换库函数

1.任意2~36进制数转化为10进制

自己实现函数

*/
int Atoint(string s, int radix) //s是给定的radix进制字符串
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char t = s[i];
        if (t >= '0' && t <= '9')
            ans = ans * radix + t - '0';
        else
            ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}
/*
2.将10进制数转换为任意的n进制数，结果为char型。

自己实现函数

*/
string intToA(int n, int radix) //n是待转数字，radix是指定的进制
{
    string ans = "";
    do
    {
        int t = n % radix;
        if (t >= 0 && t <= 9)
            ans += t + '0';
        else
            ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0); //使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(), ans.end());
    return ans;
}

/*
1）itoa（）函数（可以将一个10进制数转换为任意的2-36进制字符串）:

函数原型：char*itoa(int value,char*string,int radix);

格式：itoa(num, str, 2); num是一个int型的，是要转化的10进制数，str是转化结果，后面的值为目标进制。

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num = 10;
    char str[100];
    _itoa(num, str, 2); //c++中一般用_itoa，用itoa也行,
    printf("%s\n", str);
    return 0;
}
/*
三.使用字符串流string，stream

1）8,16->10

*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(void)
{
    string s = "20";
    int a;
    stringstream ss;
    ss << hex << s; //以16进制读入流中
    ss >> a;        //10进制int型输出
    cout << a << endl;
    return 0;
}
//输出：32

/*

2)10->8,16

*/
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(void)
{
    string s1, s2;
    int a = 30;
    stringstream ss;
    ss << oct << a; //10进制转成八进制读入流中，再以字符串输出
    ss >> s1;
    cout << s1 << endl; //输出：36
    ss.clear();         //不清空可能会出错。
    ss << hex << a;     //10进制转成十六进制读入流中，，再以字符串输出
    ss >> s2;
    cout << s2 << endl; //输出：1e
    return 0;
}