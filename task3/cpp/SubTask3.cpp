#include <iostream>

void printPattern(int n) {
    std::cout << "Pattern 1" << std::endl;

    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 0; j < (n + 1) / 2 - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < (i * 2) - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        for (int j = 0; j < i - (n + 1) / 2; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < (n + 1 - i) * 2 - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    printPattern(n);

    return 0;
}
