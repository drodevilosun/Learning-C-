#include <thread>
#include <vector>
#include <iostream>

class DataCollection {
public:
    void getStep(int num) 
    {
        std::cout << "Step is: " << step << std::endl;
        std::cout << "num is: " << num << std::endl;
    }
    // std::vector<std::thread> threadPool;
private:
    int step = 10;
};

void HandleThread(int num)
{
    std::cout << "This is thread: " << num << std::endl;
}

int main()
{
    int num_thread = 3;
    std::vector<std::thread> thread_pool;
    DataCollection obj;

    for (int i = 0; i < num_thread; i++)
    {
        /* Initialize thread with lambda function */
        // thread_pool.emplace_back([i] {
        //     if (i == 1)
        //         while (1)
        //         {
        //             std::cout << "This is thread: " << i << std::endl;
        //         }
        //     std::cout << "This is thread: " << i << std::endl;
        // });
        
        /* Initialize thread with available function */
        // thread_pool.emplace_back(HandleThread, i);
        
        /* Initialize thread with class member */
        thread_pool.emplace_back(&DataCollection::getStep, obj, i);
    }

    for (int i = 0; i < num_thread; i++)
        thread_pool[i].join();

    return 0;
}