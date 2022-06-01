class Solution
{
public:
    bool canPlaceFlowers(vector<int> flowerbed, int n)
    {
        int left = -2;
        int right = flowerbed.size() + 1;
        int res = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i])
            {
                res += ((i - left) - 2) / 2;
                left = i;
                if (res >= n)
                    return true;
            }
        }
        res += ((right - left) - 2) / 2;
        return res >= n;
    }
};