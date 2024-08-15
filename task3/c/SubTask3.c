#include <stdio.h>

void printPattern(int n) {
    printf("Pattern 1\n");
    
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 0; j < (n + 1) / 2 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < (i * 2) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        for (int j = 0; j < i - (n + 1) / 2; j++) {
            printf(" ");
        }
        for (int j = 0; j < (n + 1 - i) * 2 - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    printPattern(n);

    return 0;
}
