#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Custom handler for SIGINT
void handleSIGINT(int sig) {
    printf("\n[INFO] Caught signal SIGINT (Ctrl+C). Program will not terminate.\n");
    printf("[INFO] Press Ctrl+\\ (SIGQUIT) to quit.\n");
}

int main() {
    // Set up the SIGINT signal handler
    signal(SIGINT, handleSIGINT);

    printf("Program running. Press Ctrl+C to trigger the signal handler.\n");
    printf("Press Ctrl+\\ to terminate the program.\n");

    // Keep the program running indefinitely
    while (1) {
        printf("Working...\n");
        sleep(2);
    }

    return 0;
}
