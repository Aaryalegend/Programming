#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

// Signal handler
void signal_handler(int sig) {
    printf("Received signal: %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process started (PID: %d)\n", getpid());
        signal(SIGUSR1, signal_handler);
        signal(SIGALRM, signal_handler);
        pause(); // Wait for a signal
    } else if (pid > 0) {
        // Parent process
        printf("Parent process started (PID: %d)\n", getpid());
        sleep(1);

        // Using kill()
        printf("Using kill() to send SIGUSR1\n");
        kill(pid, SIGUSR1);

        // Using raise()
        printf("Using raise() to send SIGUSR1\n");
        raise(SIGUSR1);

        // Using alarm()
        printf("Using alarm() to send SIGALRM\n");
        alarm(2);
        pause(); // Wait for alarm signal

        // Using killpg()
        printf("Using killpg() to send SIGUSR1 to process group\n");
        killpg(getpgid(pid), SIGUSR1);

        // Using sigqueue()
        printf("Using sigqueue() to send SIGUSR1 with additional data\n");
        union sigval value;
        value.sival_int = 42; // Arbitrary data
        sigqueue(pid, SIGUSR1, value);

        // Wait for child process to finish
        wait(NULL);
    } else {
        perror("fork failed");
        exit(1);
    }
    return 0;
}
