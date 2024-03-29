#include <chrono>
#include <iostream>

#include "mingw.thread.h"

int main() {
    const long long sleepDurationMillis = 10;  // Sleep duration in milliseconds

    auto startTime = std::chrono::high_resolution_clock::now();

    // Create a thread to sleep
    std::thread sleepThread([sleepDurationMillis]() {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(sleepDurationMillis));
    });

    // Wait for the thread to finish sleeping
    sleepThread.join();

    auto endTime = std::chrono::high_resolution_clock::now();

    auto durationMillis = std::chrono::duration_cast<std::chrono::milliseconds>(
                              endTime - startTime)
                              .count();

    std::cout << "C++ Thread Sleep and Wakeup Duration: " << durationMillis
              << " milliseconds" << std::endl;

    return 0;
}
