/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 11:59:58
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 14:15:28
 */
//CPU 体系结构提供的特殊 原子操作指令 ——测试和置位（Test-And-Set）指令，如果用C代码表示，形式如下。注意，该操作是原子操作
int TestAndSet(int *old_ptr, int new_value)
{
    int old = *old_ptr;
    *old_ptr = new_value;
    return old;
}

typedef struct queue_t
{
    /* data */
} queue_t;
void queue_init(queue_t *q)
{
    /*初始化等待队列*/
}

typedef struct lock_t
{
    int flag;
    queue_t *q;
} lock_t;

void init(lock_t *lck)
{
    lck->flag = 1;
    queue_init(lck->q);
}

void lock(lock_t *lck)
{
    while (TestAndSet(&lck->flag, 1) == 1)
    {
        /*
        保存现在运行线程的TCB
        将现在运行线程的TCB插入到等待队列
        设置该线程为等待状态
        调度程序（OS选择就绪队列中其他线程执行）
        */
    }
}

void unlock(lock_t *lck)
{
    if (lck->q != nullptr)
    {
        /*
        移除等待队列的队头元素(queue_pop)
        将该线程的TCB插入到就绪队列
        设置该线程为就绪状态（等待OS的选中，然后被执行）
        */
    }
    lck->flag = 0;
}
