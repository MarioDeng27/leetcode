/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-14 14:30:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-14 14:32:43
 */
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t)
{
    unordered_map<char, int> need, window;
    for (char c : t)
        need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size())
    {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

            /*** debug 输出的位置 ***/
            printf("window: [%d, %d)\n", left, right);
        /********************/

        // 判断左侧窗口是否要收缩
        while (window needs shrink)
        {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
/*

现在开始套模板，只需要思考以下四个问题：
1、当移动 right 扩大窗口，即加入字符时，应该更新哪些数据？ 
2、什么条件下，窗口应该暂停扩大，开始移动 left 缩小窗口？ 
3、当移动 left 缩小窗口，即移出字符时，应该更新哪些数据？ 
4、我们要的结果应该在扩大窗口时还是缩小窗口时进行更新？
如果一个字符进入窗口，应该增加 window 计数器；如果一个字符将移出窗口的时候，应该减少 window 计数器；当 valid 满足 need 时应该收缩窗口；应该在收缩窗口的时候更新最终结果。


*/