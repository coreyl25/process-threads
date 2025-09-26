# process-threads
Thread Programming Assignment
Overview
This assignment explores concurrent programming concepts using POSIX threads (pthreads). With these files I implemenedt and analyzed programs that demonstrate thread creation, race conditions, and synchronization mechanisms.
Files Included
Core Programs
t0.c - Simple thread creation example
t1.c - Race condition demonstration with shared counter
main-race.c - Basic race condition example
main-race-fixed.c - Race condition fixes with different locking strategies
Supporting Files
common.h - Utility functions (timing, memory allocation)
common_threads.h - pthread wrapper functions with error handling
Makefile - Build configuration
README.md - This file
Build All Programs
make
Program Descriptions
1. t0.c - Simple Thread Creation
Demonstrates basic thread creation and joining. Two threads print different letters.
2. t1.c - Race Condition Counter
Two threads increment a shared counter 10 million times each. Demonstrates race conditions.
3. main-race.c - Basic Race Example
Simple race condition where two threads increment a shared balance variable.
4. main-race-fixed.c - Synchronization Examples
Three test cases showing different levels of synchronization:
Case 1: No locks (race condition)
Case 2: Partial locks (still has races)
Case 3: Full locks (properly synchronized)
Running the Programs
Basic Execution
# Simple thread creation
./t0

# Race condition demo (run multiple times to see variation)
./t1
./t1

# Basic race condition
./main-race

# Test different synchronization approaches
./main-race-fixed 1  # No locks
./main-race-fixed 2  # Partial locks
./main-race-fixed 3  # Full locks
