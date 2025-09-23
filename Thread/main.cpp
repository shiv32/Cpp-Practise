#include <iostream>
#include <thread>
#include <chrono>

// 1. function with no paramter
void helloThread()
{
    std::clog << "Hello thread." << std::endl;
}

// 2. function with parameter
void printNumber(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        std::clog << "value : " << i << " ";
    }

    std::clog << std::endl;
}

// 3. function with ref parameter
void incrementValue(int &value)
{
    for (int i = 0; i < 5; ++i)
    {
        ++value;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, char *argv[])
{
    // 1. basic thread
    std::thread t1(helloThread);
    t1.join();

    // 2. thread with argument
    std::thread t2(printNumber, 1, 5);
    t2.join();

    // 3. thread with ref value
    int counter{};
    std::clog << "counter before thread start : " << counter << std::endl;
    std::thread t3(incrementValue, std::ref(counter));
    t3.join();
    std::clog << "counter after thread finish : " << counter << std::endl;

    return 0;
}