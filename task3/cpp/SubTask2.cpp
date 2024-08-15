#include <iostream>
#include <fstream>
#include <string>

void createInputFile() {
    std::ofstream file("input.txt");
    if (!file) {
        std::cerr << "Error creating input.txt" << std::endl;
        exit(1);
    }
    file << "This is a test string for Sub-Task 2.";
    file.close();
}

void readAndWrite() {
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "Error opening input.txt" << std::endl;
        exit(1);
    }
    std::string content;
    std::getline(infile, content);
    std::cout << "Content read from input.txt:" << std::endl;
    std::cout << content << std::endl;
    infile.close();

    std::ofstream outfile("output.txt");
    if (!outfile) {
        std::cerr << "Error creating output.txt" << std::endl;
        exit(1);
    }
    outfile << content;
    outfile.close();
    std::cout << "Content successfully copied from input.txt to output.txt" << std::endl;

    std::ofstream appendfile("output.txt", std::ios::app);
    if (!appendfile) {
        std::cerr << "Error opening output.txt for append" << std::endl;
        exit(1);
    }
    appendfile << "\nAppending new content to output.txt.";
    appendfile.close();

    std::ifstream updatedfile("output.txt");
    if (!updatedfile) {
        std::cerr << "Error reading output.txt" << std::endl;
        exit(1);
    }
    std::cout << "Updated content of output.txt:" << std::endl;
    while (std::getline(updatedfile, content)) {
        std::cout << content << std::endl;
    }
    updatedfile.close();
}

int main() {
    createInputFile();
    readAndWrite();
    return 0;
}
