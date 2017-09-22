#include <iostream>
#include <thread>
#include "util/PropertiesUtil.h"
#include "gc/GC.h"

using namespace std;

void thread_function() {
    std::cout << "thread function\n";
}

int main() {
    GC gc = GC();
    gc.init();
//    thread t(&thread_function);   // t starts running
//    cout << "main thread\n";
//    t.join();   // main thread waits for the thread t to finish
    return 0;
}