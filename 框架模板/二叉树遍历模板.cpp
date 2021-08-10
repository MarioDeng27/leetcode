/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-10 17:47:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-10 17:49:26
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-10 17:47:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-10 17:47:36
 */
void traverse(TreeNode root)
{
    // 前序遍历
    traverse(root.left);
    // 中序遍历
    traverse(root.right);
    // 后序遍历
}

/* labuladong 告诉你，遇到任何递归型的问题，无非就是灵魂三问：

    1、这个函数是干嘛的？

    2、这个函数参数中的变量是什么的是什么？

    3、得到函数的递归结果，你应该干什么？

    呵呵，看到这灵魂三问，你有没有感觉到熟悉？本号的动态规划系列文章，篇篇都在说的动态规划套路，首先要明确的是什么？是不是要明确「定义」「状态」「选择」，这仨不就是上面的灵魂三问吗？ */