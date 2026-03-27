#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // CHILD PROCESS
        sleep(3);

        printf("Child process starting exec...\n");

        char* child_argv[] = {"ls", "-l", NULL};
        char* child_prog = child_argv[0];

        execvp(child_prog, child_argv);

        // Only runs if exec fails
        perror("exec failed");
    } else {
        // PARENT PROCESS
        waitpid(pid, NULL, 0);
        printf("Parent process finished. PID: %d\n", getpid());
    }

    return 0;
}

