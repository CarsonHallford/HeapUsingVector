# Instructions  

The purpose of this exercise is to write a Heap data structure and demonstrate the efficiency of insertion, removal, and peeking at the maximum element.

Heaps can be used for implementing a priority queue. Priority queues are often used in operating systems to manage task scheduling. The OS, such as Windows, MacOS, Android, etc. is reponsible for scheduling and running small chunks of work (tasks) for all the processing running on the OS. Processes can request a higher priority in order to get scheduled quicker. This is often the case for time-sensitive processes, such as audio or video players.

Implement a Heap data structure that can have many numbers inserted into it, but always removes and returns the maximum number.

## Heap Methods

Your heap must have these methods.

* `void insert(int item)`
* `int max()`
* `void remove_max()`
* `bool empty()`

## Input / Output

A task is identified by its priority, which is a single integer.
Executing a task is done by printing the priority on its own line.

Three types of commands exist.
* `add N`: add a task with priority N
* `run`: Execute the next highest-priority task
* `exit`: execute all the remaining tasks and exit the program

### Example 1

Input
```
add 1
add 5
add 7
add 2
exit
```

Output
```
7
5
2
1
```

### Example 2

Input
```
add 1
add 5
add 7
add 2
run
run
add 9
exit
```

Output
```
7
5
9
2
1
```