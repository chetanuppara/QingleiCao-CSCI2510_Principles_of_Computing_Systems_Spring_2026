#include <unistd.h>
#include <sys/types.h>

#define bufferSize 200

int main(void) {
    char buffer[bufferSize];

    while (1) {
        ssize_t bytesRead = read(STDIN_FILENO, buffer, bufferSize);
        if (bytesRead == 0) break;     // EOF
        if (bytesRead < 0) return 1;   // error

        ssize_t total = 0;
        while (total < bytesRead) {
            ssize_t n = write(STDOUT_FILENO, buffer + total, bytesRead - total);
            if (n < 0) return 1;
            total += n;
        }
    }
    return 0;
}
