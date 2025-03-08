#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Locking the file...\n");

    // Apply an exclusive lock (LOCK_EX) on the file
    if (flock(fd, LOCK_EX) == -1) {
        perror("Error locking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File is locked. Press Enter to unlock...\n");
    getchar();  // Wait for user input before unlocking

    // Unlock the file
    if (flock(fd, LOCK_UN) == -1) {
        perror("Error unlocking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File is unlocked.\n");

    close(fd);
    return 0;
}
