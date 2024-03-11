#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

void DoWorkInChild() {
    // Placeholder function for child process work
    printf("Child process with PID %d is working.\n", getpid());
}

int main() {
    int num_children = 5; // Number of child processes to create

    for (int i = 0; i < num_children; ++i) {
        pid_t child_pid = fork(); // Create a new process by forking

        if (child_pid < 0) {
            perror("fork failed"); // Print an error message if forking fails
            exit(1); // Exit with an error code
        } else if (child_pid == 0) {
            // Child process
            DoWorkInChild();
            exit(0); // Exit child process
        }
        // Parent process continues to loop
    }

    // Wait for all child processes to exit
    int status;
    pid_t pid;
    while (num_children > 0) {
        pid = wait(&status); // Wait for any child process to exit and get its status
        printf("Child process with PID %ld exited with status 0x%x.\n", (long)pid, status); // Print information about the exited child process
        --num_children;
    }

    return 0;
}
