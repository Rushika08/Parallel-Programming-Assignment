#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

void createChild() {
    pid_t child_pid = fork(); // Create a new process by forking

    if (child_pid < 0) {
        perror("fork failed"); // Print an error message if forking fails
        exit(1); // Exit with an error code
    } else if (child_pid == 0) {
        // Child process
        printf("Hello from Child! Process ID (PID): %d\n", getpid()); // Print child process information
        // Add child-specific work here
        exit(0); // Exit child process
    }
    // Parent process continues
}

int main() {
    // Call createChild() twice to create two child processes
    createChild();
    createChild();

    // Parent process continues
    printf("Hello from Parent! Process ID (PID): %d\n", getpid()); // Print parent process information

    // Wait for child processes to exit (optional)
    int status;
    wait(&status); // Wait for the first child process to exit
    wait(&status); // Wait for the second child process to exit

    return 0;
}
