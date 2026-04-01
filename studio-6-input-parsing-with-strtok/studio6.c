#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char input[256];

    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *token;
    char *delim = " ";

    token = strtok(input, delim);

    int max_args = 15;
    int max_argv_size = max_args + 2;
    char *cmd;
    char *my_argv[max_argv_size];

    cmd = token;

    int i = 0;
    while (token != NULL && i < max_args) {
        my_argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    my_argv[i] = NULL;

    for (int j = 0; j < i; j++) {
        printf("%s\n", my_argv[j]);
    }

    execvp(cmd, my_argv);

    return 0;
}


