# 1. PYTHON
CODE SNIPPETS:
```python
# Printing and Input
print("Enter a string:")
s = input()

# File Operations
with open('file.txt', 'w') as f:
    f.write(s)

with open('file.txt', 'r') as f:
    content = f.read()

# Copying Strings
copied_string = s[:]

# Copying from one file to another
with open('file.txt', 'r') as f_in, open('copy.txt', 'w') as f_out:
    f_out.write(f_in.read())

# Function
def my_function():
    return "Hello, World!"
```
# 2. RUBY:

CODE SNIPPETS:
```ruby
# Printing and Input
puts "Enter a string:"
s = gets.chomp

# File Operations
File.open('file.txt', 'w') { |file| file.write(s) }

content = File.read('file.txt')

# Copying Strings
copied_string = s.dup

# Copying from one file to another
File.open('copy.txt', 'w') { |file| file.write(File.read('file.txt')) }

# Function
def my_function
  "Hello, World!"
end

```
# 3. ELIXIR

CODE SNIPPETS:
```elixir
# Printing and Input
IO.puts("Enter a string:")
s = IO.gets("") |> String.trim()

# File Operations
File.write!("file.txt", s)
content = File.read!("file.txt")

# Copying Strings
copied_string = String.duplicate(s, 1)

# Copying from one file to another
File.write!("copy.txt", File.read!("file.txt"))

# Function
defmodule MyModule do
  def my_function do
    "Hello, World!"
  end
end

```
# 4. JAVA SCRIPT
REQ LIBRARIES:
```javascript
const fs = require('fs');
```

CODE SNIPPETS:
```javascript
// Printing and Input
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

readline.question('Enter a string: ', s => {
  readline.close();

  // File Operations
  fs.writeFileSync('file.txt', s);
  let content = fs.readFileSync('file.txt', 'utf8');

  // Copying Strings
  let copied_string = s;

  // Copying from one file to another
  fs.copyFileSync('file.txt', 'copy.txt');

  // Function
  function myFunction() {
    return "Hello, World!";
  }
});
```
# 5. Java

REQ LIBRARIES:
```java
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

```

CODE SNIPPETS:
```java
// Printing and Input
Scanner scanner = new Scanner(System.in);
System.out.print("Enter a string: ");
String s = scanner.nextLine();

// File Operations
try {
    FileWriter writer = new FileWriter("file.txt");
    writer.write(s);
    writer.close();

    Scanner fileReader = new Scanner(new File("file.txt"));
    String content = fileReader.nextLine();
    fileReader.close();

    // Copying Strings
    String copied_string = new String(s);

    // Copying from one file to another
    FileWriter copyWriter = new FileWriter("copy.txt");
    copyWriter.write(content);
    copyWriter.close();
} catch (IOException e) {
    e.printStackTrace();
}

// Function
public static String myFunction() {
    return "Hello, World!";
}

```
# 6. GO
REQ LIBRARIES:

```go
import (
    "fmt"
    "os"
    "io/ioutil"
)

CODE SNIPPET:
```go
// Printing and Input
fmt.Println("Enter a string:")
var s string
fmt.Scanln(&s)

// File Operations
err := ioutil.WriteFile("file.txt", []byte(s), 0644)
if err != nil {
    panic(err)
}
content, err := ioutil.ReadFile("file.txt")
if err != nil {
    panic(err)
}

// Copying Strings
copied_string := s

// Copying from one file to another
err = ioutil.WriteFile("copy.txt", content, 0644)
if err != nil {
    panic(err)
}

// Function
func myFunction() string {
    return "Hello, World!"
}

```

# 7. C
REQ LIBRARIES
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```
CODE SNIPPENTS:

```C
// Printing and Input
char s[100];
printf("Enter a string: ");
scanf("%s", s);

// File Operations
FILE *file = fopen("file.txt", "w");
if (file) {
    fprintf(file, "%s", s);
    fclose(file);
}

char content[100];
file = fopen("file.txt", "r");
if (file) {
    fscanf(file, "%s", content);
    fclose(file);
}

// Copying Strings
char copied_string[100];
strcpy(copied_string, s);

// Copying from one file to another
FILE *copy = fopen("copy.txt", "w");
if (copy) {
    fprintf(copy, "%s", content);
    fclose(copy);
}

// Function
char* myFunction() {
    return "Hello, World!";
}

```
# 8. C++

REQ LIBRARIES

```cpp
#include <iostream>
#include <fstream>
#include <string>

```
CODE SNIPPET:

```cpp
// Printing and Input
std::string s;
std::cout << "Enter a string: ";
std::cin >> s;

// File Operations
std::ofstream outfile("file.txt");
outfile << s;
outfile.close();

std::ifstream infile("file.txt");
std::string content;
infile >> content;
infile.close();

// Copying Strings
std::string copied_string = s;

// Copying from one file to another
std::ofstream copyfile("copy.txt");
copyfile << content;
copyfile.close();

// Function
std::string myFunction() {
    return "Hello, World!";
}

```
# 9. Rust
Req Libraries
```Rust
use std::fs::File;
use std::io::{self, Write, Read};

```
Code Snippets
```Rust
// Printing and Input
let mut s = String::new();
println!("Enter a string:");
io::stdin().read_line(&mut s).expect("Failed to read line");

// File Operations
let mut file = File::create("file.txt").expect("Could not create file");
file.write_all(s.as_bytes()).expect("Could not write to file");

let mut content = String::new();
let mut file = File::open("file.txt").expect("Could not open file");
file.read_to_string(&mut content).expect("Could not read file");

// Copying Strings
let copied_string = s.clone();

// Copying from one file to another
let mut copy = File::create("copy.txt").expect("Could not create copy");
copy.write_all(content.as_bytes()).expect("Could not write to copy");

// Function
fn my_function() -> &'static str {
    "Hello, World!"
}

```

# 10.Haskell

REQ LIBRARIES
```haskell
import System.IO
```

CODE SNIPPETS:
```haskell
-- Printing and Input
putStrLn "Enter a string:"
s <- getLine

-- File Operations
writeFile "file.txt" s
content <- readFile "file.txt"

-- Copying Strings
let copied_string = s

-- Copying from one file to another
writeFile "copy.txt" content

-- Function
myFunction :: String
myFunction = "Hello, World!"

```
------------------------------------------------------------------------------------------------------------------------------------------------

#  Running Files

| **Language** | **File Extension** | **Command to Run**                      | **Example Command**                         |
|--------------|---------------------|----------------------------------------|---------------------------------------------|
| Python       | `.py`               | `python filename.py`                   | `python my_script.py`                      |
| Ruby          | `.rb`               | `ruby filename.rb`                     | `ruby my_script.rb`                        |
| Elixir        | `.exs`              | `elixir filename.exs`                  | `elixir my_script.exs`                     |
| JavaScript    | `.js`               | `node filename.js`                     | `node my_script.js`                        |
| Java          | `.java`             | `javac filename.java && java ClassName`| `javac MyClass.java && java MyClass`       |
| Go            | `.go`               | `go run filename.go`                   | `go run my_program.go`                     |
| C             | `.c`                | `gcc filename.c -o outputfile && ./outputfile` | `gcc my_program.c -o my_program && ./my_program` |
| C++           | `.cpp`              | `g++ filename.cpp -o outputfile && ./outputfile` | `g++ my_program.cpp -o my_program && ./my_program` |
| Rust          | `.rs`               | `cargo run` or `rustc filename.rs && ./filename` | `cargo run` or `rustc my_program.rs && ./my_program` |
| Haskell       | `.hs`               | `ghc filename.hs -o outputfile && ./outputfile` | `ghc my_program.hs -o my_program && ./my_program` |

