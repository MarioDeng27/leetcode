/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\C++必会的几个手撕代码\smartPtr.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-20 22:08:39
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-20 22:24:21
 */
#include <iostream>

using namespace std;

template <typename T>
class SmartPtr
{
private:
    T *_ptr;
    size_t *_cnt;

public:
    SmartPtr(T *ptr == nullptr) : _ptr(ptr)
    {
        if (_ptr)
        {
            _cnt = new size_t(1);
        }
        else
        {
            _cnt = new size_t(0);
        }
    }
    ~SmartPtr()
    {
        (*this->_cnt)--;
        if (*this->_cnt == 0)
        {
            delete _ptr;
            delete _cnt;
        }
    }
    SmartPtr(const SmartPtr &ptr)
    {
        if (this != &ptr)
        {
            this->_ptr = ptr->_ptr;
            this->_cnt = ptr->_cnt;
            (*this->_cnt)++;
        }
    }
    SmartPtr &operator=(const SmartPtr &ptr)
    {
        if (this->_ptr == ptr._ptr)
            return *this;
        if (this->_ptr)
        {
            (*this->_cnt)--;
            if ((*this->_cnt) == 0)
            {
                delete this->_ptr;
                delete this->_cnt;
            }
        }
        this->_ptr = ptr->_ptr;
        this->_cnt = ptr->_cnt;
        (*this->_cnt)++;
        return *this;
    }
    T &operator*()
    {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);
    }
    T *operator->()
    {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }
    size_t use_count()
    {
        return *this->_cnt;
    }
}