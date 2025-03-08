#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];
    int fd = open(file, O_WRONLY);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Applying file lock...\n");

    // Define file lock structure
    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock entire file

    // Attempt to lock file
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error locking file");
        close(fd);
        return 1;
    }

    printf("File locked. Press Enter to unlock...\n");
    getchar(); // Wait for user input

    // Unlock file
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error unlocking file");
        close(fd);
        return 1;
    }

    printf("File unlocked successfully.\n");
    close(fd);
    return 0;
}
