#include <chrono>
#include <iostream>
#include <vector>
#define _WIN32_WINNT 0x0501
#include "mingw.thread.h"

// Function to calculate the sum of elements in a chunk of the array
int calculateChunkSum(const std::vector<int>& arr, int start, int end) {
    int sum = 0;
    for(int i = start; i < end; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function for parallel summation of chunks
void parallelSum(const std::vector<int>& arr, int numThreads) {
    int chunkSize = arr.size() / numThreads;
    std::vector<std::thread> threads(numThreads);
    std::vector<int> partialSums(numThreads);

    auto startTime = std::chrono::steady_clock::now();

    // Create threads to calculate partial sums for each chunk
    for(int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? arr.size() : start + chunkSize;
        threads[i] = std::thread([&, start, end, i]() {
            partialSums[i] = calculateChunkSum(arr, start, end);
        });
    }

    // Join threads
    for(auto& thread : threads) {
        thread.join();
    }

    // Calculate total sum
    int totalSum = 0;
    for(int sum : partialSums) {
        totalSum += sum;
    }

    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                        endTime - startTime)
                        .count();

    std::cout << "Parallel Sum: " << totalSum << std::endl;
    std::cout << "Parallel Execution Time: " << duration << " milliseconds"
              << std::endl;
}

// Function for single-threaded summation
void singleThreadedSum(const std::vector<int>& arr) {
    auto startTime = std::chrono::steady_clock::now();

    int totalSum = 0;
    for(int num : arr) {
        totalSum += num;
    }

    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                        endTime - startTime)
                        .count();

    std::cout << "Single-Threaded Sum: " << totalSum << std::endl;
    std::cout << "Single-Threaded Execution Time: " << duration
              << " milliseconds" << std::endl;
}

int main() {
    const int arraySize = 1000000;
    const int numThreads = 4;
    std::cout << "Basic Parallel Sum in C++ ->\n";
    // Create a large array
    std::vector<int> arr(arraySize);
    for(int i = 0; i < arraySize; ++i) {
        arr[i] = i + 1;  // Populate with sequential numbers
    }

    // Perform parallel summation
    parallelSum(arr, numThreads);

    // Perform single-threaded summation for comparison
    singleThreadedSum(arr);

    return 0;
}
