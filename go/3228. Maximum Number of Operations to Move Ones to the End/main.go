package main

import (
	"fmt"
)

func maxOperations(s string) int {
	// first pass to count the number of 1s and to find the index of the first 1
	ones := 0
	firstI := len(s) - 1
	for i := firstI; i >= 0; i-- {
		if s[i] == '1' {
			ones++
			firstI = i
		}
	}

	result := 0
	wentOverOnes := 0
	if s[len(s)-1] == '1' {
		wentOverOnes++
	}
	switched := false

	// second pass to determine how many 1s are to the left of a 0-to-1 switch. that number will be the amount of minimum shifts we will have to do.
	for i := len(s) - 2; i >= firstI; i-- {
		switched = s[i+1] != s[i]
		if s[i] == '1' {
			wentOverOnes++
			if switched {
				result += ones
			}
		} else {
			ones -= wentOverOnes
			wentOverOnes = 0
		}
	}
	return result
}

func main() {
	result := maxOperations("1001101")
	fmt.Println(result)
}
