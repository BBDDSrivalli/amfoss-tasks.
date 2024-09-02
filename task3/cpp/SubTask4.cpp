#include <iostream>
#include <fstream>

void printPatternToFile(int n, std::ofstream &outputFile) {
    // Print the top half of the diamond
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 0; j < (n + 1) / 2 - i; j++) {
            outputFile << " ";
            std::cout << " ";  // Print to console as well
        }
        for (int j = 0; j < (i * 2) - 1; j++) {
            outputFile << "*";
            std::cout << "*";  // Print to console as well
        }
        outputFile << "\n";
        std::cout << "\n";  // Print to console as well
    }

    // Print the bottom half of the diamond
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        for (int j = 0; j < i - (n + 1) / 2; j++) {
            outputFile << " ";
            std::cout << " ";  // Print to console as well
        }
        for (int j = 0; j < (n + 1 - i) * 2 - 1; j++) {
            outputFile << "*";
            std::cout << "*";  // Print to console as well
        }
        outputFile << "\n";
        std::cout << "\n";  // Print to console as well
    }
}

int main() {
    int n;

    // Read input directly from user
    std::cout << "Enter the number of rows: ";
    std::cin >> n;

    // Write to output file
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Error opening output.txt" << std::endl;
        return 1;
    }

    // Print pattern to both console and file
    printPatternToFile(n, outputFile);
    outputFile.close();

    std::cout << "Diamond pattern has been written to output.txt" << std::endl;

    return 0;
}
