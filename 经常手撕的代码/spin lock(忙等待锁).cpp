/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 11:47:02
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 14:17:23
 */

//模拟在OS中实现自旋锁/忙等待锁的伪代码

/*
这是最简单的一种锁，一直自旋（循环等待），利用CPU周期，直到锁可用。在单处理器上，需要抢占式的调度器（即线程通过不正常的方式被中断，它通过时钟中断一个线程，运行其他线程，它的时间片没了），不然自旋锁无法在单CPU上使用，因为一个自旋的线程永远不会放弃CPU（无限循环，flag 的值永远不能被其他线程改变）
*/

//CPU 体系结构提供的特殊 原子操作指令 ——测试和置位（Test-And-Set）指令，如果用C代码表示，形式如下。注意，该操作是原子操作
int TestAndSet(int *old_ptr, int new_value)
{
    int old = *old_ptr;
    *old_ptr = new_value;
    return old;
}

typedef struct lock_t
{
    int flag;
} lock_t;

void init(lock_t *lck)
{
    lck->flag = 1;
}

void lock(lock_t *lck)
{
    //若flag == 1则会进入忙等待状态，while不停的循环直到flag变为0
    while (TestAndSet(&lck->flag, 1) == 1)
        ;
    //do nothing
}

void unlock(lock_t *lck)
{
    lck->flag = 0;
}