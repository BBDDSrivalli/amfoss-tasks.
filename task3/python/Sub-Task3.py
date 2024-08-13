n = int(input("Enter the number of rows: "))
print("Pattern 1")

# Upper half of the diamond
for a1 in range(1, (n + 1) // 2 + 1):
    # Print leading spaces
    for a2 in range((n + 1) // 2 - a1):
        print(" ", end="")
    # Print asterisks
    for a3 in range((a1 * 2) - 1):
        print("*", end="")
    print()

# Lower half of the diamond
for a1 in range((n + 1) // 2 + 1, n + 1):
    # Print leading spaces
    for a2 in range(a1 - (n + 1) // 2):
        print(" ", end="")
    # Print asterisks
    for a3 in range((n + 1 - a1) * 2 - 1):
        print("*", end="")
    print()
