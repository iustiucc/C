#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int min = INT_MAX;
    int max = INT_MIN;
    char line[1000];
    int first_number = 1;
    int num;
    int valid_input;

    while (1) {
        printf("Enter an integer or \"done\" to exit: ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            perror("Error reading input.\n");
            return 1;
        }

        unsigned int len = strlen(line);
        while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t' || line[len - 1] == '\n')) {
            line[--len] = '\0';
        }

        if (strcmp(line, "done") == 0) {
            break;
        }

        char *endptr;
        long lval = strtol(line, &endptr, 10);

        if (*endptr != '\0' || line == endptr) {
            printf("Invalid input: '%s'. Please enter an integer or 'done'.\n", line);
            valid_input = 0;
        } else if (lval > INT_MAX || lval < INT_MIN) {
            printf("Input '%s' is out of integer range.\n", line);
            valid_input = 0;
        } else {
            num = (int)lval;
            valid_input = 1;
        }

        if (valid_input) {
            if (first_number) {
                min = num;
                max = num;
                first_number = 0;
            } else {
                if (num < min) {
                    min = num;
                }
                if (num > max) {
                    max = num;
                }
            }
        }
    }

    if (!first_number) {
        printf("Maximum %d\n", max);
        printf("Minimum %d\n", min);
    } else {
        printf("No valid integer input received.\n");
    }

    return 0;
}
