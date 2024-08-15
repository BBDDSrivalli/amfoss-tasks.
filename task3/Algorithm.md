<strong>Task 1: Hello World</strong>

Algorithm:

    Initialization:
        Prepare a program to output a simple message.
    Output:
        Print "Hello, World!" to the console.

General Steps:

    Define a main function (or the equivalent in the language).
    Use print/output statement to display "Hello, World!".

<hr>
<strong>Task 2: Read and Write from Files</strong>

Algorithm:

    Create Input File:
        Define a function to create an input.txt file.
        Open the file in write mode and write a predefined string.
        Close the file.

    Read and Write Operation:
        Define a function to:
            Open input.txt in read mode.
            Read the content and store it.
            Print the content.
            Open output.txt in write mode.
            Write the content from input.txt to output.txt.
            Close both files.
            Print a success message.

General Steps:

    Create Input File:
        Open file for writing.
        Write content and close file.

    Read and Write:
        Open input.txt for reading.
        Read and store the content.
        Open output.txt for writing.
        Write the content to output.txt.
        Close files.

<hr>
<strong>
  Task 3: Generate a Diamond Pattern
</strong>


Algorithm:

    Input:
        Read the number of rows (n).

    Generate Upper Half:
        Loop from 1 to (n + 1) // 2:
            Print leading spaces.
            Print stars.
            Move to the next line.

    Generate Lower Half:
        Loop from (n + 1) // 2 + 1 to n:
            Print leading spaces.
            Print stars.
            Move to the next line.
