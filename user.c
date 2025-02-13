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

