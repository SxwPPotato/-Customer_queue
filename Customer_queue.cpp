#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <ctime>
#include <atomic>


std::atomic_flag AtomicFlag = ATOMIC_FLAG_INIT;
std::atomic<int>  atomic_client = 0;
std::atomic<int>  atomic_count = rand() % 11;



void add_client(int duration, int count) {
      
    for (int i = 0; i < atomic_count; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(duration));

        atomic_client = atomic_client + count;
        std::cout << "Number of clients: " << atomic_client << std::endl;
        std::cout << "add_client" << std::endl;
    }
    
}

void reduce_client(int duration, int count) {
    for (int i = 0; i < atomic_count; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        atomic_client = atomic_client + count;
        std::cout << "Number of clients: " << atomic_client << std::endl;
        std::cout << "reduce_client" << std::endl;
    }
}


int main()
{
    std::cout << " Atomicbool is Lock free: " << atomic_client.is_lock_free() << std::endl;
    srand(time(0));
    std::cout << atomic_count << std::endl;
  
        std::thread t1(add_client, 1, 1);
        std::thread t2(reduce_client, 2, -1);

        t1.join();
        std::cout << "firth thread finish" << std::endl;
        t2.join();        
        std::cout << "second thread finish" << std::endl;

    return 0;
}