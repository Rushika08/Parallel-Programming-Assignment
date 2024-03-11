#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 4; // Size of the arrays
    int a[] = {1, 2, 3, 5}; // Array 'a'
    int b[] = {7, 8, 9, 7}; // Array 'b'

    // Fork a child process
    pid_t pid = fork();

    if (pid == 0) { // Child process
        printf("Child process (PID: %d): Elements of array 'a': ", getpid());
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("Parent process (PID: %d): Elements of array 'b': ", getpid());
        for (int i = 0; i < n; i++) {
            printf("%d ", b[i]);
        }
        printf("\n");
    } else {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
