
class MinStack
{
public:
    /** initialize your data structure here. */
    vector<int> vec;
    vector<int> min_vec;
    MinStack()
    {
        min_vec.push_back(INT_MAX);
    }

    void push(int x)
    {
        vec.push_back(x);
        min_vec.push_back(min(min_vec.back(), x));
    }

    void pop()
    {
        vec.pop_back();
        min_vec.pop_back();
    }

    int top()
    {
        return vec.back();
    }

    int getMin()
    {
        return min_vec.back();
    }
};