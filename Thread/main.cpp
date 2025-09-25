#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <memory>

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

class Worker
{
public:
    Worker(std::string name) : name_(std::move(name)) {}

    void doWork(int iteration)
    {
       for(int i{}; i<iteration; ++i)
       {
          std::clog<<name_<<" working "<<i<<std::endl;
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
       }
    }

private:
    std::string name_;
};

struct Task
{
    void operator() (int taskNo)
    {
       std::clog<<"Task #"<<taskNo<<" running.."<<std::endl;
       std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
};

int main(int argc, char *argv[])
{
    // 1. basic thread ---------------------------
    std::thread t1(helloThread);
    t1.join();
    //--------------------------------------------

    // 2. thread with argument --------------------
    std::thread t2(printNumber, 1, 5);
    t2.join();
    //---------------------------------------------

    // 3. thread with ref value -----------------------------------------
    int counter{};
    std::clog << "counter before thread start : " << counter << std::endl;
    std::thread t3(incrementValue, std::ref(counter));
    t3.join();
    std::clog << "counter after thread finish : " << counter << std::endl;
    //--------------------------------------------------------------------

    // 4. multiple thread in a loop -----------------------------------
    std::vector<std::thread> threadContainer;

    for (size_t i{}; i < 3; ++i)
    {
        threadContainer.emplace_back([i]()
                                     {
                                         std::clog << "thread #" << i << " working.." << std::endl;
                                         std::this_thread::sleep_for(std::chrono::milliseconds(200)); });
    }

    for (auto &t : threadContainer)
    {
        t.join();
    }
    //-------------------------------------------------------------------

    // 5. detach thread ---------------------------------
    std::thread t4([]()
                   {
                       std::clog << "Detaching thread..." << std::endl;
                       std::this_thread::sleep_for(std::chrono::seconds(1));
                       std::clog << "Detach done." << std::endl; });
    t4.detach();
    // give time detach thread to finish
    std::this_thread::sleep_for(std::chrono::seconds(2)); // main thread
    //--------------------------------------------------

    //6. member function ptr -------------------------------
    auto worker = std::make_shared<Worker>("Thread-A");
    std::thread t5(&Worker::doWork, worker, 4);
    t5.join();
    //-------------------------------------------------------

    //7. function object or functor ------------------------------------
    std::thread t6(Task{}, 8);
    t6.join();
    //--------------------------------------------------------

    std::clog << "main thread exit." << std::endl;

    return 0;
}