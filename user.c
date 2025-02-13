#include <stdio.h>   // Standard I/O functions (printf, fprintf)
#include <stdlib.h>  // Standard library functions (atoi, exit)
#include <unistd.h>  // POSIX functions (sleep, getpid, getppid)

int main(int argc, char *argv[]) {
    // Ensure exactly one command-line argument (number of iterations) is provided.
    if (argc != 2) {
        // Print usage information to stderr if the argument count is incorrect.
        fprintf(stderr, "Usage: %s <iterations>\n", argv[0]);
        exit(EXIT_FAILURE);  // Exit with failure status.
    }

 // Convert the argument (iterations) from a string to an integer.
 int iterations = atoi(argv[1]);

 // Loop from 1 to the number of iterations (inclusive).
 for (int i = 1; i <= iterations; i++) {
     // Print process information before sleeping:
     // getpid() returns the current process's PID,
     // getppid() returns the parent's PID.
     printf("USER PID:%d PPID:%d Iteration:%d before sleeping\n",
            getpid(), getppid(), i);
     
     sleep(1);  // Pause execution for 1 second.

     // Print process information after sleeping.
     printf("USER PID:%d PPID:%d Iteration:%d after sleeping\n",
            getpid(), getppid(), i);
 }

 return 0;  // Return success.
}