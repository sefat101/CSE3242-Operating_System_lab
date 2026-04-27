/*Question 3—Process
Create two child processes from one parent process and display the process tree.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    printf("Parent Process (PID: %d)\n", getpid());

    pid1 = fork();

    if (pid1 == 0) {
        printf("├── First Child (PID: %d, PPID: %d)\n", getpid(), getppid());
    }
    else {
        wait(NULL); // wait first child

        pid2 = fork();

        if (pid2 == 0) {
            printf("└── Second Child (PID: %d, PPID: %d)\n", getpid(), getppid());
        }
        else {
            wait(NULL); // wait second child
        }
    }

    return 0;
}
