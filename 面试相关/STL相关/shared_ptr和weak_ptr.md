# shared_ptr和weak_ptr

什么时候要用到weak_ptr？

weak_ptr的特点

shared_ptr指向的对象什么时候才调用析构函数

weak_ptr如何感知到所引用的对象以及不存在了？通过expired，若true则表示已被释放，若false则表示还存在，还可以继续使用，它本身要通过shared_ptr来初始化，并不增加引用计数。获得对应的shared_ptr要用lock()



核心源码实现：https://blog.csdn.net/dong_beijing/article/details/79504591 、 https://blog.csdn.net/ithiker/article/details/51532484