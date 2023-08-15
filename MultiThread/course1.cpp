#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // 相当于windows的 windows.h ，提供了很多系统API
#include <string.h>
#include <pthread.h>
#include <iostream>

void* threadFunction(void*)
{
    std::cout << "Thread is running!" << std::endl;

    for (int i = 0; i < 9; ++i)
    {
        printf("child == i: = %d\n", i);
    }

    return nullptr;
}

int main(int argc, char *argv[])
{
    pthread_t threadId; // pthread_t ---- unsigned long int 

    // 线程创建成功返回0 ，否则是其他错误报告
    // 线程创建返回的ID   线程的属性（一般为空） 函数指针  作为实参传递给函数指针
    int result = pthread_create(&threadId, NULL, &threadFunction, NULL); 

    if (result != 0)
    {
        std::cerr << "Failed to create thread." << std::endl;
        return 1;
    }
    printf("子线程创建成功！\n");
    std::cout << "线程ID为: " << threadId << std::endl;

    // 主线程执行阶段
    printf("我是主线程！\n");
    std::cout << "主线程的线程ID为: " << pthread_self() << std::endl;

    for (size_t i = 0; i < 3; i++)
    {
        printf("i: %ld\n", i);
    }
    
    // std::this_thread::sleep_for(std::chrono::milliseconds(50));//睡眠50毫秒
    // sleep(1);
    // 利用线程退出函数，想要让主线程进行退出，但是不影响子线程的运行
    // 主线程退出一般返回NULL，子线程退出的时候可以将参数进行返回给主线程
    pthread_exit(NULL);
    return 0;
}
