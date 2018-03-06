#include <pthread.h>
#include <cstdio>
#include <thread>

void* thread_func(void *index)
{
    printf("this is the %dth thread!\n", *((int*)index));
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

void startJoinableThreads(int threadNum)
{
    int ret = 0;
    pthread_t thread;
    
    while(threadNum)
    {
        // bug: 
        if(0 != (ret=pthread_create(&thread, nullptr, thread_func, &threadNum)))
        {
            printf("%dth detached thread creation failure: %d!\n", threadNum, ret);
        }
        threadNum--;
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

void startDetachedThreads(int threadNum)
{
    int ret = 0;
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    while(threadNum)
    {
        // bug: pass address of threadNum, rather than value!
        if(0 != (ret=pthread_create(&thread, &attr, thread_func, &threadNum)))
        {
            printf("%dth detached thread creation failure: %d!\n", threadNum, ret);
        }
        threadNum--;
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

int main(int argc, char *argv[])
{
    //startJoinableThreads(5);
    startDetachedThreads(5);
    return 0;
}


