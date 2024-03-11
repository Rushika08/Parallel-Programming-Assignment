#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int a, b, z, c;
    pid_t pid_a, pid_b, pid_z;

    // Fork first child for 'a'
    pid_a = fork();

    if (pid_a == 0) {
        // In child process for 'a'
        a = 1 + 2;
        printf("Calculated a = %d\n", a);
        return 0; // Exit child process
    }

    // Fork second child for 'b'
    pid_b = fork();

    if (pid_b == 0) {
        // In child process for 'b'
        b = 4 * 5;
        printf("Calculated b = %d\n", b);
        return 0; // Exit child process
    }

    // Fork third child for 'z'
    pid_z = fork();

    if (pid_z == 0) {
        // In child process for 'z'
        a = 1 + 2; // Duplicated work, just for the sake of example
        z = a * 2;
        printf("Calculated z = %d\n", z);
        return 0; // Exit child process
    }

    // In parent process, wait for all child processes to finish
    waitpid(pid_a, NULL, 0);
    waitpid(pid_b, NULL, 0);
    waitpid(pid_z, NULL, 0);

    // Calculate 'c' in the parent process
    a = 1 + 2;
    b = 4 * 5;
    z = a * 2;
    c = a + b + z;

    printf("Calculated c = %d\n", c);

    return 0;
}