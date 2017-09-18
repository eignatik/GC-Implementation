#include <iostream>
#include <thread>
#include "util/PropertiesUtil.h"

using namespace std;

void thread_function() {
    std::cout << "thread function\n";
}

int main() {
    string edenSize = string("eden.size");
    string survivorSize = string("survivor.size");
    string oldSize = string("old.size");
    PropertiesUtil util = PropertiesUtil();
    cout << util.getProperty(edenSize);
    cout << util.getProperty(survivorSize);
    cout << util.getProperty(oldSize);

//    thread t(&thread_function);   // t starts running
//    cout << "main thread\n";
//    t.join();   // main thread waits for the thread t to finish
    return 0;
}