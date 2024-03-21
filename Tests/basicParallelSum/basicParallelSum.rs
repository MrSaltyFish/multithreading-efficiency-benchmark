use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Instant;

// Function to calculate the sum of elements in a chunk of the array
fn calculate_chunk_sum(arr: &[i32], start: usize, end: usize) -> i32 {
    let mut sum = 0;
    for i in start..end {
        sum += arr[i];
    }
    sum
}

// Function for parallel summation of chunks
fn parallel_sum(arr: &[i32], num_threads: usize) {
    let chunk_size = arr.len() / num_threads;
    let mut handles = vec![];
    let partial_sums = Arc::new(Mutex::new(vec![0; num_threads]));

    let start_time = Instant::now();

    // Create threads to calculate partial sums for each chunk
    for i in 0..num_threads {
        let partial_sums = Arc::clone(&partial_sums);
        let arr = arr.to_owned();
        let handle = thread::spawn(move || {
            let start = i * chunk_size;
            let end = if i == num_threads - 1 {
                arr.len()
            } else {
                start + chunk_size
            };
            let sum = calculate_chunk_sum(&arr, start, end);
            let mut partial_sums = partial_sums.lock().unwrap();
            partial_sums[i] = sum;
        });
        handles.push(handle);
    }

    // Join threads
    for handle in handles {
        handle.join().unwrap();
    }

    // Calculate total sum
    let total_sum: i32 = partial_sums.lock().unwrap().iter().sum();

    let duration = start_time.elapsed().as_micros();

    println!("Parallel Sum: {}", total_sum);
    println!("Parallel Execution Time: {} microseconds", duration);
}

// Function for single-threaded summation
fn single_threaded_sum(arr: &[i32]) {
    let start_time = Instant::now();

    let total_sum: i32 = arr.iter().sum();

    let duration = start_time.elapsed().as_micros();

    println!("Single-Threaded Sum: {}", total_sum);
    println!("Single-Threaded Execution Time: {} microseconds", duration);
}

fn main() {
    let array_size = 1000000;
    let num_threads = 4;

    // Create a large array
    let arr: Vec<i32> = (1..=array_size as i32).collect();

    // Perform parallel summation
    parallel_sum(&arr, num_threads);

    // Perform single-threaded summation for comparison
    single_threaded_sum(&arr);
}
