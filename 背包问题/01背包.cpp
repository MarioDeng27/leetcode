/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-22 15:45:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-22 16:37:18
 */
/**
     * 解决背包问题的递归函数（自顶向下）
     * 缺点：有些情况重复计算，导致效率低下
     * @param w        物品的重量数组
     * @param v        物品的价值数组
     * @param index    当前待选择的物品索引
     * @param capacity 当前背包有效容量
     * @return 最大价值
     */
int solveKS(vector<int> wn, vector<int> vn, int index, int capacity)
{
    if (index < 0 || capacity <= 0)
    {
        return 0;
    }
    //将第index个物品不放入背包中能获得最大价值的钱
    int res = solveKS(wn, vn, index - 1, capacity);
    //当背包剩余空间大于当前物品的体积，那么就可以考虑将第index个物品放入背包中
    if (capacity - wn[index] >= 0)
        res = max(res, vn[index] + solveKS(wn, vn, index - 1, capacity - wn[index]));
    return res;
}
int knapSack(vector<int> wn, vector<int> vn, int C)
{
    int size = wn.size();
    return solveKS(wn, vn, size - 1, C);
}

//带memory的递归

/**
     * 解决背包问题的递归函数
     *
     * @param w        物品的重量数组
     * @param v        物品的价值数组
     * @param index    当前待选择的物品索引
     * @param capacity 当前背包有效容量
     * @return 最大价值
     */
//第一个int表示第i个物品，第二个int表示所剩空间大小
vector<vector<int>> memory;
int solveKS(vector<int> wn, vector<int> vn, int index, int capacity)
{
    if (index < 0 || capacity <= 0)
    {
        return 0;
    }
    if (memory[index][capacity] != -1)
        return memory[index][capacity];
    //将第index个物品不放入背包中能获得最大价值的钱
    int res = solveKS(wn, vn, index - 1, capacity);
    //当背包剩余空间大于当前物品的体积，那么就可以考虑将第index个物品放入背包中
    if (capacity - wn[index] >= 0)
        res = max(res, vn[index] + solveKS(wn, vn, index - 1, capacity - wn[index]));
    memory[index][capacity] = res;
    return res;
}
int knapSack(vector<int> wn, vector<int> vn, int C)
{
    int size = wn.size();
    memory = vector<vector<int>>(size + 1, vector<int>(C + 1, -1));
    return solveKS(wn, vn, size - 1, C);
}
//二维DP解决01问题
int knapSack(vector<int> wn, vector<int> vn, int C)
{
    int size = wn.size();
    //dp[i][j] 表示[1,i]个物品中选择若干个（当然可以包含i和不包含i），在容量为j的情况下获得的最大价值
    //初始值dp[0][j]表示没有一个物品，则总价值肯定为0，dp[i][0]容量为0，总价值必定为0
    vector<vector<int>> dp(size + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= size; i++)
    {
        //第i个物品，在数组里的下标是i-1
        int v = vn[i - 1];
        int w = wn[i - 1];
        for (int j = 1; j <= C; j++)
        {
            if (j >= w)
            {
                dp[i][j] = max(dp[i - 1][j], v + dp[i - 1][j - w]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][C];
}

//一维DP解决01问题
int knapSack(vector<int> wn, vector<int> vn, int C)
{
    int size = wn.size();
    //dp[j]表示当前容量为j的时候可以获得的最大价值
    vector<int> dp(C + 1, 0);
    for (int i = 1; i <= size; i++)
    {
        //第i个物品，在数组里的下标是i-1
        int v = vn[i - 1];
        int w = wn[i - 1];
        //注意j从C开始从后往前遍历，这样它所依赖前一个状态的值还没更新，若反过来则状态值已更新
        for (int j = C; j >= w; j--)
        {
            dp[j] = max(dp[j], v + dp[j - w]);
        }
    }
    return dp[C];
}