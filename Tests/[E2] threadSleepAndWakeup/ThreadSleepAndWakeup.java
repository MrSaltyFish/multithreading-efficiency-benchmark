public class ThreadSleepAndWakeup {

    public static void main(String[] args) {
        final long sleepDurationMillis = 10; // Sleep duration in milliseconds

        long startTime = System.nanoTime();

        // Create a thread to sleep
        Thread sleepThread = new Thread(() -> {
            try {
                Thread.sleep(sleepDurationMillis);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        sleepThread.start();

        // Wait for the thread to finish sleeping
        try {
            sleepThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        long endTime = System.nanoTime();

        long durationMillis = (endTime - startTime) / 1_000_000; // Convert nanoseconds to milliseconds

        System.out.println("Java Thread Sleep and Wakeup Duration: " + durationMillis + " milliseconds");
    }
}
