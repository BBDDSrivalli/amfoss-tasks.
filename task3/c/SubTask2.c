#include <stdio.h>
#include <stdlib.h>

void create_input_file() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error creating input.txt\n");
        exit(1);
    }
    fprintf(file, "This is a test string for Sub-Task 2.");
    fclose(file);
}

void read_and_write() {
    char buffer[256];
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input.txt\n");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), file);
    printf("Content read from input.txt:\n%s\n", buffer);
    fclose(file);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error creating output.txt\n");
        exit(1);
    }
    fprintf(file, "%s", buffer);
    fclose(file);
    printf("Content successfully copied from input.txt to output.txt\n");

    file = fopen("output.txt", "a");
    if (file == NULL) {
        printf("Error opening output.txt for append\n");
        exit(1);
    }
    fprintf(file, "\nAppending new content to output.txt.");
    fclose(file);

    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error reading output.txt\n");
        exit(1);
    }
    printf("Updated content of output.txt:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    create_input_file();
    read_and_write();
    return 0;
}
