#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

int main() {
    pid_t child_pid = fork(); // Create a new process by forking

    if (child_pid < 0) {
        perror("fork failed"); // Print an error message if forking fails
        exit(1); // Exit with an error code
    } else if (child_pid == 0) {
        // Child process
        printf("Hello from Child! Process ID (PID): %d\n", getpid()); // Print child process information
    } else {
        // Parent process
        printf("Hello from Parent! Process ID (PID): %d\n", getpid()); // Print parent process information
    }

    return 0;
}