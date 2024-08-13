# Sub-Task2.py

def create_input_file():
    """Create input.txt and write some content to it."""
    file_path = 'input.txt'
    with open(file_path, 'w') as file:
        file.write("This is a test string for Sub-Task 2.")

def read_and_write():
    """Read content from input.txt and write it to output.txt."""
    file_path = 'input.txt'
    
    # Read content from input.txt
    with open(file_path, 'r') as file:
        file_content = file.read()
    
    # Print the content read from input.txt
    print("Content read from input.txt:")
    print(file_content)
    
    # Write content to output.txt
    with open('output.txt', 'w') as file:
        file.write(file_content)
    
    print("Content successfully copied from input.txt to output.txt")
    
    # Append content to output.txt
    with open('output.txt', 'a') as file:
        file.write("\nAppending new content to output.txt.")

    # Read and print the updated content of output.txt
    with open('output.txt', 'r') as file:
        updated_content = file.read()
    
    print("Updated content of output.txt:")
    print(updated_content)

if __name__ == "__main__":
    create_input_file()
    read_and_write()

