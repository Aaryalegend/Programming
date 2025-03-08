#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

pid_t child_pid;

// Signal handler for the parent process
void parentSignalHandler(int sig) {
    if (sig == SIGUSR1) {
        printf("[Parent] Received SIGUSR1 from child. Task acknowledged.\n");
    } else if (sig == SIGUSR2) {
        printf("[Parent] Received SIGUSR2 from child. Task completed.\n");
    }
}

// Signal handler for the child process
void childSignalHandler(int sig) {
    if (sig == SIGTERM) {
        printf("[Child] Received SIGTERM from parent. Terminating.\n");
        exit(0);
    }
}

int main() {
    pid_t pid;

    // Set up signal handlers for parent
    signal(SIGUSR1, parentSignalHandler);
    signal(SIGUSR2, parentSignalHandler);

    // Fork to create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        signal(SIGTERM, childSignalHandler);

        printf("[Child] PID: %d, waiting to send signals to parent...\n", getpid());
        sleep(2);
        kill(getppid(), SIGUSR1);  // Notify parent of task acknowledgement
        sleep(2);
        kill(getppid(), SIGUSR2);  // Notify parent of task completion

        printf("[Child] Sending termination signal to self...\n");
        kill(getpid(), SIGTERM);  // Terminate child
    } else {
        // Parent process
        child_pid = pid;

        printf("[Parent] Waiting for signals from child (PID: %d)...\n", child_pid);
        while (1) {
            // Keep the parent alive to handle signals
            pause();
        }
    }

    return 0;
}
