/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-05 17:26:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 17:26:22
 */
class Solution
{
public:
    bool check(string s, string t)
    {
        int m = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == t[m])
            {
                m++;
            }
        }
        return m == t.size();
    }

    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(),
             [](auto &a, auto &b)
             {
                 if (a.size() != b.size())
                 {
                     return a.size() > b.size();
                 }
                 else
                 {
                     return a < b;
                 }
             });
        for (int i = 0; i < dictionary.size(); i++)
        {
            if (check(s, dictionary[i]))
                return dictionary[i];
        }
        return "";
    }
};