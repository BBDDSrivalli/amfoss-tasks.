#include <iostream>

void printPattern(int n) {
    std::cout << "Pattern 1\n";
    
    int mid = (n + 1) / 2; // Calculate the middle row index
    
    // Print the top half of the pattern
    for (int i = 1; i <= mid; i++) {
        // Print leading spaces
        for (int j = 0; j < mid - i; j++) {
            std::cout << " ";
        }
        // Print stars
        for (int j = 0; j < (i * 2) - 1; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    // Print the bottom half of the pattern
    for (int i = mid - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = 0; j < mid - i; j++) {
            std::cout << " ";
        }
        // Print stars
        for (int j = 0; j < (i * 2) - 1; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows: ";
    std::cin >> n;
    
    // Ensure n is at least 1 and an odd number for a symmetric pattern
    if (n < 1) {
        std::cerr << "Number of rows must be at least 1." << std::endl;
        return 1;
    }
    if (n % 2 == 0) {
        std::cerr << "Number of rows must be an odd number for a symmetric pattern." << std::endl;
        return 1;
    }
    
    printPattern(n);

    return 0;
}
