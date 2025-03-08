#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void executeWithExecvp(const char *program, char *const args[]) {
    printf("Child (PID: %d) executing task using execvp: %s\n", getpid(), program);
    execvp(program, args);
    perror("Execvp failed"); // Only executed if exec fails
    exit(EXIT_FAILURE);
}

void executeWithExecl(const char *program) {
    printf("Child (PID: %d) executing task using execl: %s\n", getpid(), program);
    execl(program, program, "-l", NULL);
    perror("Execl failed");
    exit(EXIT_FAILURE);
}

void createChildUsingFork(const char *program, char *const args[]) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // In child process
        executeWithExecvp(program, args);
    }
    // Parent process
    printf("Parent created child with PID: %d\n", pid);
    waitpid(pid, NULL, 0); // Wait for child to complete
    printf("Child (PID: %d) finished execution.\n", pid);
}

void createChildUsingVfork(const char *program) {
    pid_t pid = vfork();
    if (pid < 0) {
        perror("Vfork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // In child process
        executeWithExecl(program);
    }
    // Parent process
    printf("Parent created child using vfork with PID: %d\n", pid);
    waitpid(pid, NULL, 0); // Wait for child to complete
    printf("Child (PID: %d) finished execution.\n", pid);
}

int main() {
    printf("Parent process PID: %d\n", getpid());

    // Using fork() and execvp() to execute a command
    char *lsArgs[] = {"ls", "-l", NULL};
    createChildUsingFork("/bin/ls", lsArgs);

    // Using vfork() and execl() to execute a different command
    createChildUsingVfork("/bin/echo");

    // Task for another child with execv()
    pid_t pid = fork();
    if (pid == 0) {
        char *dateArgs[] = {"/bin/date", NULL};
        printf("Child (PID: %d) executing task using execv: date\n", getpid());
        execv(dateArgs[0], dateArgs);
        perror("Execv failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        printf("Parent created another child with PID: %d\n", pid);
        waitpid(pid, NULL, 0); // Wait for this child to complete
        printf("Child (PID: %d) finished execution.\n", pid);
    }

    printf("Parent process (PID: %d) exiting.\n", getpid());
    return 0;
}
