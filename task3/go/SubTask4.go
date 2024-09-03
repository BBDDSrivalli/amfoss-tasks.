package main

import (
    "fmt"
    "os"
)

func printPatternToFile(n int, outputFile *os.File) {
    for i := 1; i <= (n+1)/2; i++ {
        for j := 0; j < (n+1)/2-i; j++ {
            fmt.Fprint(outputFile, " ")
            fmt.Print(" ")
        }
        for j := 0; j < (i*2)-1; j++ {
            fmt.Fprint(outputFile, "*")
            fmt.Print("*")
        }
        fmt.Fprintln(outputFile)
        fmt.Println()
    }

    for i := (n+1)/2 + 1; i <= n; i++ {
        for j := 0; j < i-(n+1)/2; j++ {
            fmt.Fprint(outputFile, " ")
            fmt.Print(" ")
        }
        for j := 0; j < (n+1-i)*2-1; j++ {
            fmt.Fprint(outputFile, "*")
            fmt.Print("*")
        }
        fmt.Fprintln(outputFile)
        fmt.Println()
    }
}

func main() {
    var n int
    fmt.Print("Enter the number of rows: ")
    fmt.Scan(&n)

    outputFile, err := os.Create("output.txt")
    if err != nil {
        fmt.Println("Error opening output.txt")
        return
    }
    defer outputFile.Close()

    printPatternToFile(n, outputFile)
    fmt.Println("Diamond pattern has been written to output.txt")
}

