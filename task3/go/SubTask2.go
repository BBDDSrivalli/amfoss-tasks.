package main

import (
    "fmt"
    "io/ioutil"
)

func createInputFile() {
    content := "This is a test string for Sub-Task 2."
    err := ioutil.WriteFile("input.txt", []byte(content), 0644)
    if err != nil {
        fmt.Println("Error creating input.txt:", err)
        return
    }
}

func readAndWrite() {
    // Read content from input.txt
    content, err := ioutil.ReadFile("input.txt")
    if err != nil {
        fmt.Println("Error reading input.txt:", err)
        return
    }
    
    fmt.Println("Content read from input.txt:")
    fmt.Println(string(content))
    
    // Write content to output.txt
    err = ioutil.WriteFile("output.txt", content, 0644)
    if err != nil {
        fmt.Println("Error writing to output.txt:", err)
        return
    }
    
    fmt.Println("Content successfully copied from input.txt to output.txt")
    
    // Append content to output.txt
    appendedContent := "\nAppending new content to output.txt."
    err = ioutil.WriteFile("output.txt", append(content, []byte(appendedContent)...), 0644)
    if err != nil {
        fmt.Println("Error appending to output.txt:", err)
        return
    }

    // Read and print the updated content of output.txt
    updatedContent, err := ioutil.ReadFile("output.txt")
    if err != nil {
        fmt.Println("Error reading output.txt:", err)
        return
    }

    fmt.Println("Updated content of output.txt:")
    fmt.Println(string(updatedContent))
}

func main() {
    createInputFile()
    readAndWrite()
}
