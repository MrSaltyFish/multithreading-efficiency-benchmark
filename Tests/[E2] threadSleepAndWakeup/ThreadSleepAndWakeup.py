import threading
import time

def sleep_thread(sleep_duration):
    time.sleep(sleep_duration)

if __name__ == "__main__":
    sleep_duration_secs = 0.01  # Sleep duration in seconds

    start_time = time.time()

    # Create a thread to sleep
    sleep_thread = threading.Thread(target=sleep_thread, args=(sleep_duration_secs,))
    sleep_thread.start()

    # Wait for the thread to finish sleeping
    sleep_thread.join()

    end_time = time.time()

    duration_secs = end_time - start_time

    print("Thread Sleep and Wakeup Duration: {:.3f} seconds".format(duration_secs))
