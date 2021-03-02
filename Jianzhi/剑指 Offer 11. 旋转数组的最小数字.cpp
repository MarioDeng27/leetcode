/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 20:16:23
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 20:16:44
 */
class Solution
{
public:
    int getInOder(vector<int> numbers, int l, int r)
    {
        int min = numbers[l];
        for (int i = l; i <= r; i++)
        {
            if (min > numbers[i])
                min = numbers[i];
        }
        return min;
    }
    int minArray(vector<int> &numbers)
    {
        if (numbers.size() == 0)
        {
            return -1;
        }
        int l = 0;
        int r = numbers.size() - 1;

        while (numbers[l] >= numbers[r])
        {
            if (r - l == 1)
                return numbers[r];
            int m = (l + r) / 2;
            if (numbers[l] == numbers[r] && numbers[m] == numbers[l])
                return getInOder(numbers, l, r);
            if (numbers[l] <= numbers[m])
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return numbers[0];
    }
};