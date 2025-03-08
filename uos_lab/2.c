#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;  // Process ID for fork
    int status; // Status for waitpid

    printf("Parent Process ID: %d\n", getpid());
    
    // Create a new process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        printf("Child executing application...\n");

        // Replace the current process with a new program (e.g., gnome-calculator)
        execlp("gnome-calculator", "gnome-calculator", NULL);

        // If exec fails
        perror("Exec failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent waiting for child to terminate...\n");
        waitpid(pid, &status, 0); // Wait for child to finish
        printf("Child process exited with status: %d\n", WEXITSTATUS(status));
    }

    printf("Parent process terminating.\n");
    return 0;
}
