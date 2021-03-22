/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-21 17:12:31
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-21 17:12:32
 */
//https://www.nowcoder.com/test/question/ebf85b76361245f4a3ac273e6876c662?pid=21283868&tid=42470284
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串
     */
    string compress(string str)
    {
        // write code here
        stack<string> stStr;
        stack<int> stNum;
        string tmp = "";
        int time = 0;
        for (auto chr : str)
        {
            if (chr == '[')
            {
                continue;
            }
            if (chr == ']')
            {
                int num = stNum.top();
                tmp = stStr.top() + getStr(num, tmp);
                stNum.pop();
                stStr.pop();
            }
            if (isAlpha(chr))
            {
                tmp += chr;
            }
            if (isNum(chr))
            {
                int num = chr - '0';
                time = 10 * time + num;
            }
            if (chr == '|')
            {
                stNum.push(time);
                stStr.push(tmp);
                time = 0;
                tmp = "";
            }
        }
        return tmp;
    }
    bool isNum(char chr)
    {
        return (chr >= '0' && chr <= '9');
    }
    bool isAlpha(char chr)
    {
        return ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
    }
    string getStr(int cnt, string str)
    {
        string tmp;
        while (cnt--)
        {
            tmp += str;
        }
        return tmp;
    }
};