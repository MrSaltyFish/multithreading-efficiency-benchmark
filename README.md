# Multithreading and Concurrency Benchmark Tests
This is a repository meant to store the different approaches used to benchmark the various metrics in different languages and compare their performance.

----------
Languages compared -

<br>Go, C++, Rust, Java, Python
<br>

----------
__Tests to be done -__

__EASY -__
<br>

_Basic Parallel Sum:_ Divide a large array into chunks and calculate the sum of each chunk concurrently using multiple threads.
<br>-> Compare the total execution time with a single-threaded approach.

_Thread Sleep and Wakeup:_ Measure the time it takes for a thread to sleep for a short duration and then wake up.
<br>-> This benchmark assesses the overhead of thread context switching and scheduling.

_Thread Join Overhead:_ Create multiple threads that perform simple tasks and then join them sequentially.
<br>-> Measure the time taken for each thread to complete and the total overhead of joining threads.

_Incrementing a Shared Counter:_ Have multiple threads increment a shared counter a large number of times concurrently.
<br>-> Compare the final value of the counter with the expected value to evaluate thread safety and synchronization overhead.

_Basic Producer-Consumer:_ Create a simple producer-consumer scenario where one thread produces data items and another thread consumes them.
<br>-> Measure the throughput and latency of data transfer between threads.

_Thread Creation vs. Task Execution:_ Compare the time it takes to create a thread with the time taken to execute a simple task in a thread.
<br>-> This benchmark helps assess the overhead of thread creation versus the actual work performed by threads.

_Simple Parallel Loop:_ Parallelize a basic loop that iterates over a large number of iterations using multiple threads.
<br>-> Measure the time taken to complete the loop in parallel versus sequentially.

_Thread Termination Overhead:_ Create threads that perform a simple task and then terminate immediately.
<br>-> Measure the time taken for a thread to terminate after completing its task.

----------

__MEDIUM -__
<br>

_Thread Creation Overhead:_ Measure the time it takes to create and start a large number of threads concurrently.
<br>-> This benchmark helps assess the overhead of thread creation in different languages.

_Basic Task Parallelism:_ Create a simple parallel task, such as calculating the sum of a large array or performing a repetitive computation.
<br>-> Compare the execution time when running the task concurrently using multiple threads.

_Thread Coordination:_ Implement a scenario where multiple threads need to coordinate their actions, such as updating a shared counter or performing a barrier synchronization.
<br>-> Measure the overhead and efficiency of thread coordination mechanisms like locks, mutexes, or semaphores.

_Parallelized I/O Operations:_ Write a program that performs concurrent I/O operations, such as reading from or writing to multiple files simultaneously.
<br>-> Measure the throughput and latency of I/O-bound tasks across languages.

_CPU-bound vs. I/O-bound Workloads:_ Design benchmarks that differentiate between CPU-bound and I/O-bound workloads.
<br>-> Compare the performance of languages in handling CPU-intensive tasks (e.g., mathematical calculations) versus I/O-bound tasks (e.g., file I/O or network operations) using multithreading.

_Thread Pool Performance:_ Implement a thread pool and submit tasks to be executed concurrently.
<br>-> Measure the overhead of task scheduling, thread creation, and resource management in maintaining the thread pool.

_Concurrency Control Overhead:_ Evaluate the overhead of synchronization primitives like locks or mutexes by measuring the time taken to acquire and release them in a multithreaded environment.

_Scalability Testing:_ Gradually increase the number of threads or tasks in a benchmark and observe how performance scales with increasing concurrency.
<br>-> Identify any bottlenecks or limitations in scalability across languages.

----------

__HARD -__
<br>

_Parallelized Matrix Multiplication:_ Implement matrix multiplication using multithreading in different languages and measure the execution time.
<br>-> This benchmark tests the efficiency of parallelization and thread management.

_Parallelized Sorting Algorithms:_ Implement parallel versions of sorting algorithms like quicksort or mergesort and compare their performance across languages.
<br>-> Sorting large datasets in parallel can highlight differences in multithreading capabilities.

_Producer-Consumer Problem:_ Create a scenario where multiple producer threads generate data items, which are consumed by consumer threads.
<br>-> Measure throughput and latency across languages to assess the efficiency of concurrent data processing.

_Parallel File Processing:_ Design a benchmark where multiple threads read and process data from files concurrently.
<br>-> Measure throughput and scalability across languages, considering factors like disk I/O and CPU utilization.

_Parallel HTTP Requests:_ Write a program to perform parallel HTTP requests to multiple endpoints simultaneously.
<br>-> Measure response times and throughput to evaluate the efficiency of multithreading in handling network-related tasks.

_Parallel Image Processing:_ Develop an image processing application that applies filters or transformations to images using multithreading.
<br>->Measure the time taken to process a batch of images concurrently in different languages.

_Monte Carlo Simulation:_ Implement a Monte Carlo simulation that calculates pi or simulates a financial model using multithreading.
<br>-> Compare the execution time and accuracy of results across languages.

_Concurrency with Data Structures:_ Test the performance of concurrent data structures like queues, maps, or sets in different languages under heavy concurrent access scenarios.
<br>-> Measure throughput, scalability, and synchronization overhead.

----------

