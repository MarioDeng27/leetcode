/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-30 17:21:49
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-30 17:21:50
 */
map<string, int> m = {{"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}, {"2", 15}, {"joker", 16}, {"JOKER", 17}};
int getType(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
            cnt++;
    }
    if (cnt == 0)
        return 1;
    if (cnt == 1)
    {
        if (str == "joker JOKER")
            return 6;
        return 2;
    }
    if (cnt == 2)
        return 3;
    if (cnt == 3)
        return 5;
    if (cnt == 4)
        return 4;
    return -1;
}
string getFirst(string str)
{
    string tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            break;
        }
        else
            tmp += str[i];
    }
    return tmp;
}
string getAns(string str)

{
    string a;
    string b;
    string tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '-')
        {
            a = tmp;
            tmp = "";
        }
        else
            tmp += str[i];
    }
    b = tmp;

    if (getType(a) == getType(b))
        return m[getFirst(a)] > m[getFirst(b)] ? a : b;
    else if (getType(a) >= 1 && getType(a) <= 4 && getType(b) == 5)
        return b;
    else if (getType(b) >= 1 && getType(b) <= 4 && getType(a) == 5)
        return a;
    else if (getType(a) == 6)
        return a;
    else if (getType(b) == 6)
        return b;
    else
        return "ERROR";
}

int main()
{
    string str;
    cout << "start" << endl;
    while (getline(cin, str))
    {
        cout << getAns(str) << endl;
    }
    return 0;
}