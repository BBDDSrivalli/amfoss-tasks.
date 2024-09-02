#include <stdio.h>
#include <stdlib.h>

void printPatternToFile(int n, FILE *outputFile) {
    // Print the top half of the diamond
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 0; j < (n + 1) / 2 - i; j++) {
            fprintf(outputFile, " ");
            printf(" ");  // Print to console as well
        }
        for (int j = 0; j < (i * 2) - 1; j++) {
            fprintf(outputFile, "*");
            printf("*");  // Print to console as well
        }
        fprintf(outputFile, "\n");
        printf("\n");  // Print to console as well
    }

    // Print the bottom half of the diamond
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        for (int j = 0; j < i - (n + 1) / 2; j++) {
            fprintf(outputFile, " ");
            printf(" ");  // Print to console as well
        }
        for (int j = 0; j < (n + 1 - i) * 2 - 1; j++) {
            fprintf(outputFile, "*");
            printf("*");  // Print to console as well
        }
        fprintf(outputFile, "\n");
        printf("\n");  // Print to console as well
    }
}

int main() {
    int n;

    // Read input directly from user
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Write to output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt\n");
        return 1;
    }

    // Print pattern to both console and file
    printPatternToFile(n, outputFile);
    fclose(outputFile);

    printf("Diamond pattern has been written to output.txt\n");

    return 0;
}
