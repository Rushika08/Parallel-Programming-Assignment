#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int a[] = {1, 2, 3, 5};
    int b[] = {7, 8, 9, 7};
    int c[sizeof(a) / sizeof(a[0])]; // Array to store the results of a + b
    int n = sizeof(a) / sizeof(a[0]); // Size of the arrays
    pid_t pid;

    // Loop to create child processes
    for (int i = 0; i < n; i++) {
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork failed"); // Print an error message if forking fails
            return 1; // Exit with an error code
        } else if (pid == 0) {
            // In child process
            c[i] = a[i] + b[i]; // Calculate the sum of elements in the child process
            printf("Child id: %d : c[%d] = %d\n", getpid(), i, c[i]); // Print child process information
            return 0; // Exit child process
        } else {
            wait(NULL); // Parent waits for the child to finish
        }
    }

    return 0; // The main process exits after creating all child processes
}