import threading
import time

# Function to calculate the sum of elements in a chunk of the array
def calculate_chunk_sum(arr, start, end):
    return sum(arr[start:end])

# Function for parallel summation of chunks
def parallel_sum(arr, num_threads):
    chunk_size = len(arr) // num_threads
    threads = []
    partial_sums = []

    start_time = time.time()

    # Create threads to calculate partial sums for each chunk
    for i in range(num_threads):
        start = i * chunk_size
        end = start + chunk_size if i < num_threads - 1 else len(arr)
        thread = threading.Thread(target=lambda: partial_sums.append(calculate_chunk_sum(arr, start, end)))
        threads.append(thread)
        thread.start()

    # Join threads
    for thread in threads:
        thread.join()

    # Calculate total sum
    total_sum = sum(partial_sums)

    end_time = time.time()
    duration = (end_time - start_time) * 1000  # Convert to milliseconds

    print("Parallel Sum:", total_sum)
    print("Parallel Execution Time:", duration, "milliseconds")

# Function for single-threaded summation
def single_threaded_sum(arr):
    start_time = time.time()

    total_sum = sum(arr)

    end_time = time.time()
    duration = (end_time - start_time) * 1000  # Convert to milliseconds

    print("Single-Threaded Sum:", total_sum)
    print("Single-Threaded Execution Time:", duration, "milliseconds")

if __name__ == "__main__":
    array_size = 1000000
    num_threads = 4

    # Create a large array
    arr = list(range(1, array_size + 1))

    # Perform parallel summation
    parallel_sum(arr, num_threads)

    # Perform single-threaded summation for comparison
    single_threaded_sum(arr)
