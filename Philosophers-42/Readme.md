# Philosophers

### Philosophers with threads and mutexes
### The basics of threading a process. You will see how to create threads and you will discover mutexes
### The famous "Dining Philosophers Problem"

## Table of Contents
- [Project Title](#philosophers)
- [Table of Contents](#table-of-contents)
- [The dining Philosophers Problem](#the-dining-philosophers-problem)
- [Explain the General idea](#explain-the-general-idea)
- [Difference between process and thread](#difference-between-process-and-thread)
- [Data Races Conditions](#data-races-race-conditions--what-are-they)
- [Mutex](#mutex)

## The Dining Philosophers Problem:
[The dining philosophers problem]((https://en.wikipedia.org/wiki/Dining_philosophers_problem)) is a famous problem in computer science used to illustrate common issues in [concurrent programming](https://en.wikipedia.org/wiki/Concurrency_(computer_science)). The problem was originally formulated in 1965 by [Edsger Dijkstra](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra), and is stated as follows:

	X amount of philosophers sit at a round table with bowls of food.
	Forks are placed in front of each philosopher.
	There are as many forks as philosophers.
	All day the philosophers take turns eating, sleeping, and thinking.
	A philosopher must have two forks in order to eat, and each fork
	may only be used by one philosopher at a time. At any time a
	philosopher can pick up or set down a fork,
	but cannot start eating until picking up both forks.
	The philosophers alternatively eat, sleep, or think.
	While they are eating, they are not thinking not sleeping,
	while thinking, they are not eating not sleeping,
	and, of course, while sleeping, they are not eating not thinking

## Explain the General idea:
First of all, we have to imgine a table, X num of philosophers sitting around it and each of them brings a fork and places it in front of them. And we know that a philosophers can eat, sleep or think, but in order to eat he has to pick two forks(the one in front of him and another one to his right or to his left).
Let's use a picture to have a more concrete idea of what we are talking about:

![The dining philosopers problem](img/os-dining-philosophers-problem.gif)

Let's say there are 5 philosophers sitting at the table. Philosopher 1 wants to eat, so he picks the fork int front of him and the one to his right, at this point, we notice that philosopher 2 and philosopher 5 can't eat, since philosopher 1 picked the fork int front of him and in front of philosopher 5. this might seem a little obvious but keep in mind this situation because the main problem of this project is how to organize the eating action of the philosophers. Probably the first solution that came to your mind is to simply make the odd and even philos eat separately, well we are not going to do that, it's too hard coded and we would lose the meaning of the project, philos have to organize by themselves. We will be using [threads](https://en.wikipedia.org/wiki/Thread_(computing)) and implement a [multithreading solution](https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)).

In the first, you'll needs to understand the concept of threads, here are some good videos I recommend you watch:

* [General introduction to threads](https://www.youtube.com/watch?v=LOfGJcVnvAk)

* [Introduction to threads with code examples](https://www.youtube.com/watch?v=ldJ8WGZVXZk)

* [Short introduction to threads (pthreads)](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

## Difference between process and thread:
Process: A process is an independent and self-contained unit of execution in a computer system. It is a instance of a running program that includes its own memory space, ressources and system stat. A process has it's own main thread, so your program is a thread. Each process has its own separate memory space. Process do not share memory with other process by default. Process are allocated system ressources, including CPU time, memory, file handles, and more. Each process operates independently of other processes.
Thread: A thread is the smallest unit of execution within a process. It shares the same ressources and memory space as others threads whiting the same process. Threads whitin the same process and share the same memory space. They can directly access the memory of other threads whitin the same process. Threads whitin a process share the same ressources. They can efficiently communicate with each other through shared memory. Threads whitin the same process can communicate directly through shared variable and data structures.

## Data Races (Race Conditions) — What Are They?
Data races are a common problem in multithreaded programming. Data races occur when multiple tasks or threads access a shared resource without sufficient protections, leading to undefined or unpredictable behavior.
* two or more threads concurrently accessing a location of memory
* one of them is a write
* one of them is unsynchronized
In simpler words a race condition can happen when 2 or more threads are trying to access and modify the same variable at the same time, it can lead to an error in the final value of the variable, it doesn’t mean it will for sure happen though.
How can we solve this? easily we just need to attach a lock, let me introduce you to mutex.
* [What a race condition](https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3&ab_channel=CodeVault)
* [Race Conditions Explained with An Example](https://www.youtube.com/watch?v=K1aoimUYTK8&ab_channel=PortfolioCourses)

## Mutex

Now that we know what is a race condition let’s see what is the solution.
Imagine a lock that protects a block of code and it can be only executed by the lock owner until he unlocks the lock. Taking the previous example we can avoid the overwrite by adding a lock in the deposit function. if thread #1 reaches the lock thread #2 will just have to wait until thread #1 is done executing the code and reaches the unlock, only then thread #2 will enter and execute himself.
```c
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

// the initial balance is 0
int balance = 0;

// write the new balance (after as simulated 1/4 second delay)
void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}

// returns the balance (after a simulated 1/4 seond delay)
int read_balance()
{
  usleep(250000);
  return balance;
}

// carry out a deposit
void* deposit(void *amount)
{
  // lock the mutex
  pthread_mutex_lock(&mutex);

  // retrieve the bank balance
  int account_balance = read_balance();

  // make the update locally
  account_balance += *((int *) amount);

  // write the new bank balance
  write_balance(account_balance);

  // unlock to make the critical section available to other threads
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main()
{
  // mutex variable
  pthread_mutex_t mutex;

  // output the balance before the deposits
  int before = read_balance();
  printf("Before: %d\n", before);

  // we'll create two threads to conduct a deposit using the deposit function
  pthread_t thread1;
  pthread_t thread2;

  // initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // the deposit amounts... the correct total afterwards should be 500
  int deposit1 = 300;
  int deposit2 = 200;

  // create threads to run the deposit function with these deposit amounts
  pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
  pthread_create(&thread2, NULL, deposit, (void*) &deposit2);

  // join the threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

   // destroy the mutex
  pthread_mutex_destroy(&mutex);

  // output the balance after the deposits
  int after = read_balance();
  printf("After: %d\n", after);

  return 0;
}
```
You have surely noticed that we initialize and destroy the mutex, and you have to do that every time you want to use a mutex (destroy it after you finished using it) otherwise it won’t work.
* [What is a mutex in c(pthreads_mutex)](https://www.youtube.com/watch?v=oq29KUy29iQ&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=5&ab_channel=CodeVault)
* [Mutex introduction(p_threads)](https://www.youtube.com/watch?v=raLCgPK-Igc&t=424s&ab_channel=PortfolioCourses)