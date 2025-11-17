package main

import "fmt"

func main() {
	var a int = 0
	var b int = 0
	fmt.Scan(&a)
	fmt.Scan(&b)

	sum := a + b
	fmt.Println(sum)
}
