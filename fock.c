/*  7. Demonstrate fork () system call. Let the parent process display its pid, ppid and a message I am the parent. Also let the child display its pid, ppid and a     message I am the child.  */


#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid == -1) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // This code is executed by the child process
        printf("I am the child. PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // This code is executed by the parent process
        printf("I am the parent. PID: %d, PPID: %d\n", getpid(), getppid());
    }

    return 0;
}
