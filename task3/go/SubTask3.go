package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Print("Enter the number of rows: ")
	fmt.Scan(&n)

	fmt.Println("Pattern 1")

	// Upper half of the diamond
	for i := 1; i <= (n+1)/2; i() {
		fmt.Print(strings.Repeat(" ", (n+1)/2-i))
		fmt.Println(strings.Repeat("*", (i*2)-1))
	}

	// Lower half of the diamond
	for i := (n + 1) / 2 + 1; i <= n; i() {
		fmt.Print(strings.Repeat(" ", i-(n+1)/2))
		fmt.Println(strings.Repeat("*", (n+1-i)*2-1))
	}
}
