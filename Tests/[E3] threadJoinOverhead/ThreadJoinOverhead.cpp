#include <chrono>
#include <iostream>
#include <vector>

#include "mingw.thread.h"

// Function to perform a simple task in a thread
void simpleTask(int threadNum, std::chrono::duration<double>& threadDuration) {
    auto startTime = std::chrono::steady_clock::now();
    std::cout << "Thread " << threadNum << " is executing." << std::endl;
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * threadNum));
    auto endTime = std::chrono::steady_clock::now();
    threadDuration = endTime - startTime;
}

int main() {
    const int numThreads = 4;  // Number of threads

    std::vector<std::thread> threads;
    std::vector<std::chrono::duration<double>> threadDurations(numThreads);

    // Create threads and perform simple tasks
    for(int i = 0; i < numThreads; ++i) {
        threads.push_back(
            std::thread(simpleTask, i, std::ref(threadDurations[i])));
    }

    // Join threads sequentially and measure overhead
    auto joinStartTime = std::chrono::steady_clock::now();
    for(int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }
    auto joinEndTime = std::chrono::steady_clock::now();
    auto joinOverhead = joinEndTime - joinStartTime;

    // Print thread durations
    for(int i = 0; i < numThreads; ++i) {
        std::cout << "Thread " << i << " completed in "
                  << threadDurations[i].count() << " seconds." << std::endl;
    }

    // Calculate total overhead of joining threads
    std::cout << "Total overhead of joining threads: "
              << (joinOverhead.count() / 1000000) << " miliseconds." << std::endl;

    return 0;
}
