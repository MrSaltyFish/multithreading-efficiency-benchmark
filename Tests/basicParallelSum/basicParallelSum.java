import java.util.ArrayList;
import java.util.List;

public class basicParallelSum {
    // Function to calculate the sum of elements in a chunk of the array
    public static int calculateChunkSum(List<Integer> arr, int start, int end) {
        int sum = 0;
        for (int i = start; i < end; ++i) {
            sum += arr.get(i);
        }
        return sum;
    }

    // Function for parallel summation of chunks
    public static void parallelSum(List<Integer> arr, int numThreads) throws InterruptedException {
        int chunkSize = arr.size() / numThreads;
        List<Thread> threads = new ArrayList<>(numThreads);
        List<Integer> partialSums = new ArrayList<>(numThreads);

        long startTime = System.currentTimeMillis();

        // Create threads to calculate partial sums for each chunk
        for (int i = 0; i < numThreads; ++i) {
            int start = i * chunkSize;
            int end = (i == numThreads - 1) ? arr.size() : start + chunkSize;
            final int finalStart = start;
            final int finalEnd = end;
            Thread thread = new Thread(() -> {
                int sum = calculateChunkSum(arr, finalStart, finalEnd);
                synchronized (partialSums) {
                    partialSums.add(sum);
                }
            });
            threads.add(thread);
            thread.start();
        }

        // Join threads
        for (Thread thread : threads) {
            thread.join();
        }

        // Calculate total sum
        int totalSum = 0;
        for (int sum : partialSums) {
            totalSum += sum;
        }

        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime;

        System.out.println("Parallel Sum: " + totalSum);
        System.out.println("Parallel Execution Time: " + duration + " milliseconds");
    }

    // Function for single-threaded summation
    public static void singleThreadedSum(List<Integer> arr) {
        long startTime = System.currentTimeMillis();

        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        long endTime = System.currentTimeMillis();
        long duration = endTime - startTime;

        System.out.println("Single-Threaded Sum: " + totalSum);
        System.out.println("Single-Threaded Execution Time: " + duration + " milliseconds");
    }

    public static void main(String[] args) throws InterruptedException {
        final int arraySize = 1000000;
        final int numThreads = 4;
        System.out.println("Basic Parallel Sum in Java ->");
        // Create a large array
        List<Integer> arr = new ArrayList<>(arraySize);
        for (int i = 0; i < arraySize; ++i) {
            arr.add(i + 1); // Populate with sequential numbers
        }

        // Perform parallel summation
        parallelSum(arr, numThreads);

        // Perform single-threaded summation for comparison
        singleThreadedSum(arr);
    }
}
