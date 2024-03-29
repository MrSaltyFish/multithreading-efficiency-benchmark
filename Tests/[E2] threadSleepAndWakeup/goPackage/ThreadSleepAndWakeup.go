package main

import (
	"fmt"
	"time"
)

func sleepRoutine(sleepDuration time.Duration) {
	time.Sleep(sleepDuration)
}

func main() {
	sleepDuration := 10 * time.Millisecond // Sleep duration

	startTime := time.Now()

	// Create a goroutine to sleep
	go sleepRoutine(sleepDuration)

	// Wait for the goroutine to finish sleeping
	time.Sleep(sleepDuration)

	endTime := time.Now()

	duration := endTime.Sub(startTime)

	fmt.Printf("Goroutine Sleep and Wakeup Duration: %s\n", duration)
}
