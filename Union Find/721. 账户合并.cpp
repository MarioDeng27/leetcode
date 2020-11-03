/*
    纯粹的暴力算法:简单的合并

*/
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<pair<string, set<string>>> vaccounts;
        for (auto vec : accounts)
        {
            set<string> s(vec.begin() + 1, vec.end());
            pair<string, set<string>> p = {vec[0], s};
            vaccounts.push_back(p);
        }
        for (int i = 0; i < vaccounts.size(); i++)
        {
            if (vaccounts[i].first == "No")
                continue;
            pair<string, set<string>> &p_acc = vaccounts[i];
            for (int j = i + 1; j < vaccounts.size(); j++)
            {
                pair<string, set<string>> &q_acc = vaccounts[j];
                if (p_acc.first != q_acc.first)
                    continue;
                for (auto q : q_acc.second)
                {
                    if (p_acc.second.find(q) != p_acc.second.end())
                    {
                        p_acc.second.insert(q_acc.second.begin(), q_acc.second.end());
                        q_acc.first = "No";
                        i = -1;
                        break;
                    }
                }
            }
        }
        vector<vector<string>> res;
        for (int i = 0; i < vaccounts.size(); i++)
        {
            if (vaccounts[i].first != "No")
            {
                vector<string> temp;
                temp.push_back(vaccounts[i].first);
                for (auto s : vaccounts[i].second)
                    temp.push_back(s);
                res.push_back(temp);
            }
        }
        return res;
    }
};