#include <stdio.h>
#include <stdlib.h>
// creating a input file if its not there
//Thats why its's in a  "w" mode.
void create_input_file() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error creating input.txt\n");
        exit(1);
    }
    fprintf(file, "This is a test string for Sub-Task 2.");
    fclose(file);
}

//I have already created a input.txt file manually  so this function just reads it
void read_and_write() {
// creating a string to read from the file
    char buffer[256];
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input.txt\n");
        exit(1);
    }// fgets - reads string from a file 
// syntax - fgets(string name , number of bytes we need to read,file pointer i.e from which file we want to read the file )
    fgets(buffer, sizeof(buffer), file);
    printf("Content read from input.txt:\n%s\n", buffer);//This is for our confirmation
    fclose(file);// close the input file

    file = fopen("output.txt", "w");//open the o/p file in "w" mode so that buffer can be written here
    if (file == NULL) {
        printf("Error creating output.txt\n");
        exit(1);
    }
//if the file exists then print the buffer we have stored
    fprintf(file, "%s", buffer);
    fclose(file);//close it
    printf("Content successfully copied from input.txt to output.txt\n");

    printf("Updated content of output.txt:\n");
}
int main() {
    create_input_file();
    read_and_write();
    return 0;
}




















