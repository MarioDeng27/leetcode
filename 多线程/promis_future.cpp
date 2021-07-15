/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-13 19:06:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-13 19:21:05
 */
#include <chrono>
#include <cstdlib>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

void thread_set_promise(std::promise<int> &promiseObj)
{
    std::cout << "In a thread, making data...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    promiseObj.set_value(35);
    std::cout << "Finished\n";
}

int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread t(&thread_set_promise, std::ref(promiseObj));
    std::cout << futureObj.get() << std::endl;
    t.join();

    system("pause");
    return 0;
}