#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Signal handler for custom signal
void signalHandler(int sig) {
    printf("[Receiver] Received Signal: %d\n", sig);
    printf("[Receiver] Custom Signal Handling Done.\n");
}

int main() {
    // Get the process ID of the receiver
    pid_t pid = getpid();
    printf("[Receiver] Process ID: %d\n", pid);

    // Set the signal handler for SIGUSR1
    signal(SIGUSR1, signalHandler);

    // Wait for signals
    printf("[Receiver] Waiting for a signal...\n");
    while (1) {
        pause(); // Wait for signal
    }

    return 0;
}
