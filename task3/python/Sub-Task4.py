def read_number_from_file(file_path):
    """Read a number from a file."""
    with open(file_path, 'r') as file:
        # Read the first line and convert it to an integer
        number = int(file.readline().strip())
    return number

def generate_diamond_pattern(n):
    """Generate a diamond pattern with `n` rows."""
    pattern = []
    
    # Generate the upper part of the diamond
    for i in range(1, (n + 1) // 2 + 1):
        spaces = ' ' * ((n + 1) // 2 - i)  # Leading spaces
        stars = '*' * (i * 2 - 1)          # Number of stars
        pattern.append(spaces + stars)
    
    # Generate the lower part of the diamond
    for i in range((n + 1) // 2 + 1, n + 1):
        spaces = ' ' * (i - (n + 1) // 2)  # Leading spaces
        stars = '*' * ((n + 1 - i) * 2 - 1)  # Number of stars
        pattern.append(spaces + stars)
    
    return '\n'.join(pattern)

def write_pattern_to_file(file_path, pattern):
    """Write the diamond pattern to a file."""
    with open(file_path, 'w') as file:
        file.write(pattern)

def main():
    """Main function to read number, generate pattern, and write to file."""
    input_file_path = 'input4.txt'  # Updated input file name
    output_file_path = 'output4.txt'  # Updated output file name
    
    # Step 1: Read the number from input4.txt
    n = read_number_from_file(input_file_path)
    print(f"Read number: {n}")  # Debugging line
    
    # Step 2: Generate the diamond pattern
    pattern = generate_diamond_pattern(n)
    print("Generated pattern:")
    print(pattern)  # Debugging line
    
    # Step 3: Write the pattern to output4.txt
    write_pattern_to_file(output_file_path, pattern)
    print("Pattern written to output4.txt")  # Debugging line

if __name__ == "__main__":
    main()

