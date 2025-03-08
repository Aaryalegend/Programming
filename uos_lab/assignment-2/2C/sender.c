#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("[Sender] Enter the Process ID of Receiver: ");
    scanf("%d", &pid);

    // Send SIGUSR1 signal to the receiver process
    printf("[Sender] Sending Signal to Process ID: %d\n", pid);
    if (kill(pid, SIGUSR1) == 0) {
        printf("[Sender] Signal Sent Successfully.\n");
    } else {
        perror("[Sender] Failed to Send Signal");
    }

    return 0;
}
