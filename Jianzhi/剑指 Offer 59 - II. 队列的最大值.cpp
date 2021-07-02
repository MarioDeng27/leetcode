/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 20:52:45
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-02 20:52:56
 */
class MaxQueue {
public:
    queue<int> q;
    deque<int> fall_queue;
    MaxQueue()
    {
        
    }

    int max_value() 
    {
        if(fall_queue.empty())
            return -1;
        return fall_queue.front();
    }

    void push_back(int value) 
    {
        q.push(value);
        while(!fall_queue.empty() && fall_queue.back() < value)
        {
            fall_queue.pop_back();
        }
        fall_queue.push_back(value);
    }

    int pop_front() 
    {
        if(q.empty())
            return -1;
        int res = q.front();
        if(res == fall_queue.front())
            fall_queue.pop_front();
        q.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */