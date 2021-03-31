#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line1 = NULL;
    char *line1 = NULL;
    size_t len = 0;
    ssize_t read = 0;
        puts("Enter the first line");
        read = getline(&line, &len, stdin);
        printf("line = %s", line);
        printf("line length = %zu\n", read);
        puts("");
    free(line);
    return 0;
}