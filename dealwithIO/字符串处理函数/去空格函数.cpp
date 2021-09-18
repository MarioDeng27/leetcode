/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-18 18:19:58
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-18 18:19:59
 */
string trim(string &s)
{
    const string &space = " /f/n/t/r/v";
    string r = s.erase(s.find_last_not_of(space) + 1);
    return r.erase(0, r.find_first_not_of(space));
}

string ltrim(string &s)
{
    const string &space = " /f/n/t/r/v";
    return s.erase(0, s.find_first_not_of(space));
}

string rtrim(string &s)
{
    const string &space = " /f/n/t/r/v";
    return s.erase(s.find_last_not_of(space) + 1);
}