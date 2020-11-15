/*
    1. 首先将input通过'/n'分割成若干个string组成的数组
    注意'/n'和'/t'是一个字符
    2. 遍历整个数组vec,通过判断有多少个'/t'来判断当前目录或文件夹在第几层,如果是在根目录里也就是没有/t则相当于在0层
    有一个/t则在第1层
    一开始肯定都不符合level < st.size()这个条件不会进入while循环
    所以都会直接计算len值,并且将其压入栈中
    当前要计算的目录或者文件,它的前面的层数等于栈中元素个数-1
    比如目前栈中元素个数是3,而来了一个层数是1层的文件夹或者目录,它必须出栈两个元素,然后它的栈顶就是当前文件夹或者目录的前序
    目录
    3. len的计算:相当于当前目录或者文件的前序也就是当前栈的栈顶的值+当前str的长度-层数(/t的个数)+1(代表还要加一个\字符)
    4. 每当判断出当前str是个文件时,就维护res值,也就是当前循环中的len比较下长度
*/

class Solution
{
public:
    vector<string> strsplit(string input)
    {
        string::size_type pos = 0;
        string::size_type start = 0;
        vector<string> res;
        while ((pos = input.find_first_of('\n', pos)) != string::npos)
        {
            res.push_back(input.substr(start, pos - start));
            pos += 1;
            start = pos;
        }
        res.push_back(input.substr(start, pos - start));
        return res;
    }
    int lengthLongestPath(string input)
    {
        vector<string> vec = strsplit(input);
        stack<int> st;
        int res = 0;
        for (auto str : vec)
        {
            string::size_type level = str.find_last_of('\t') + 1;
            while (level < st.size())
                st.pop();
            int len;
            if (!st.empty())
                len = st.top() + str.size() - level + 1;
            else
                len = str.size() - level;
            st.push(len);
            if (str.find('.', 0) != string::npos)
            {
                res = max(res, len);
            }
        }
        return res;
    }
};