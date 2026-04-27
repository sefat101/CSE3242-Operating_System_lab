/*Question 2—Process
Write a program where:

parent prints numbers 1– 5

child prints numbers 6– 10
Observe execution order. */

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child
        for (int i = 6; i <= 10; i++) {
            printf("Child: %d\n", i);
        }
    }
    else {
        // Parent
        for (int i = 1; i <= 5; i++) {
            printf("Parent: %d\n", i);
        }
    }

    return 0;
}


//use wait(NULL) for controlled mode 
