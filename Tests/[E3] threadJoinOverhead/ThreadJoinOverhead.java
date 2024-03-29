import java.util.ArrayList;
import java.util.List;

public class ThreadJoinOverhead {
    static class SimpleTask implements Runnable {
        private int threadNum;
        private long startTime;

        public SimpleTask(int threadNum) {
            this.threadNum = threadNum;
        }

        @Override
        public void run() {
            startTime = System.nanoTime();
            System.out.println("Thread " + threadNum + " is executing.");
            // Simulate some work
            try {
                Thread.sleep(100 * threadNum);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            long endTime = System.nanoTime();
            long duration = (endTime - startTime) / 1_000_000; // Convert nanoseconds to milliseconds
            System.out.println("Thread " + threadNum + " completed in " + duration + " milliseconds.");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        final int numThreads = 4; // Number of threads

        List<Thread> threads = new ArrayList<>();

        // Create threads and perform simple tasks
        for (int i = 0; i < numThreads; i++) {
            Thread thread = new Thread(new SimpleTask(i));
            thread.start();
            threads.add(thread);
        }

        // Join threads sequentially and measure overhead
        long joinStartTime = System.nanoTime();
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        long joinEndTime = System.nanoTime();
        long joinOverhead = (joinEndTime - joinStartTime) / 1_000_000; // Convert nanoseconds to milliseconds
        System.out.println("Total overhead of joining threads: " + joinOverhead + " milliseconds.");
    }
}
