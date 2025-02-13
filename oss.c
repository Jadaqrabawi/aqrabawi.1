#include <stdio.h>      // Standard I/O for printf, fprintf
#include <stdlib.h>     // Standard library for atoi, exit
#include <unistd.h>     // POSIX API for fork, execl, getopt, sleep
#include <sys/wait.h>   // For wait() function to wait for child processes
#include <getopt.h>     // For parsing command-line options

// Function to print usage information for the program.
// It prints the correct syntax and explains the available command-line options.
void print_usage(const char *prog) {
    fprintf(stderr, "Usage: %s [-h] [-n proc] [-s simul] [-t iter]\n", prog);
    fprintf(stderr, "   -n proc   Total number of user processes to launch\n");
    fprintf(stderr, "   -s simul  Maximum number of processes to run simultaneously\n");
    fprintf(stderr, "   -t iter   Number of iterations to pass to each user process\n");
}

int main(int argc, char *argv[]) {
    int opt;
    // Set default values for total processes, simultaneous limit, and iterations.
    int total_procs = 1, simul_limit = 1, iterations = 1;

    // Parse command-line options using getopt.
    // 'h' for help, 'n' for total processes, 's' for simultaneous limit, and 't' for iterations.
    while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
        switch (opt) {
            case 'h':  // Help option: print usage and exit successfully.
                print_usage(argv[0]);
                exit(EXIT_SUCCESS);
            case 'n':  // Total number of processes option: convert optarg to integer.
                total_procs = atoi(optarg);
                break;
            case 's':  // Simultaneous limit option: convert optarg to integer.
                simul_limit = atoi(optarg);
                break;
            case 't':  // Iterations option: convert optarg to integer.
                iterations = atoi(optarg);
                break;
            default:   // For any unrecognized option, print usage and exit with failure.
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

   
    int launched = 0;   // Counter for the total number of launched user processes.
    int running = 0;    // Counter for the number of currently running (active) child processes.
    int status;         // Variable to capture exit status from child processes.

    // Main loop: Continue launching children until the desired total number is reached.
    while (launched < total_procs) {
        // Check if we are below the simultaneous process limit.
        if (running < simul_limit) {
            pid_t pid = fork();  // Create a new process.
            if (pid < 0) {
                // Fork failed: print error message and exit.
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process:
                // Convert the iteration count to a string to pass as a command-line argument.
                char iter_str[16];
                snprintf(iter_str, sizeof(iter_str), "%d", iterations);
                // Execute the user process executable "./user" with the iteration parameter.
                execl("./user", "./user", iter_str, (char *)NULL);
                // If execl returns, an error occurred; print error and exit child.
                perror("execl");
                exit(EXIT_FAILURE);
                
                
            } else {
                // Parent process:
                running++;    // Increment the count of running child processes.
                launched++;   // Increment the count of total launched processes.
            }
        } else {
            // If the simultaneous limit has been reached, wait for any child to finish.
            pid_t finished = wait(&status);
            if (finished > 0) {
                running--;  // Decrement the running counter as a child has finished.
            }
        }
    }

    // After launching all children, wait for any remaining child processes to finish.
    while (running > 0) {
        wait(&status);
        running--;
    }

    return 0; // Exit successfully.
}
