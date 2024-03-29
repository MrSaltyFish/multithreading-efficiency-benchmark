package main

import (
	"fmt"
	"sync"
	"time"
)

// Function to calculate the sum of elements in a chunk of the array
func calculateChunkSum(arr []int, start, end int, wg *sync.WaitGroup, results chan<- int) {
	defer wg.Done()
	sum := 0
	for i := start; i < end; i++ {
		sum += arr[i]
	}
	results <- sum
}

// Function for parallel summation of chunks
func parallelSum(arr []int, numThreads int) {
	chunkSize := len(arr) / numThreads
	var wg sync.WaitGroup
	results := make(chan int, numThreads)

	startTime := time.Now()

	// Create goroutines to calculate partial sums for each chunk
	for i := 0; i < numThreads; i++ {
		start := i * chunkSize
		end := start + chunkSize
		if i == numThreads-1 {
			end = len(arr)
		}
		wg.Add(1)
		go calculateChunkSum(arr, start, end, &wg, results)
	}

	// Wait for all goroutines to finish
	wg.Wait()
	close(results)

	// Calculate total sum
	totalSum := 0
	for partialSum := range results {
		totalSum += partialSum
	}

	duration := time.Since(startTime)

	fmt.Println("Parallel Sum:", totalSum)
	fmt.Println("Parallel Execution Time:", duration)
}

// Function for single-threaded summation
func singleThreadedSum(arr []int) {
	startTime := time.Now()

	totalSum := 0
	for _, num := range arr {
		totalSum += num
	}

	duration := time.Since(startTime)

	fmt.Println("Single-Threaded Sum:", totalSum)
	fmt.Println("Single-Threaded Execution Time:", duration)
}

func main() {
	arraySize := 1000000
	numThreads := 4
	fmt.Println("Basic Parallel Sum in Go ->")
	// Create a large array
	arr := make([]int, arraySize)
	for i := 0; i < arraySize; i++ {
		arr[i] = i + 1 // Populate with sequential numbers
	}

	// Perform single-threaded summation for comparison
	singleThreadedSum(arr)

	// Perform parallel summation
	parallelSum(arr, numThreads)
}
