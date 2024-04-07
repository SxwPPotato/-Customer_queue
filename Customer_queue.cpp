#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <ctime>


void add_client(int duration, int count, int& client, int count_client ) {
      
    for (int i = 0; i < count_client; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(duration));

        client = client + count;
        std::cout << "Number of clients: " << client << std::endl;
        std::cout << "add_client" << std::endl;
    }
    
}

void reduce_client(int duration, int count, int& client, int count_client) {
    for (int i = 0; i < count_client; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        client = client + count;
        std::cout << "Number of clients: " << client << std::endl;
        std::cout << "reduce_client" << std::endl;
    }
}


int main()
{
    int client = 0;
    srand(time(0));
    int count_client = rand() % 11;
    
        std::thread t1(add_client, 1, 1, std::ref(client), count_client);
        std::thread t2(reduce_client, 2, -1, std::ref(client), count_client);

        t1.join();
        std::cout << "firth thread finish" << std::endl;
        t2.join();        
        std::cout << "second thread finish" << std::endl;

    return 0;
}